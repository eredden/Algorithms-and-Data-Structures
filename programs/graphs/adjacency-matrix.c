#include <stdio.h>
#include <stdlib.h>
#include "../sort/queue.h"

int main(void)
{
    queue_t* queue = queue_factory();

    printf("HEAD: %p\n", queue -> head);
    printf("TAIL: %p\n", queue -> tail);
    printf("LNTH: %d\n", queue -> length);

    return 0;
}