#include <stdio.h>

typedef struct node 
{
    int value;
    struct node *prev, *next;
} node_t;

typedef struct linked_list
{
    node_t *head;
    node_t *tail;
} linked_list_t;

int get_length(linked_list_t *linked_list)
{
    node_t *current_node = linked_list -> head;
    int length;

    for (length = 0; current_node -> next != NULL; length++)
    {
        current_node = current_node -> next;
    }

    return length + 1;
}

node_t* get_node(linked_list_t *linked_list, int index)
{
    node_t *current_node = linked_list -> head;

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

void insert_at(linked_list_t *linked_list, node_t *node, int index)
{
    node_t *next_node = get_node(linked_list, index);
    node_t *prev_node = next_node -> prev;

    node -> next = next_node;
    node -> prev = prev_node;

    if (prev_node != NULL) { prev_node -> next = node; }
    else { linked_list -> head = node; }

    if (next_node != NULL) { next_node -> prev = node; }
    else { linked_list -> tail = node; }
}

void insert_front(linked_list_t *linked_list, node_t *node)
{
    node_t *head = linked_list -> head;

    node -> next = head;
    head -> prev = node;

    linked_list -> head = node;
}

void insert_back(linked_list_t *linked_list, node_t *node)
{
    node_t *tail = linked_list -> tail;

    tail -> next = node;
    node -> prev = tail;

    linked_list -> tail = node;
}

void remove_at(linked_list_t *linked_list, int index)
{
    node_t *node = get_node(linked_list, index);

    node_t *prev_node = node -> prev;
    node_t *next_node = node -> next;

    if (prev_node != NULL) { prev_node -> next = next_node; }
    else { linked_list -> head = next_node; }

    if (next_node != NULL) { next_node -> prev = prev_node; }
    else { linked_list -> tail = prev_node; }

    node -> next = NULL;
    node -> prev = NULL;
}

void remove_front(linked_list_t *linked_list)
{
    node_t *removed_head = linked_list -> head;
    node_t *new_head = linked_list -> head -> next;

    linked_list -> head = linked_list -> head -> next;

    removed_head -> next = NULL;
    new_head -> prev = NULL;
}

void remove_back(linked_list_t *linked_list)
{
    node_t *removed_tail = linked_list -> tail;
    node_t *new_tail = linked_list -> tail -> prev;

    linked_list -> tail = linked_list -> tail -> prev;

    removed_tail -> prev = NULL;
    new_tail -> next = NULL;

}
