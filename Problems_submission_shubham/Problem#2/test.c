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

struct stream { int call_count; };

extern struct fixed_buff* fixed_buff_alloc(void);
extern uint8_t* stream_get(struct stream *s, unsigned int *data_len);
extern struct fixed_buff* build_fixed_buff_list(struct stream *s);
// extern void free_fixed_buff_list(struct fixed_buff *head);

void print_node(FILE *f, struct fixed_buff *node, int idx) {
    fprintf(f, "Node %d: %u bytes: ", idx, node->data_len);
    for (unsigned int i = 0; i < node->data_len; i++) {
        if (node->data[i] >= 32 && node->data[i] <= 126) fputc(node->data[i], f);
        else fprintf(f, "\\x%02x", node->data[i]);
    }
    fprintf(f, "\n");
}

int main() {
    FILE *f = fopen("output_log.txt", "w");
    if (!f) return 1;

    struct stream s = {0};
    struct fixed_buff *list = build_fixed_buff_list(&s);
    if (!list) {
        fprintf(f, "No data processed.\n");
        fclose(f);
        return 1;
    }

    int count = 0, valid = 1;
    struct fixed_buff *cur = list;
    while (cur) {
        count++;
        print_node(f, cur, count);
        if (cur->next && cur->data_len != FIXED_BUFF_LEN)
            valid = 0;
        cur = cur->next;
    }

    fprintf(f, "\nTotal nodes: %d\n", count);
    fprintf(f, "Calls to stream_get: %d\n", s.call_count);
    if (valid) fprintf(f, "SUCCESS: All buffers correct\n");
    else fprintf(f, "ERROR: One or more buffers not 32 bytes\n");

    fclose(f);
    return valid ? 0 : 1;
}