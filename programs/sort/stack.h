#ifndef STACK
#define STACK

typedef struct node 
{
    int value;
    struct node *next;
} node_t;

typedef struct stack
{
    node_t *head;
    int length;
} stack_t;

stack_t* stack_factory();
void stack_destructor(stack_t* stack);

int peek(stack_t *stack);

void push(stack_t *stack, node_t *node);

int pop(stack_t *stack);

# endif // STACK
