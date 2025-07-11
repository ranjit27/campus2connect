#include<stdio.h>
#include <stdint.h>
#include<string.h>
#include<stdlib.h>
#define FIXED_BUFF_LEN 32

struct fixed_buff{
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

 
struct fixed_buff* fixed_buff_alloc(void);

struct stream;

uint8_t* stream_get(struct stream *s, unsigned int *data_len);


struct fixed_buff* build_fixed_buff_list(struct stream *s) {

    struct fixed_buff *head = NULL;
    struct fixed_buff *tail = NULL;

    uint8_t* curr_data;
    unsigned int curr_data_len;

    while ((curr_data = stream_get(s, &curr_data_len))) {
        unsigned int i=0;

        while (i<curr_data_len) {
            struct fixed_buff *node = fixed_buff_alloc();
            if (!node) return head;

            unsigned int to_copy = (curr_data_len - i < FIXED_BUFF_LEN) ? (curr_data_len - i) : FIXED_BUFF_LEN;
            memcpy(node->data, curr_data + i, to_copy);
            node->data_len = to_copy;
            node->next = NULL;
            
            if(!head) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }

            i+=to_copy;
        }
        free(curr_data);
    }
    return head;
}