#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "fixed_buff_list.h"

#define FIXED_BUFF_LEN 32

uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    if (s->offset >= s->size) return NULL;

    unsigned int remain = s->size - s->offset;
    unsigned int chunk_size = remain >= 50 ? 50 : remain;

    *data_len = chunk_size;
    uint8_t *chunk = &s->buffer[s->offset];
    s->offset += chunk_size;

    return chunk;
}

struct fixed_buff* fixed_buff_alloc(void) {
    struct fixed_buff *node = (struct fixed_buff*) malloc(sizeof(struct fixed_buff));
    if (node) {
        node->data_len = 0;
        node->next = NULL;
    }
    return node;
}

void print_list(struct fixed_buff *head, FILE *logfile) {
    int index = 1;
    while (head) {
        fprintf(logfile, "Node %d:\n", index++);
        fprintf(logfile, "  Data length: %u\n", head->data_len);
        fprintf(logfile, "  Data: ");
        for (unsigned int i = 0; i < head->data_len; i++) {
            fprintf(logfile, "%u ", head->data[i]);
        }
        fprintf(logfile, "\n\n");
        head = head->next;
    }
}

void free_list(struct fixed_buff *head) {
    while (head) {
        struct fixed_buff *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    FILE *log = fopen("output.txt", "w");
    if (!log) {
        printf("Log file creation failed.\n");
        return 1;
    }

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        fprintf(stderr, "Failed to open input file.\n");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    unsigned int total_size = ftell(f);
    rewind(f);

    struct stream s = {0};
    s.size = total_size;
    s.offset = 0;
    s.buffer = malloc(total_size);
    if (!s.buffer) {
        fprintf(log, "Failed to allocate stream buffer.\n");
        fclose(f);
        fclose(log);
        return 1;
    }

    fread(s.buffer, 1, total_size, f);
    fclose(f);

    fprintf(log, "Stream Size: %u bytes\n", total_size);

    struct fixed_buff *result = build_fixed_buff_list(&s);

    if (!result) {
        fprintf(log, "build_fixed_buff_list returned NULL.\n");
        free(s.buffer);
        fclose(log);
        return 1;
    }

    fprintf(log, "Linked list created.!!\n\n");
    print_list(result, log);

    free_list(result);
    free(s.buffer);

    fprintf(log, "Test completed.\n");
    fclose(log);
    return 0;
}
