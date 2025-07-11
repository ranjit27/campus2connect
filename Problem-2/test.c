#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "buffer_builder.c"

struct stream { int dummy; };

FILE *log_file = NULL;
int stream_index = 0;

#define MAX_CHUNKS 1000
char *mock_data[MAX_CHUNKS];
int total_chunks = 0;

struct fixed_buff* fixed_buff_alloc(void) {
    return (struct fixed_buff *)calloc(1, sizeof(struct fixed_buff));
}

uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    if (stream_index >= total_chunks || mock_data[stream_index] == NULL)
        return NULL;

    *data_len = strlen(mock_data[stream_index]);
    uint8_t *copy = malloc(*data_len);
    memcpy(copy, mock_data[stream_index], *data_len);
    stream_index++;
    return copy;
}

void load_input_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("ERROR: Cannot open input file: %s\n", filename);
        exit(1);
    }

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer[strcspn(buffer, "\n")] = 0;
        mock_data[total_chunks++] = strdup(buffer);
        if (total_chunks >= MAX_CHUNKS) break;
    }

    fclose(fp);
}

void print_list(struct fixed_buff *head) {
    if (head == NULL) {
        fprintf(log_file, "No data processed from input (empty stream)\n\n");
        printf("No data processed from input (empty stream)\n\n");
        return;
    }

    int count = 1;
    while (head) {
        fprintf(log_file, "Buffer %d: data_len = %u, data = \"", count, head->data_len);
        printf("Buffer %d: data_len = %u, data = \"", count, head->data_len);
        for (unsigned int i = 0; i < head->data_len; ++i) {
            fprintf(log_file, "%c", head->data[i]);
            printf("%c", head->data[i]);
        }
        fprintf(log_file, "\"\n");
        printf("\"\n");
        head = head->next;
        count++;
    }

    fprintf(log_file, "SUCCESS: Data copied to fixed_buff list\n\n");
    printf("SUCCESS: Data copied to fixed_buff list\n\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file.txt>\n", argv[0]);
        return 1;
    }

    log_file = fopen("output.log", "a");  // append mode
    if (!log_file) {
        printf("ERROR: Could not open output.log\n");
        return 1;
    }

    load_input_file(argv[1]);

    struct stream s;
    struct fixed_buff *list = build_fixed_buff_list(&s);

    fprintf(log_file, "\nFile: %s\n", argv[1]);
    printf("\nFile: %s\n", argv[1]);
    print_list(list);

    for (int i = 0; i < total_chunks; i++) {
        free(mock_data[i]);
    }

    fclose(log_file);
    return 0;
}
