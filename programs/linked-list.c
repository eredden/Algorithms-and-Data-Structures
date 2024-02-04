#include <stdio.h>

typedef struct node 
{
    int value;
    struct node *prev, *next;
} node_t;

int get_length(node_t *head)
{
    node_t *current_node = head;
    int length;

    for (length = 0; current_node -> next != NULL; length++)
    {
        current_node = current_node -> next;
    }

    return length + 1;
}

node_t* get_node(node_t *head, int index)
{
    node_t *current_node = head;

    for (int i = 0; i < index; i++)
    {
        if (current_node -> next != NULL) 
        {
            current_node = current_node -> next;
        }

        else { break; }
    }

    return current_node;
}

void insert_at(node_t *head, node_t *node, int index)
{
    node_t *prev_node = get_node(head, index);
    node_t *next_node = prev_node -> next;

    node -> next = next_node;
    node -> prev = prev_node;

    if (prev_node != NULL) { prev_node -> next = node; }
    if (next_node != NULL) { next_node -> prev = node; }
}

void prepend(node_t *head, node_t *node)
{
    node -> next = head;
    head -> prev = node;
}

void append(node_t *head, node_t *node)
{
    int last_index = get_length(head) - 1;
    node_t *last_node = get_node(head, last_index);

    last_node -> next = node;
    node -> prev = last_node;
}

void remove_node(node_t *node)
{
    node_t *prev_node = node -> prev;
    node_t *next_node = node -> next;

    if (prev_node != NULL) { prev_node -> next = next_node; }
    if (next_node != NULL) { next_node -> prev = prev_node; }

    node -> next = NULL;
    node -> prev = NULL;
}

void remove_at(node_t *head, int index)
{
    node_t *node = get_node(head, index);
    remove_node(node);
}
