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

// External function declarations
extern struct fixed_buff* fixed_buff_alloc(void);
extern uint8_t* stream_get(struct stream *s, unsigned int *data_len);
extern struct fixed_buff* build_fixed_buff_list(struct stream *s);
extern void free_fixed_buff_list(struct fixed_buff *head);

void print_node_data(FILE *output, struct fixed_buff *node, int node_num) {
    fprintf(output, "Node %d: data_len=%u, data=[", node_num, node->data_len);
    for (unsigned int i = 0; i < node->data_len; i++) {
        if (node->data[i] >= 32 && node->data[i] <= 126) {
            fprintf(output, "%c", node->data[i]);
        } else {
            fprintf(output, "\\x%02x", node->data[i]);
        }
    }
    fprintf(output, "]\n");
}

int main() {
    FILE *output = fopen("output_log.txt", "w");
    if (!output) {
        perror("Failed to open output file");
        return 1;
    }
    
    fprintf(output, "====== Fixed Buffer List Test ======\n");
    fprintf(output, "FIXED_BUFF_LEN = %d\n\n", FIXED_BUFF_LEN);
    
    printf("Fixed Buffer List Test\n");
    printf("Enter data for each stream_get() call.\n");
    printf("Press Enter on empty line to finish.\n");
    printf("Example: First line '50 characters...', Second line '20 characters...', Empty line to stop\n\n");
    
    struct stream s = {0};
    
    struct fixed_buff *list = build_fixed_buff_list(&s);
    
    if (!list) {
        fprintf(output, "Result: No data was processed or allocation failed\n");
        printf("No data was processed.\n");
        fclose(output);
        return 1;
    }
    
    fprintf(output, "Successfully created fixed buffer list\n");
    fprintf(output, "List structure:\n");
    
    printf("\nGenerated linked list:\n");
    
    int node_count = 0;
    int total_bytes = 0;
    
    for (struct fixed_buff *node = list; node; node = node->next) {
        node_count++;
        total_bytes += node->data_len;
        
        
        // Print to both console and file
        print_node_data(output, node, node_count);
        printf("Node %d: %u bytes -> ", node_count, node->data_len);
        for (unsigned int i = 0; i < node->data_len; i++) {
            printf("%c", node->data[i]);
        }
        printf("\n");
        printf("  Total array size: %zu bytes\n", sizeof(node->data));
printf("  Elements in array: %zu\n", sizeof(node->data) / sizeof(node->data[0]));
    }
    
    fprintf(output, "\nSummary:\n");
    fprintf(output, "Total nodes: %d\n", node_count);
    fprintf(output, "Total bytes: %d\n", total_bytes);
    
    fprintf(output, "stream_get() calls made: %d\n", s.call_count);
    
    // Verify correctness
    int all_full_except_last = 1;
    int current_node = 1;
    for (struct fixed_buff *node = list; node; node = node->next) {
        if (node->next != NULL && node->data_len != FIXED_BUFF_LEN) {
            all_full_except_last = 0;
            fprintf(output, "ERROR: Node %d has %u bytes but should have %d (not last node)\n", 
                    current_node, node->data_len, FIXED_BUFF_LEN);
        }
        current_node++;
    }
    
    if (all_full_except_last) {
        fprintf(output, "SUCCESS: All nodes except last have exactly %d bytes\n", FIXED_BUFF_LEN);
        printf("✓ Test PASSED: All nodes properly sized\n");
    } else {
        fprintf(output, "FAILURE: Some non-last nodes don't have %d bytes\n", FIXED_BUFF_LEN);
        printf("✗ Test FAILED: Incorrect node sizing\n");
    }
    
    printf("\nTotal: %d nodes, %d bytes\n", node_count, total_bytes);
    printf("Results written to output_log.txt\n");
    
    free_fixed_buff_list(list);
    fclose(output);
    
    return all_full_except_last ? 0 : 1;
}