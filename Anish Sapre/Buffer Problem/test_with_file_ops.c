//
// Created by Anish Sapre on 06/07/25.
//
// There is an incoming data stream of unknown length.
// The data are read using the stream_get() function.
// You must copy the data into a linked list of fixed_buff structures.
// Each fixed_buff can store up to 32 (FIXED_BUFF_LEN) bytes of data.
// You should not change FIXED_BUFF_LEN  to another value.
//
// As an example, you might have the following:
// Call 1: stream_get() returns curr_data_len == 50 bytes.
// Call 2: stream_get() returns curr_data_len == 20 bytes.
// Call 3: stream_get() returns NULL, so finished reading.
//
// You should return a linked list of 3 fixed_buffs:
// buff1->buff2->buff3
// buff1 should have the first 32 bytes (data_len == 32)
// buff2 should have the second 32 bytes (data_len == 32)
// buff3 should have the last 6 bytes (data_len == 6)
//
// Please complete the function build_fixed_buff_list to accomplish this.
// You should call stream_get and fixed_buff_alloc, but you do not need to implement them.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff
{
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream {
    const uint8_t *data;
    unsigned int size;
    unsigned int offset;
};

struct fixed_buff* fixed_buff_alloc(void) {
    return (struct fixed_buff*) malloc(sizeof(struct fixed_buff));
}

//the logic to split data into 32byte chunks is in build_fixed_buff_list,
//this function will always be called twice, first call returns the length
//of the stream and the second call always returns null to indicate end
uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    FILE* fptr = fopen("output.txt", "a");
    if (s->offset >= s->size) { //end of stream returns null as mentioned
        fputs("\nSecond call, returns NULL to indicate end", fptr);
        return NULL;
    }

    fputs("\nFirst call to stream_get, returns length of stream", fptr);
    unsigned int remaining = s->size - s->offset;
    *data_len = remaining;
    s->offset = s->size;
    return (uint8_t*)s->data;;
}

struct fixed_buff* build_fixed_buff_list(struct stream *s)
{
    FILE* fptr = fopen("output.txt", "a");
    uint8_t* curr_data;
    struct fixed_buff *read = NULL, *write = NULL;
    unsigned int curr_data_len;
    while ((curr_data = stream_get(s, &curr_data_len)))
    {
        fputs("\nSplitting logic and list builder called", fptr);
        int buffer_counter = 0;
        unsigned int copy_len = FIXED_BUFF_LEN;
        while (curr_data_len) {
            struct fixed_buff *node = fixed_buff_alloc();
            if (curr_data_len < FIXED_BUFF_LEN) {
                copy_len = curr_data_len;
            }
            for (unsigned int i = 0; i < copy_len; i++) {
                node->data[i] = curr_data[i + buffer_counter];
            }
            fputs("\nData added", fptr);
            node->data_len = copy_len;
            node->next = NULL;

            if (read == NULL) { //i used read/write instead of head/tail because i found the logic more intuitive
                read = node;
            }
            else {
                write->next = node;
            }
            fputs("\nRW head updated", fptr);
            write = node;
            buffer_counter += copy_len;
            curr_data_len -= copy_len;
            fputs("\nNode done", fptr);
        }
    }
    return read;
}

int main() {
    //char *input = "ABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBA"; //each segment AB...BA is 32 bytes so its easy to debug 32*3 bytes so 3 buffers
    //char *input = "ABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBACCCCCCCCC"; //32 + 9bytes
    //char *input = "ABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBACCCCCCCCC"; //32*3 + 9bytes so 4 buffers
    char *input = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBCCCCCC"; //email test case 50+20+6
    FILE* fptr = fopen("output.txt", "w");
    if (!fptr) {
        perror("Failed to open file");
        return -1;
    }
    if (!fptr) {
        printf("Could not open file\n");
    }
    fputs("\nInput: ", fptr);
    fputs(input, fptr);
    fputc('\n', fptr);

    struct stream s = {
        .data = (const uint8_t*)input,
        .size = strlen(input),
        .offset = 0
    };
    fputs("Output: ", fptr);
    struct fixed_buff *result = build_fixed_buff_list(&s);
    while (result) {
        for (unsigned int i = 0; i < result->data_len; ++i) {
            printf("%c", result->data[i]);
        }

        fwrite(result->data, 1, result->data_len, fptr);
        printf("\n");
        result = result->next;
    }
    fclose(fptr);


    return 0;
}