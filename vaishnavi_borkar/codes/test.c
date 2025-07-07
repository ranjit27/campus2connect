#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define FIXED_BUFF_LEN 32

//  STRUCTURES 
struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream {
    int index;
};

uint8_t test_data1[30];
uint8_t test_data2[20];

// Fill with dummy data (optional)
void test_data_create() {
    for (int i = 0; i < 50; ++i) test_data1[i] = i + 1;
    for (int i = 0; i < 20; ++i) test_data2[i] = i + 31;
}

uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    if (s->index == 0) {
        *data_len = 30; 
        s->index++;
        return test_data1;
    } else if (s->index == 1) {
        *data_len = 20; 
        s->index++;
        return test_data2;
    } else {
        return NULL;
    }
}

struct fixed_buff* fixed_buff_alloc(void) {
    return (struct fixed_buff*)malloc(sizeof(struct fixed_buff));
}

// DECLARE YOUR FUNCTION 
struct fixed_buff* build_fixed_buff_list(struct stream *s);

int main() {
    test_data_create();

    struct stream s = {0};
    struct fixed_buff *head = build_fixed_buff_list(&s);

    FILE *f = fopen("output.txt", "w");
    if (!f) {
        printf("Error opening output.txt\n");
        return 1;
    }

    int node_num = 0;
    struct fixed_buff *curr = head;

    while (curr) {
        fprintf(f, "Node %d: data_len = %u, data = ", ++node_num, curr->data_len);
        for (unsigned int i = 0; i < curr->data_len; ++i) {
            fprintf(f, "%d ", curr->data[i]);
        }
        fprintf(f, "\n");
        curr = curr->next;
    }

    fprintf(f, "Total nodes: %d\n", node_num);
    fclose(f);

    return 0;
}
