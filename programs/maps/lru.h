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
#define HASHMAP_MAX_SIZE 10

typedef struct map
{
    int key;
    node_t* value;
    struct map *next;
} map_t;

typedef struct hashmap
{
    map_t** table;
} hashmap_t;

hashmap_t* hashmap_factory(void);
void hashmap_destructor(hashmap_t* hashmap);

map_t* map_factory(int key, node_t* value);
void map_destructor(map_t* map);

int hash(int key);
void hashmap_insert(hashmap_t* hashmap, int key, node_t* value);
map_t* hashmap_search(hashmap_t* hashmap, int key);
void hashmap_remove(hashmap_t* hashmap, int key);

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