#include <stdio.h>
 #include <stdlib.h>
  #include <stdint.h>
   #include <string.h>

#define FIXED_BUFF_LEN 32

// buffer node
struct fixed_buff 
{
    uint8_t data[FIXED_BUFF_LEN];
    int data_len;
    struct fixed_buff *next;
};

//stream struct
struct stream
 {
    int call_counter;
};

// Simulated ip data
const char *line1 = "Appleyyynacherryyyiesmangopinessyruesry";
const char *line2 = "rmonyagslachlycheeeeck";

//  reading from stream
uint8_t* stream_get(struct stream *s, int *len)
 {
    if (s->call_counter == 0) 
    {
        s->call_counter++;
        *len = strlen(line1);
        uint8_t *copy = malloc(*len);
        if (copy) 
        {
            for (int i = 0; i < *len; i++) copy[i] = line1[i];
        }
        return copy;
    } else if (s->call_counter == 1) 
    {
        s->call_counter++;
                  *len = strlen(line2);
        uint8_t *copy = malloc(*len);
        if (copy)
         {
                  for (int i = 0; i < *len; i++) copy[i] = line2[i];
        }
        return copy;
    }
            return NULL;
}

// new buffer node
struct fixed_buff* fixed_buff_alloc() {
    
                  struct fixed_buff *node = malloc(sizeof(struct fixed_buff));
                if (!node) return NULL;
    node->data_len = 0;
            node->next = NULL;
    return node;
}

// Main solution  function to build 
struct fixed_buff* fixed_buff_list(struct stream *s) {
    struct fixed_buff *head = NULL;
                  struct fixed_buff *tail = NULL;

    uint8_t *data;
    int len;

    while ((data = stream_get(s, &len)) != NULL)
     {
                int offset = 0;
  
             while (offset < len)
         {
                struct fixed_buff *node = fixed_buff_alloc();
            if (!node) break;

                      int chunk = (len - offset >= FIXED_BUFF_LEN) ? FIXED_BUFF_LEN : (len - offset);

            for (int i = 0; i < chunk; i++)
             {
                     node->data[i] = data[offset + i];
            }

            node->data_len = chunk;
            node->next = NULL;

            if (!head)
              {
                      head = tail = node;
            } else 
            {
                tail->next = node;
                    tail = node;
            }

            offset += chunk;
        }

        free(data);
    }

    return head;
}







int main() 

{
    FILE *out = fopen("output.txt", "w");
           if (!out) {
                printf("Error opening output.txt\n");
                        return 1;
    }

    struct stream s;
               s.call_counter = 0;

    struct fixed_buff *list = fixed_buff_list(&s);

    int buf_no = 1;
    while (list != NULL) {
                    fprintf(out, "Buffer %d (%d bytes): ", buf_no, list->data_len);
        for (int i = 0; i < list->data_len; i++) {
                        fprintf(out, "%c", list->data[i]);
        }
        fprintf(out, "\n");

        struct fixed_buff *next = list->next;
               free(list);
                  list = next;
                     buf_no++;
    }

    fprintf(out, "\nWriting Finished.\n");
                          fclose(out);
    return 0;
}
