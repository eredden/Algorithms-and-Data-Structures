#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node 
{
    int value;
    struct node *prev, *next;
} node_t;

typedef struct linked_list
{
    node_t *head;
    node_t *tail;
    int length;
} linked_list_t;

linked_list_t* linked_list_factory(void);
void linked_list_destructor(linked_list_t* linked_list);

int get_length(linked_list_t *linked_list);

node_t* get_node(linked_list_t *linked_list, int index);

void insert_at(linked_list_t *linked_list, node_t *node, int index);
void insert_front(linked_list_t *linked_list, node_t *node);
void insert_back(linked_list_t *linked_list, node_t *node);

int remove_at(linked_list_t *linked_list, int index);
int remove_front(linked_list_t *linked_list);
int remove_back(linked_list_t *linked_list);

# endif // LINKED_LIST
