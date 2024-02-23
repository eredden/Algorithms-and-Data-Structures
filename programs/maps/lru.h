# ifndef LRU
# define LRU

typedef struct node
{
    int value;
    struct node *next, *prev;
} node_t;

typedef struct map
{
    int key;
    node_t* value;
} map_t;

node_t* node_factory(int value);
void node_destructor(node_t* node);

map_t* map_factory(int key, node_t* value);
void map_destructor(map_t* map);

# endif // LRU