#ifndef BREADTH
#define BREADTH

/*
had to implement a special queue struct for this 
search because in theprimeagen's course they use
left and right in the nodes as well as returning 
the node when dequeuing rather than the value of 
the node, thus this was created to do that
*/

typedef struct node
{
    int value;
    struct node* next;
    struct node* left;
    struct node* right;
} node_t;

typedef struct queue
{
    node_t *head;
    node_t *tail;
    int length;
} queue_t;

int peek(queue_t *queue);

void enqueue(queue_t *queue, node_t *node);

node_t* deque(queue_t *queue);

# endif // BREADTH