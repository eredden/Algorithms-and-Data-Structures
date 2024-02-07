#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int peek(stack_t *stack) { return stack -> head -> value; }

void push(stack_t *stack, node_t *node)
{
    stack -> length++;

    if (stack -> head == NULL) 
    { 
        stack -> head = node;
        return;
    }

    node -> next = stack -> head;
    stack -> head = node;
}

int pop(stack_t *stack)
{
    if (stack -> length <= 0) { exit(-1); }

    stack -> length--;

    node_t *old_head = stack -> head;

    stack -> head = old_head -> next;
    old_head -> next = NULL;

    return old_head -> value;
}
