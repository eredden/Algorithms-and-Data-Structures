#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

linked_list_t* linked_list_factory(void)
{
    linked_list_t* linked_list = (linked_list_t*) malloc(sizeof(linked_list_t));

    if (linked_list == NULL)
    {
        printf("Memory allocation for linked list failed.\n");
        exit(EXIT_FAILURE);
    }

    linked_list -> head = NULL;
    linked_list -> tail = NULL;
    linked_list -> length = 0;

    return linked_list;
}

void linked_list_destructor(linked_list_t* linked_list)
{
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    free(linked_list);
}

int get_length(linked_list_t *linked_list)
{
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    return linked_list -> length;
}

node_t* get_node(linked_list_t *linked_list, int index)
{
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index > get_length(linked_list) - 1)
    {
        printf("Index is out of bounds.\n");
        exit(EXIT_FAILURE);
    }

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
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (node == NULL)
    {
        printf("Node is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index > get_length(linked_list) - 1)
    {
        printf("Index is out of bounds.\n");
        exit(EXIT_FAILURE);
    }

    linked_list -> length++;

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
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (node == NULL)
    {
        printf("Node is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    linked_list -> length++;

    if (linked_list -> head == NULL)
    {
        linked_list -> head = node;
        linked_list -> tail = node;

        return;
    }

    node_t *head = linked_list -> head;

    node -> next = head;
    head -> prev = node;

    linked_list -> head = node;
}

void insert_back(linked_list_t *linked_list, node_t *node)
{
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (node == NULL)
    {
        printf("Node is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    linked_list -> length++;

    if (linked_list -> tail == NULL)
    {
        linked_list -> head = node;
        linked_list -> tail = node;

        return;
    }

    node_t *tail = linked_list -> tail;

    tail -> next = node;
    node -> prev = tail;

    linked_list -> tail = node;
}

node_t* remove_at(linked_list_t *linked_list, int index)
{
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (get_length(linked_list) == 0)
    {
        printf("Linked list is empty.\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index > get_length(linked_list) - 1)
    {
        printf("Index is out of bounds.\n");
        exit(EXIT_FAILURE);
    }

    linked_list -> length--;

    node_t *node = get_node(linked_list, index);

    node_t *prev_node = node -> prev;
    node_t *next_node = node -> next;

    if (prev_node != NULL) { prev_node -> next = next_node; }
    else { linked_list -> head = next_node; }

    if (next_node != NULL) { next_node -> prev = prev_node; }
    else { linked_list -> tail = prev_node; }

    node -> next = NULL;
    node -> prev = NULL;

    return node;
}

node_t* remove_front(linked_list_t *linked_list)
{
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (get_length(linked_list) == 0)
    {
        printf("Linked list is empty.\n");
        exit(EXIT_FAILURE);
    }

    linked_list -> length--;

    node_t *removed_head = linked_list -> head;
    node_t *new_head = linked_list -> head -> next;

    if (linked_list -> head == linked_list -> tail)
    {
        linked_list -> head = NULL;
        linked_list -> tail = NULL;

        return removed_head;
    }

    linked_list -> head = linked_list -> head -> next;

    removed_head -> next = NULL;
    new_head -> prev = NULL;

    return removed_head;
}

node_t* remove_back(linked_list_t *linked_list)
{
    if (linked_list == NULL)
    {
        printf("Linked list is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (get_length(linked_list) == 0)
    {
        printf("Linked list is empty.\n");
        exit(EXIT_FAILURE);
    }

    linked_list -> length--;

    node_t *removed_tail = linked_list -> tail;
    node_t *new_tail = linked_list -> tail -> prev;

    if (linked_list -> head == linked_list -> tail)
    {
        linked_list -> head = NULL;
        linked_list -> tail = NULL;

        return removed_tail;
    }

    linked_list -> tail = linked_list -> tail -> prev;

    removed_tail -> prev = NULL;
    new_tail -> next = NULL;

    return removed_tail;
}
