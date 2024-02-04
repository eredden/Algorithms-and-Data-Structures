#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node 
{
    int value;
    struct node *prev, *next;
} node_t;

int get_length(node_t *head);

node_t* get_node(node_t *head, int index);

void insert_at(node_t *head, node_t *node, int index);
void prepend(node_t *head, node_t *node);
void append(node_t *head, node_t *node);

void remove_node(node_t *node);
void remove_at(node_t *head, int index);

# endif
