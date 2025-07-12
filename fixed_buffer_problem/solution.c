
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define FIXED_BUFF_LEN 32

struct fixed_buff
{

    uint8_t data[FIXED_BUFF_LEN];

    unsigned int data_len;

    struct fixed_buff *next;
};

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

struct fixed_buff *fixed_buff_alloc(void)
{

    struct fixed_buff *new_buffer = (struct fixed_buff *)malloc(sizeof(struct fixed_buff));

    // memory allocation failed
    if (new_buffer == NULL)
    {
        return NULL;
    }

    new_buffer->data_len = 0;
    new_buffer->next = NULL;

    return new_buffer;
}

struct fixed_buff *build_fixed_buff_list(struct stream *s)

{
    // Singly LINK LIST implementation

    uint8_t *curr_data;
    unsigned int newdata_len;
    unsigned int curr_data_len;
    struct fixed_buff *newNode;

    // Initializations

    struct fixed_buff *head = NULL;    // first node
    struct fixed_buff *current = NULL; // add from end in LL
    curr_data = NULL;
    curr_data_len = 0;

    while ((curr_data = stream_get(s, &curr_data_len)))
    {

        unsigned int dataset_offset = 0; // current data chunk position

        while (dataset_offset < curr_data_len)
        {
            newNode = fixed_buff_alloc();

            // chunk data apart from 32 bit ,remaining bits
            unsigned int remain_data = curr_data_len - dataset_offset;
            unsigned int buffer_len = FIXED_BUFF_LEN;

            if (remain_data <= buffer_len)
            {
                newdata_len = remain_data;
            }
            else
            {
                newdata_len = buffer_len;
            }

            // copy data in buffer

            for (int i = 0; i < newdata_len; i++)
            {
                newNode->data[i] = curr_data[dataset_offset + i];
            }

            newNode->data_len = newdata_len;
            newNode->next = NULL;

            // linking the nodes

            if (head == NULL)
            {
                head = newNode;
                current = newNode;
            }
            else
            {
                // add to end
                current->next = newNode;
                current = newNode;
            }

            dataset_offset = dataset_offset + newdata_len; // move the pointer
        }
    }

    return head;
}

int main()
{
   uint8_t test_data[100];
   int i =0;
   for ( i = 0; i < 100; i++) {
        test_data[i] = i + 1;  // Fill with 1, 2, 3, ..., 70
    }

    struct stream test_stream;
    test_stream.data =test_data;
    test_stream.tot_len = 100;
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
