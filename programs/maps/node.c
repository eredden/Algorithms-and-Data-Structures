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

int main(void)
{
    node_t* node1 = node_factory(1);
    node_t* node2 = node_factory(2);

    node1 -> next = node2;
    node2 -> prev = node1;

    node_destructor(node1);
    node_destructor(node2);

    if (node1 == node2 -> prev || node1 == node2 -> prev)
    {
        printf("Destructor function failed to disconnect nodes.\n");
        exit(EXIT_FAILURE);
    }

    printf("No errors occurred with the node functions.\n");

    return 0;
}