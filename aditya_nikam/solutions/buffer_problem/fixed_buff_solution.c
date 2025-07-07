#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream {
    uint8_t *data;
    size_t size;
    size_t position;
};

struct fixed_buff* fixed_buff_alloc(void);
uint8_t* stream_get(struct stream *s, unsigned int *data_len);

// implemented this for testing in local env.

// struct fixed_buff* fixed_buff_alloc(void) {
//     struct fixed_buff *buff = (struct fixed_buff*)malloc(sizeof(struct fixed_buff));
//     if (buff) {
//         buff->data_len = 0;
//         buff->next = NULL;
//         for (int i = 0; i < FIXED_BUFF_LEN; i++) {
//             buff->data[i] = 0;
//         }
//     }
//     return buff;
// }

// uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
//     int static test_case = 0;
//     if (!s || s->position >= s->size) {
//         test_case++;
//         *data_len = 0;
//         return NULL;
//     }
    
//     static int call_count = 0;
//     unsigned int chunk_size = 0;
//     size_t remaining = s->size - s->position;

//     if(test_case == 0){
//         if (call_count == 0) {
//             chunk_size = 30;
//         } else if (call_count == 1) {
//             chunk_size = 15;
//         }else if(call_count == 2){
//             chunk_size = 18;
//         }else if(call_count == 3){
//             chunk_size = remaining; 
//         }else {
//             *data_len = 0;
//             return NULL;
//         }
//     }else if (test_case == 1){
//         if (call_count == 4) {
//             chunk_size = 32;
//         } else if (call_count == 5) {
//             chunk_size = remaining; 
//         } else {
//             *data_len = 0;
//             call_count = 0;
//             return NULL;
//         }
//     }else if (test_case == 2){
//         if (call_count == 5) {
//             chunk_size = 10;
//         } else if (call_count == 1) {
//             chunk_size = remaining; 
//         } else {    
//             *data_len = 0;
//             call_count = 0;
//             return NULL;
//         }
//     }
//     call_count++;
//     *data_len = chunk_size;
//     uint8_t *result = s->data + s->position;
//     s->position += chunk_size;
//     return result;
// }

struct fixed_buff* build_fixed_buff_list(struct stream *s) {
    struct fixed_buff *head = NULL;
    struct fixed_buff *tail = NULL;
    struct fixed_buff *current_buffer = NULL;
    
    uint8_t *curr_data;
    unsigned int curr_data_len;
    
    while ((curr_data = stream_get(s, &curr_data_len)) != NULL) {
        printf("Stream returned %u bytes\n", curr_data_len);
        
        for (unsigned int i = 0; i < curr_data_len; i++) {
            if (current_buffer == NULL || current_buffer->data_len == FIXED_BUFF_LEN) {
                struct fixed_buff *new_buff = fixed_buff_alloc();
                if (!new_buff) {
                    printf("Error: Cannot allocate buffer\n");
                    return head;
                }
                
                if (head == NULL) {
                    head = new_buff;
                    tail = new_buff;
                } else {
                    tail->next = new_buff;
                    tail = new_buff;
                }
                
                current_buffer = new_buff;
                printf("Created new buffer\n");
            }
            
            current_buffer->data[current_buffer->data_len] = curr_data[i];
            current_buffer->data_len++;
        }
    }
    
    if (current_buffer != NULL) {
        printf("Final buffer has %u bytes\n", current_buffer->data_len);
    }
    
    return head;
}

void print_buffer_list(struct fixed_buff *head) {
    struct fixed_buff *current = head;
    int count = 1;
    
    printf("\n=== BUFFER LIST ===\n");
    while (current != NULL) {
        printf("Buffer %d: %u bytes\n", count++, current->data_len);
        printf(" bytes: ");
        for (unsigned int i = 0; i < current->data_len; i++) {
            printf("%02X ", current->data[i]);
        }
        printf("\n");
        current = current->next;
    }
    printf("==================\n");
}

void free_buffer_list(struct fixed_buff *head) {
    struct fixed_buff *current = head;
    while (current != NULL) {
        struct fixed_buff *next = current->next;
        free(current);
        current = next;
    }
}

void log_message(const char *message) {
    FILE *log_file = fopen("output.log", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    }
    printf("%s\n", message);
}