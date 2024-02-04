#include <stdio.h>

typedef struct node {
    int value;
    struct node *prev, *next;
} node_t;

void insert_node(node_t *node, node_t *prev_node)
{
    node_t *next_node = prev_node -> next;

    node -> next = next_node;
    node -> prev = prev_node;

    prev_node -> next = node;
    next_node -> prev = node;
}

void delete_node(node_t *node)
{
    node_t *prev_node = node -> prev;
    node_t *next_node = node -> next;

    prev_node -> next = next_node;
    next_node -> prev = prev_node;

    node -> next = NULL;
    node -> prev = NULL;
}

int main(void)
{
    node_t head, body, spare_body, tail;

    head.value = 0;
    head.prev = NULL;
    head.next = &body;

    body.value = 1;
    body.prev = &head;
    body.next = &tail;

    spare_body.value = 1;
    spare_body.prev = NULL;
    spare_body.next = NULL;

    tail.value = 2;
    tail.prev = &body;
    tail.next = NULL;

    delete_node(&body);
    insert_node(&spare_body, &head);

    return 0;
}
