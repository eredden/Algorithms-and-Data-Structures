#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue_t* queue_factory(void)
{
    queue_t* queue = (queue_t*) malloc(sizeof(queue_t));

    if (queue == NULL) {
        printf("Memory allocation for queue failed.\n");
        exit(EXIT_FAILURE);
    }

    queue -> head = NULL;
    queue -> tail = NULL;
    queue -> length = 0;

    return queue;
}

void queue_destructor(queue_t* queue)
{
    if (queue == NULL) {
        printf("Queue is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    free(queue);
}

int peek(queue_t *queue) { 
    if (queue == NULL) {
        printf("Queue is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (queue -> length <= 0) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE); 
    }

    return queue -> head -> value; 
}

void enqueue(queue_t *queue, node_t *node)
{
    if (queue == NULL) {
        printf("Queue is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (node == NULL)
    {
        printf("Node is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

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

node_t* deque(queue_t *queue)
{
    if (queue == NULL) {
        printf("Queue is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (queue -> length <= 0) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE); 
    }

    if (queue -> length == 1) 
    { 
        queue -> tail = NULL; 
    }

    queue -> length--;

    node_t *old_head = queue -> head;

    queue -> head = old_head -> next;
    old_head -> next = NULL;

    return old_head;
}
