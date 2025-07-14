// test.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

const char *line1 = "Appleyyynacherryyyiesmangopinessyruesry";
const char *line2 = "rmonyagslachlycheeeeck";

// Simulated stream_get implementation
uint8_t* stream_get(struct stream *s, int *len)
 {
    if (s->call_counter == 0) 
    {
        s->call_counter++;
        *len = strlen(line1);
             uint8_t *copy = malloc(*len);
        if (copy)
         {
            for (int i = 0; i < *len; i++) copy[i] = line1[i];
        }
        return copy;
    } else if (s->call_counter == 1) 
    {
        s->call_counter++;
        *len = strlen(line2);
        uint8_t *copy = malloc(*len);
        if (copy)
         {
            for (int i = 0; i < *len; i++) copy[i] = line2[i];
        }
        return copy;
    }
    return NULL;
}

// Simulated fixed_buff_alloc implementation
struct fixed_buff* fixed_buff_alloc(void)

{
    struct fixed_buff *node = malloc(sizeof(struct fixed_buff));
    if (!node) return NULL;
    node->data_len = 0;
    node->next = NULL;
    return node;
}

// Declaration of the function to test
struct fixed_buff* fixed_buff_list(struct stream *s);

int main() 
{
    //writing to a output file
    FILE *out = fopen("output.txt", "w");
    if (!out)
    //if error in file opening
     {
        printf("Error: Could not open output.txt\n");
        return 1;
    }

    struct stream s;
    s.call_counter = 0;

             fprintf(out, "Running fixed_buff_list...\n");

    struct fixed_buff *list = fixed_buff_list(&s);
    int buf_no = 1;

    while (list != NULL) 
    //printing data stream byte 1byte=char  32 chars each buffer
    {
        fprintf(out, "Buffer %d (%d bytes): ", buf_no, list->data_len);
        for (int i = 0; i < list->data_len; i++) 
        {
            fprintf(out, "%c", list->data[i]);
        }
        fprintf(out, "\n");

        struct fixed_buff *next = list->next;
        free(list);
        list = next;
        buf_no++;
    }

          fprintf(out, "Test complete.\n");
    fclose(out);
    return 0;
}

