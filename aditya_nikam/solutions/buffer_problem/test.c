#include "fixed_buff_solution.c"

int main() {
    FILE *log_file = fopen("output.log", "w");
    if (log_file) {
        fprintf(log_file, "FIXED BUFFER TEST LOG\n");  
        fclose(log_file);
    }
    log_message("Test case 1");
    
    uint8_t test_data[70];
    for (int i = 0; i < 70; i++) {
        test_data[i] = (uint8_t)(i + 1);
    }
    
    struct stream s;
    s.data = test_data;
    s.size = 70;
    s.position = 0;
    
    struct fixed_buff *head = build_fixed_buff_list(&s);
    
    print_buffer_list(head);
    
    int buffer_count = 0;
    int total_bytes = 0;
    struct fixed_buff *current = head;
    
    while (current != NULL) {
        buffer_count++;
        total_bytes += current->data_len;
        current = current->next;
    }
    
    char result_msg[256];
    sprintf(result_msg, "Result: %d buffers, %d total bytes", buffer_count, total_bytes);
    log_message(result_msg);
    
    if (buffer_count == 3 && total_bytes == 70) {
        log_message("Test case 1 passed");
    } else {
        log_message("Test case 1 failed");
    }
    free_buffer_list(head);

    log_message("-----------------------------------");
    
    log_message("Test case 2");
    
    uint8_t test_data2[32];
    for (int i = 0; i < 32; i++) {
        test_data2[i] = (uint8_t)(i + 100);
    }
    
    struct stream s2;
    s2.data = test_data2;
    s2.size = 32;
    s2.position = 0;
    
    struct fixed_buff *head2 = build_fixed_buff_list(&s2);
    print_buffer_list(head2);
    
    buffer_count = 0;
    total_bytes = 0;
    current = head2;
    
    while (current != NULL) {
        buffer_count++;
        total_bytes += current->data_len;
        current = current->next;
    }
    
    sprintf(result_msg, "Result: %d buffers, %d total bytes", buffer_count, total_bytes);
    log_message(result_msg);
    
    if (buffer_count == 1 && total_bytes == 32) {
        log_message("Test case 2 passed");
    } else {
        log_message("Test case 2 failed"); 
    }
    
    free_buffer_list(head2);
    log_message("-----------------------------------");
    
    log_message("Test case 3");
    
    uint8_t test_data3[10];
    for (int i = 0; i < 10; i++) {
        test_data3[i] = (uint8_t)(i + 200);
    }
    
    struct stream s3;
    s3.data = test_data3;
    s3.size = 10;
    s3.position = 0;
    
    struct fixed_buff *head3 = build_fixed_buff_list(&s3);
    print_buffer_list(head3);
    
    buffer_count = 0;
    total_bytes = 0;
    current = head3;
    
    while (current != NULL) {
        buffer_count++;
        total_bytes += current->data_len;
        current = current->next;
    }
    
    sprintf(result_msg, "Result: %d buffers, %d total bytes", buffer_count, total_bytes);
    log_message(result_msg);
    
    if (buffer_count == 1 && total_bytes == 10) {
        log_message("Test case 3 passed");
    } else {
        log_message("Test case 3 failed");
    }
    
    free_buffer_list(head3);
    log_message("-----------------------------------");
    
    log_message("Test case 4");
    
    struct stream s4;
    s4.data = NULL;
    s4.size = 0;
    s4.position = 0;
    
    struct fixed_buff *head4 = build_fixed_buff_list(&s4);
    
    if (head4 == NULL) {
        log_message("Test case 4 passed");
    } else {
        log_message("Test case 4 failed");
    }
    free_buffer_list(head4);

    printf("Test completed successfully!\n");
    printf("Check output.log for detailed results.\n");
    
    return 0;
}