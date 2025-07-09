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
int main(int argc, char *argv[]) {
    FILE *input = stdin;
    FILE *log = fopen("output.log", "w");
    if (!log) {
        perror("Log file error");
        return 1;
    }

    if (argc == 2) {
        input = fopen(argv[1], "rb");
        if (!input) {
            fprintf(stderr, "Could not open file: %s\n", argv[1]);
            fclose(log);
            return 1;
        }
    } else {
        printf("Enter input stream (Ctrl+D to end input):\n");
    }

    int ch;
    while ((ch = fgetc(input)) != EOF && total_len < sizeof(user_data)) {
        user_data[total_len++] = (uint8_t)ch;
    }
    if (input != stdin) fclose(input);

    struct stream s;
    struct fixed_buff *node = build_fixed_buff_list(&s);

    for (int i = 1; node; i++) {
        fprintf(log, "Buffer %d - data_len: %u\n", i, node->data_len);
        for (unsigned int j = 0; j < node->data_len; j++) {
            fprintf(log, "%u ", node->data[j]);
        }
        fprintf(log, "\n");

        struct fixed_buff *temp = node;
        node = node->next;
        free(temp);
    }

    fprintf(log, "Finished reading stream.\n");
    fclose(log);
    printf("Check output.log for result.\n");
    return 0;
}
