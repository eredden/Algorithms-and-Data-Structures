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
void hashmap_validate(hashmap_t* hashmap);
void hashmap_destructor(hashmap_t* hashmap);

int hash(int key);
void hashmap_insert(hashmap_t* hashmap, int key, node_t* value);
void hashmap_remove(hashmap_t* hashmap, int key);
map_t* hashmap_search(hashmap_t* hashmap, int key);
node_t* hashmap_get(hashmap_t* hashmap, int key);

map_t* map_factory(int key, node_t* value);
void map_destructor(map_t* map);

// lru cache defintions start here
typedef struct lru
{
    int length;
    int capacity;
    node_t* head;
    node_t* tail;
    hashmap_t* lookup;
    hashmap_t* reverse_lookup;
} lru_t;

lru_t* lru_factory(int capacity);
void lru_destructor(lru_t* lru);

void lru_update(lru_t* lru, int key, int value);
void lru_detach(lru_t* lru, node_t* node);
void lru_prepend(lru_t* lru, node_t* node);
void lru_trim_cache(lru_t* lru);
int lru_get(lru_t* lru, int key);

# endif // LRU