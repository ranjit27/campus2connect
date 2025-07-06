#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define BUFFER_SIZE 32

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint8_t write_index;
    uint8_t read_index;
} circular_buffer;

typedef struct buffer_node {
    circular_buffer cb;
    struct buffer_node *next;
} buffer_node;

typedef struct {
    buffer_node *head;
    buffer_node *current;
} list_of_circular_buffers;

void init_circular_buffer(circular_buffer *cb) {
    cb->write_index = 0;
    cb->read_index = 0;
}

buffer_node* create_buffer_node() {
    buffer_node *node = (buffer_node*)malloc(sizeof(buffer_node));
    if (node) {
        init_circular_buffer(&node->cb);
        node->next = NULL;
    }
    return node;
}

void init_buffer_list(list_of_circular_buffers *list) {
    list->head = create_buffer_node();
    list->current = list->head;
}

int list_insert(list_of_circular_buffers *list, uint8_t data) {
    if (!list->current) {
        printf("NO BUFFER LIST PRESENT\n");
        return 0;  // No current buffer
    }
    if (list->current->cb.write_index < BUFFER_SIZE) {
        list->current->cb.buffer[list->current->cb.write_index++] = data;
        return 1;
    }
    else
    {
        printf("32 SIZE REACHED\n");
        buffer_node *new_node = create_buffer_node();
        list->current->next = new_node;
        list->current = new_node;
        list->current->cb.buffer[list->current->cb.write_index++] = data;
        return 1;
    }
}

void cb_print(circular_buffer *cb) {
    printf("\nDATA:\n");
    for (uint8_t i = 0; i < cb->write_index; ++i) {
        printf("[%d] = '%c' ", i, cb->buffer[i]);
    }
    printf("R: %u\n", cb->read_index);
    printf("W: %u\n", cb->write_index);
}

void print_list_of_buffers(list_of_circular_buffers *list) {
    printf("\nBUFFERS:\n");
    buffer_node *current = list->head;
    int buffer_num = 0;

    while (current) {
        printf("[%d] ", buffer_num++);
        cb_print(&current->cb);
        current = current->next;
    }
    printf("\n");
}

int count_buffers(list_of_circular_buffers *list) {
    int count = 0;
    buffer_node *current = list->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

int list_read(list_of_circular_buffers *list, uint8_t *data) {
    if (!list->head) {
        return 0;  // No buffers
    }

    buffer_node *current = list->head;
    while (current) {
        if (current->cb.read_index < current->cb.write_index) {
            *data = current->cb.buffer[current->cb.read_index++];
            return 1;
        }
        current = current->next;
    }
    return 0;  // No more data to read
}

int main() {
    list_of_circular_buffers buffer_list;
    init_buffer_list(&buffer_list);

    //inserting 100bytes
    for (int i = 0; i < 100; ++i) {
        char c = 'A' + (i % 26);
        if (!list_insert(&buffer_list, c)) {
            printf("Failed to insert character %c\n", c);
            break;
        }
    }

    printf("COunt: %d\n", count_buffers(&buffer_list));
    print_list_of_buffers(&buffer_list);

    return 0;
}