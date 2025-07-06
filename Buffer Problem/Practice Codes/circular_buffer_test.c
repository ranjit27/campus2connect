#include <stdio.h>
#include <stdint.h>
#define BUFFER_SIZE 32

typedef struct {
    uint8_t buffer[BUFFER_SIZE];
    uint8_t write_index;
    uint8_t read_index;
} circular_buffer;

void init_circular_buffer(circular_buffer *cb) {
    cb->write_index = 0;
    cb->read_index = 0;
}

int cb_insert(circular_buffer *cb, uint8_t data) {
    if (cb->write_index < BUFFER_SIZE) {
        cb->buffer[cb->write_index++] = data;
        return 1;
    } else {
        printf("OVERFLOW");
        return 0;
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

int main() {
    circular_buffer test_buffer;
    init_circular_buffer(&test_buffer);

    cb_insert(&test_buffer, 'a');
    cb_insert(&test_buffer, 'b');
    cb_insert(&test_buffer, 'c');
    for (int i = 0; i < 40; ++i) {
        cb_insert(&test_buffer, 'A' + (i % 26));
    }
    cb_print(&test_buffer);

    return 0;
}
