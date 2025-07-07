// fixed_buff_list.c
#include <stdlib.h>
#include <stdint.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff 
{
    uint8_t data[FIXED_BUFF_LEN];
           int data_len;
         struct fixed_buff *next;
};

struct stream
 {
 
    int call_counter;
};


uint8_t* stream_get(struct stream *s, int *len);


struct fixed_buff* fixed_buff_alloc(void);

// Function to build the linked list 
struct fixed_buff* fixed_buff_list(struct stream *s) {
    struct fixed_buff *head = NULL;
             struct fixed_buff *tail = NULL;
    uint8_t *curr_data;
                         int curr_len;

    while ((curr_data = stream_get(s, &curr_len)) != NULL)
    {
                            int offset = 0;

        while (offset < curr_len) 
        {
            struct fixed_buff *node = fixed_buff_alloc();
          
            if (!node) break;

                       int chunk = (curr_len - offset >= FIXED_BUFF_LEN) ? FIXED_BUFF_LEN : (curr_len - offset);
 
            for (int i = 0; i < chunk; i++)
             {
             
                node->data[i] = curr_data[offset + i];
            }

            node->data_len = chunk;

                    node->next = NULL;

            if (!head) 
            {
                head = tail = node;
            } 
            else
             {
                tail->next = node;

                tail = node;
            }

                   offset += chunk;
        }

             free(curr_data);
    }

    return head;
}
