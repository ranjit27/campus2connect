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

struct stream {
    int call_count;
};

struct fixed_buff* fixed_buff_alloc(void) {
    struct fixed_buff *new_node = malloc(sizeof(struct fixed_buff));
    if (new_node) {
        new_node->data_len = 0;
        new_node->next = NULL;
        memset(new_node->data, 0, FIXED_BUFF_LEN);
    }
    return new_node;
}

uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    static uint8_t input_buffer[1024];
    
    printf("Enter data for stream_get call %d (empty line to finish): ", s->call_count + 1);
    
    if (fgets((char*)input_buffer, sizeof(input_buffer), stdin) == NULL) {
        return NULL;
    }
    
    // Remove newline if present
    size_t len = strlen((char*)input_buffer);
    if (len > 0 && input_buffer[len-1] == '\n') {
        input_buffer[len-1] = '\0';
        len--;
    }
    
    // Empty line means end of stream
    if (len == 0) {
        return NULL;
    }
    
    *data_len = len;
    s->call_count++;
    
    return input_buffer;
}

struct fixed_buff* build_fixed_buff_list(struct stream *s) {
    uint8_t* curr_data;
    unsigned int curr_data_len;
    
    struct fixed_buff *head = NULL;
    struct fixed_buff *tail = NULL;
    
    // Buffer to hold leftover data between calls
    static uint8_t leftover_buffer[1024];
    unsigned int leftover_len = 0;
    
    while ((curr_data = stream_get(s, &curr_data_len)) != NULL) {
        
        // Combine leftover data with new data
        unsigned int total_len = leftover_len + curr_data_len;
        uint8_t *combined_data = malloc(total_len);
        
        if (!combined_data) {
            break;
        }
        
        // Copy leftover first, then new data
        memcpy(combined_data, leftover_buffer, leftover_len);
        memcpy(combined_data + leftover_len, curr_data, curr_data_len);
        
        unsigned int offset = 0;
        
        // Create nodes for complete 32-byte chunks
        while (offset + FIXED_BUFF_LEN <= total_len) {
            struct fixed_buff *new_node = fixed_buff_alloc();
            if (!new_node) {
                free(combined_data);
                return head;
            }
            
            memcpy(new_node->data, combined_data + offset, FIXED_BUFF_LEN);
            new_node->data_len = FIXED_BUFF_LEN;
            
            if (!head) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
            
            offset += FIXED_BUFF_LEN;
        }
        
        // Store remaining data for next iteration
        leftover_len = total_len - offset;
        if (leftover_len > 0) {
            memcpy(leftover_buffer, combined_data + offset, leftover_len);
        }
        
        free(combined_data);
    }
    
    // Handle any remaining data (last node with < 32 bytes)
    if (leftover_len > 0) {
        struct fixed_buff *new_node = fixed_buff_alloc();
        if (new_node) {
            memcpy(new_node->data, leftover_buffer, leftover_len);
            new_node->data_len = leftover_len;
            
            if (!head) {
                head = new_node;
            } else {
                tail->next = new_node;
            }
        }
    }
    
    return head;
}

void free_fixed_buff_list(struct fixed_buff *head) {
    while (head) {
        struct fixed_buff *next = head->next;
        free(head);
        head = next;
    }
}