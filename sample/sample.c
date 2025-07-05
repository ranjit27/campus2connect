#include <stdio.h>

#define LENGTH 10

int main()
{
#if defined(LENGTH)
    printf("LENGTH is defined as %d\n", LENGTH);
#else
    printf("LENGTH is not defined\n");
#endif

    return 0;
}