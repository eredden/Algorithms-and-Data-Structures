#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node 
{
    int value;
    struct node *prev, *next;
} node_t;

typedef struct queue
{
    node_t *head;
    node_t *tail;
    int length;
} queue_t;

node_t* peek(queue_t *queue, int index);

void enqueue(queue_t *queue, node_t *node);

int deque(queue_t *queue);

# endif // LINKED_LIST
