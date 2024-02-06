#include <stdio.h>
#include "queue.h"

node_t* peek(queue_t *queue, int index)
{
    node_t *current_node = queue -> head;

    for (int i = 0; i < index; i++)
    {
        if (current_node -> next != NULL) 
        {
            current_node = current_node -> next;
        }

        else { return NULL; }
    }

    return current_node;
}

void enqueue(queue_t *queue, node_t *node)
{
    if (queue -> length > 0)
    {
        queue -> tail -> next = node;
        node -> prev = queue -> tail;

        queue -> tail = node;
    }

    else
    {
        queue -> head = node;
        queue -> tail = node;
    }

    queue -> length++;
}

int deque(queue_t *queue)
{
    if (queue -> length > 1)
    {
        node_t *old_head = queue -> head;
        node_t *new_head = queue -> head -> next;

        queue -> head = new_head;

        old_head -> next = NULL;
        new_head -> prev = NULL;

        queue -> length--;

        return old_head -> value;
    }

    else if (queue -> length == 1)
    {

        node_t *old_head = queue -> head;
        
        old_head -> prev = NULL;
        old_head -> next = NULL;

        queue -> head = NULL;
        queue -> tail = NULL;

        queue -> length--;

        return old_head -> value;
    }

    else 
    {
        // TO-DO: figure out how to produce error here
    }
}
