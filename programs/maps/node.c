#include <stdio.h>
#include <stdlib.h>
#include "lru.h"

node_t* node_factory(int value)
{
    node_t* node = (node_t*) malloc(sizeof(node_t));

    if (node == NULL)
    {
        printf("Memory allocation for node failed.\n");
        exit(EXIT_FAILURE);
    }

    node -> value = value;
    node -> next = NULL;
    node -> prev = NULL;

    return node;
}

void node_destructor(node_t* node)
{
    if (node == NULL)
    {
        printf("Node is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (node -> prev != NULL)
    {
        node_t* prev = node -> prev;
        prev -> next = NULL;
    }

    if (node -> next != NULL)
    {
        node_t* next = node -> next;
        next -> prev = NULL;
    }

    free(node);
}
