# ifndef LRU
# define LRU

// node definitions start here
typedef struct node
{
    int value;
    struct node *next, *prev;
} node_t;

node_t* node_factory(int value);
void node_destructor(node_t* node);

// map definitions start here
typedef struct map
{
    int key;
    node_t* value;
} map_t;

map_t* map_factory(int key, node_t* value);
void map_destructor(map_t* map);

// lru cache defintions start here
typedef struct lru
{
    int length;
    node_t* head, tail;

    // add lookup attribute here
    // should be map type with key/value pair
    // value needs to be node
} lru_t;

# endif // LRU