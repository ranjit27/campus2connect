#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff
{
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};
struct stream;

struct fixed_buff *fixed_buff_alloc(void);
uint8_t *stream_get(struct stream *s, unsigned int *data_len);

struct fixed_buff *build_fixed_buff_list(struct stream *s)
{
    uint8_t *curr_data;
    unsigned int curr_data_len;
    struct fixed_buff *head = NULL;
    struct fixed_buff *tail = NULL;

    while (curr_data = stream_get(s, &curr_data_len))
    {
        unsigned int offset = 0;
        while (offset < curr_data_len)
        {
            struct fixed_buff *node = fixed_buff_alloc();
            if (!node)
                return head; // return list on error
            unsigned int bytes_copy = curr_data_len - offset;
            if (bytes_copy > FIXED_BUFF_LEN)
                bytes_copy = FIXED_BUFF_LEN; // more than 32 left only copy 32
            memcpy(node->data, curr_data + offset, bytes_copy);
            node->data_len = bytes_copy;
            node->next = NULL;
            if (!head)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            offset += bytes_copy;
        }
    }

    return head;
}