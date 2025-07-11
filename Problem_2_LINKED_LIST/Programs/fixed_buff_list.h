#ifndef FIXED_BUFF_LIST_H
#define FIXED_BUFF_LIST_H

#include <stdint.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream {
    int call_count;
    uint8_t *buffer;         
    unsigned int size;       
    unsigned int offset;
};

struct fixed_buff* build_fixed_buff_list(struct stream *s);

#endif
