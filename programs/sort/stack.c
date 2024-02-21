#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_t* stack_factory(void)
{
    stack_t* stack = (stack_t*) malloc(sizeof(stack_t));

    if (stack == NULL)
    {
        printf("Memory allocation for stack failed.\n");
        exit(EXIT_FAILURE);
    }

    stack -> head = NULL;
    stack -> length = 0;
}

void stack_destructor(stack_t* stack)
{
    if (stack == NULL)
    {
        printf("Stack is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    free(stack);
}

int peek(stack_t *stack) 
{ 
    if (stack == NULL)
    {
        printf("Stack is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (stack -> length <= 0) 
    { 
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE); 
    }

    return stack -> head -> value; 
}

void push(stack_t *stack, node_t *node)
{
    if (stack == NULL)
    {
        printf("Stack is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (node == NULL)
    {
        printf("Node is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

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
    if (stack == NULL)
    {
        printf("Stack is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (stack -> length <= 0) 
    { 
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE); 
    }

    stack -> length--;

    node_t *old_head = stack -> head;

    stack -> head = old_head -> next;
    old_head -> next = NULL;

    return old_head -> value;
}
