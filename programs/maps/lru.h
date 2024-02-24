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

int hash(int key, int size);
map_t* search(map_t** hash_map, int size, int key);

// lru cache defintions start here
typedef struct lru
{
    int length;
    int capacity;
    node_t* head;
    node_t* tail;
    map_t* lookup;
    map_t* reverse_lookup;
} lru_t;

lru_t* lru_factory(int capacity);
void lru_destructor(lru_t* lru);

void update(lru_t* lru, int key, int value);
void get(lru_t* lru, int key);

# endif // LRU