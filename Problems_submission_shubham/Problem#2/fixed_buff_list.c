#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff
{
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream
{
    int call_count;
    FILE *fp;
};

struct fixed_buff *fixed_buff_alloc(void)
{
    struct fixed_buff *n = malloc(sizeof(struct fixed_buff));
    if (n)
    {
        n->data_len = 0;
        n->next = NULL;
        memset(n->data, 0, FIXED_BUFF_LEN);
    }
    return n;
}

uint8_t *stream_get(struct stream *s, unsigned int *len)
{
    static uint8_t buf[1024];
    // printf("Input %d: ", s->call_count + 1);
    // if (!fgets((char*)buf, sizeof(buf), stdin)) return NULL;
    if (!fgets((char *)buf, sizeof(buf), s->fp))
        return NULL;
    size_t l = strlen((char *)buf);
    if (l > 0 && buf[l - 1] == '\n')
    {
        buf[l - 1] = '\0';
        l--;
    }
    if (l == 0)
        return NULL;
    *len = l;
    s->call_count++;
    return buf;
}

struct fixed_buff *build_fixed_buff_list(struct stream *s)
{
    uint8_t *data;
    unsigned int len;
    struct fixed_buff *head = NULL, *tail = NULL;
    static uint8_t leftover[1024];
    unsigned int leftover_len = 0;

    while ((data = stream_get(s, &len)))
    {
        unsigned int total = leftover_len + len;
        uint8_t *combined = malloc(total);
        if (!combined)
            break;
        // memcpy(combined, leftover, leftover_len);
        // memcpy(combined + leftover_len, data, len);

        for (unsigned int i = 0; i < leftover_len; i++)
        {
            combined[i] = leftover[i];
        }
        for (unsigned int i = 0; i < len; i++)
        {
            combined[leftover_len + i] = data[i];
        }

        unsigned int i = 0;
        while (i + FIXED_BUFF_LEN <= total)
        {
            struct fixed_buff *node = fixed_buff_alloc();
            if (!node)
                break;
            // memcpy(node->data, combined + i, FIXED_BUFF_LEN);

            for (unsigned int j = 0; j < FIXED_BUFF_LEN; j++)
            {
                node->data[j] = combined[i + j];
            }

            node->data_len = FIXED_BUFF_LEN;
            if (!head)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            i += FIXED_BUFF_LEN;
        }

        leftover_len = total - i;
        // if (leftover_len > 0)
        // memcpy(leftover, combined + i, leftover_len);

        if (leftover_len > 0)
        {
            for (unsigned int j = 0; j < leftover_len; j++)
            {
                leftover[j] = combined[i + j];
            }
        }

        free(combined);
    }

    if (leftover_len > 0)
    {
        struct fixed_buff *node = fixed_buff_alloc();
        if (node)
        {
            // memcpy(node->data, leftover, leftover_len);
            for (unsigned int i = 0; i < leftover_len; i++)
            {
                node->data[i] = leftover[i];
            }

            node->data_len = leftover_len;
            if (!head)
                head = node;
            else
                tail->next = node;
        }
    }

    return head;
}