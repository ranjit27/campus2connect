#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream {};

uint8_t user_data[1000];      
unsigned int total_len = 0;
unsigned int offset = 0;
unsigned int chunk_size = 50;

uint8_t* stream_get(struct stream *s, unsigned int *data_len)
{
    if (offset >= total_len) {
        return NULL;  
    }
    if (total_len - offset < chunk_size)
        chunk_size = total_len - offset;

    *data_len = chunk_size;
    uint8_t *data_ptr = user_data + offset;
    offset += chunk_size;
    return data_ptr;

}

struct fixed_buff* fixed_buff_alloc(void)
{
    return (struct fixed_buff*)malloc(sizeof(struct fixed_buff));
}

struct fixed_buff* build_fixed_buff_list(struct stream *s);


int main() {
    FILE *log = fopen("output.log", "w");
    if (!log) {
        printf("Could not open log file\n");
        return 1;
    }

    printf("Enter input stream (Ctrl+D to end input):\n");

    int ch;
    while ((ch = getchar()) != EOF && total_len < sizeof(user_data)) {
        user_data[total_len++] = (uint8_t)ch;
    }

    struct stream s;
    struct fixed_buff *head = build_fixed_buff_list(&s);

    int count = 1;
    while (head) {
        fprintf(log, "Buffer %d - data_len: %u\n", count++, head->data_len);
        for (unsigned int i = 0; i < head->data_len; i++) {
            fprintf(log, "%u ", head->data[i]);
        }
        fprintf(log, "\n");

        struct fixed_buff *tmp = head;
        head = head->next;
        free(tmp);
    }

    fprintf(log, "Finished reading stream.\n");
    fclose(log);
    printf("Check output.log for result.\n");

    return 0;
}
