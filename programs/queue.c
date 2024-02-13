#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int peek(queue_t *queue) { return queue -> head -> value; }

void enqueue(queue_t *queue, node_t *node)
{
    queue -> length++;

    if (queue -> tail == NULL) 
    { 
        queue -> head = node;
        queue -> tail = node; 
        return;
    }

    queue -> tail -> next = node;
    queue -> tail = node;
}

int deque(queue_t *queue)
{
    if (queue -> length <= 0) { exit(-1); }

    if (queue -> length == 1) 
    { 
        queue -> tail = NULL; 
    }

    queue -> length--;

    node_t *old_head = queue -> head;

    queue -> head = old_head -> next;
    old_head -> next = NULL;

    return old_head -> value;
}
