#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "fixed_buff_list.h"

#define FIXED_BUFF_LEN 32

uint8_t* stream_get(struct stream *s, unsigned int *data_len);
struct fixed_buff* fixed_buff_alloc(void);

void* my_memcpy(void* dest, const void* src, unsigned int len) {
    uint8_t *d = (uint8_t*) dest;
    const uint8_t *s = (const uint8_t*) src;
    for (unsigned int i = 0; i < len; ++i) d[i] = s[i];
    return dest;
}


struct fixed_buff* build_fixed_buff_list(struct stream *s) {
    if (!s) {
        fprintf(stderr, "[ERROR] Null stream passed to build_fixed_buff_list\n");
        return NULL;
    }

    uint8_t *all_data = NULL;
    unsigned int total_len = 0;
    uint8_t *curr_data;
    unsigned int curr_len;

    // Accumulate entire stream
    while ((curr_data = stream_get(s, &curr_len)) != NULL) {
        uint8_t *new_buf = realloc(all_data, total_len + curr_len);
        if (!new_buf) {
            fprintf(stderr, "[ERROR] Memory reallocation failed.\n");
            free(all_data);
            return NULL;
        }
        all_data = new_buf;
        my_memcpy(all_data + total_len, curr_data, curr_len);
        total_len += curr_len;
    }

    // Chunk the entire buffer into 32-byte fixed_buff nodes
    struct fixed_buff *head = NULL, *tail = NULL;
    unsigned int offset = 0;

    while (offset < total_len) {
        unsigned int chunk_size = (total_len - offset >= FIXED_BUFF_LEN) ? FIXED_BUFF_LEN : (total_len - offset);
        struct fixed_buff *node = fixed_buff_alloc();
        if (!node) {
            fprintf(stderr, "[ERROR] Failed to allocate fixed_buff node.\n");
            break;
        }

        my_memcpy(node->data, all_data + offset, chunk_size);
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

