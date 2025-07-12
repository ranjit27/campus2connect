#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define FIXED_BUFF_LEN 32


struct stream
{

    unsigned int current_pos; //
    unsigned int tot_len;     // total length of stream
    uint8_t* data;
};

// returns:the data from the stream, NULL when stream is done
uint8_t *
stream_get(struct stream *s, unsigned int *data_len)
{

    unsigned int chunk_size;
    unsigned int remain_data;
    uint8_t *result_ptr;
    // when reached end of stream
    if (s->current_pos >= s->tot_len)
    {
        return NULL; // no more data
    }

    // how much is left data

    remain_data = s->tot_len - s->current_pos;

    if (remain_data >= FIXED_BUFF_LEN)
    {
        chunk_size = FIXED_BUFF_LEN;
    }
    else
    {
        chunk_size = remain_data;
    }

    *data_len = chunk_size;

    result_ptr = &s->data[s->current_pos]; // current  data

    // move the index i.e current_pos

    s->current_pos = s->current_pos + chunk_size;

    return result_ptr;
}

struct fixed_buff *fixed_buff_alloc(void);


int main()
{
   uint8_t test_data[70];
   int i =0;
   for ( i = 0; i < 70; i++) {
        test_data[i] = i + 1;  // Fill with 1, 2, 3, ..., 70
    }

    struct stream test_stream;
    test_stream.data =test_data;
    test_stream.tot_len = 70;
    test_stream.current_pos = 0;

    struct fixed_buff* result = build_fixed_buff_list(&test_stream);

 int count = 0;
    struct fixed_buff* current = result;  // result = new head
    
    while (current != NULL) {
        count++;
        printf("Buffer %d: %u bytes\n", count, current->data_len);
        current = current->next;
    }
    
    printf("Total: %d buffers\n", count);
}