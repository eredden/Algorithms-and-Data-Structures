#ifndef QUEUE
#define QUEUE

typedef struct node 
{
    int value;
    struct node *next;

    // added for bfs, redundant for regular queue stuff
    struct node* left;
    struct node* right;
} node_t;

typedef struct queue
{
    node_t *head;
    node_t *tail;
    int length;
} queue_t;

queue_t* queue_factory(void);

void queue_destructor(queue_t* queue)

int peek(queue_t *queue);

void enqueue(queue_t *queue, node_t *node);

node_t* deque(queue_t *queue);

# endif // QUEUE
