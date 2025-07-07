#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream;
extern struct fixed_buff* fixed_buff_alloc(void);
uint8_t* stream_get(struct stream *s, unsigned int *data_len); 


struct fixed_buff* build_fixed_buff_list(struct stream *s) {
    uint8_t* curr_data;
    unsigned int curr_data_len;

    struct fixed_buff *head = NULL;
    struct fixed_buff *tail = NULL;

    uint8_t *leftover = NULL;
    unsigned int leftover_len = 0;

    while ((curr_data = stream_get(s, &curr_data_len))) {
        unsigned int total_len = leftover_len + curr_data_len;
        uint8_t *combined = malloc(total_len);
        if (leftover_len > 0) {
            memcpy(combined, leftover, leftover_len);
            free(leftover);
        }
        memcpy(combined + leftover_len, curr_data, curr_data_len);

        unsigned int index = 0;
        while (total_len - index >= FIXED_BUFF_LEN) {
            struct fixed_buff *node = fixed_buff_alloc();
            memcpy(node->data, combined + index, FIXED_BUFF_LEN);
            node->data_len = FIXED_BUFF_LEN;
            node->next = NULL;

            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            index += FIXED_BUFF_LEN;
        }

        leftover_len = total_len - index;
        leftover = malloc(leftover_len);
        memcpy(leftover, combined + index, leftover_len);
        free(combined);
    }

    if (leftover_len > 0) {
        struct fixed_buff *node = fixed_buff_alloc();
        memcpy(node->data, leftover, leftover_len);
        node->data_len = leftover_len;
        node->next = NULL;

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        free(leftover);
    }

    return head;
}
