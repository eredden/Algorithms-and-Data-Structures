#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    queue_t* queue = queue_factory();

    printf("%p", queue -> head);
    printf("%p", queue -> tail);
    printf("%d", queue -> length);

    return 0;
}