#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "fixed_buff_list.h"

#define FIXED_BUFF_LEN 32

struct fixed_buff* fixed_buff_alloc(void);
uint8_t* stream_get(struct stream *s, unsigned int *data_len);

struct fixed_buff* build_fixed_buff_list(struct stream *s) {
    if (!s) return NULL;

    uint8_t *all_data = NULL;
    unsigned int total_len = 0;

    uint8_t *curr_data;
    unsigned int curr_len;

    // Read all
    while ((curr_data = stream_get(s, &curr_len)) != NULL) {
        uint8_t *new_buf = (uint8_t *) realloc(all_data, total_len + curr_len);
        if (!new_buf) {
            free(all_data);
            return NULL;
        }

        all_data = new_buf;
        memcpy(all_data + total_len, curr_data, curr_len);
        total_len += curr_len;
    }

    // Break stream
    struct fixed_buff *head = NULL, *tail = NULL;
    unsigned int offset = 0;

    while (offset < total_len) {
        unsigned int chunk_size = (total_len - offset >= FIXED_BUFF_LEN) ? FIXED_BUFF_LEN : (total_len - offset);

        struct fixed_buff *node = fixed_buff_alloc();
        if (!node) {
            fprintf(stderr, "Failed memory allocation.\n");
            break;
        }

        memcpy(node->data, all_data + offset, chunk_size);
        node->data_len = chunk_size;
        node->next = NULL;

        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }

        offset += chunk_size;
    }

    free(all_data);
    return head;
}
