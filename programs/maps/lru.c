#include <stdio.h>
#include <stdlib.h>
#include "lru.h"

lru_t* lru_factory(int capacity)
{
    lru_t* lru = (lru_t*) malloc(sizeof(lru_t));
    hashmap_t* lookup = hashmap_factory();
    hashmap_t* reverse_lookup = hashmap_factory();

    if (lru == NULL)
    {
        printf("Memory allocation for LRU failed.\n");
        exit(EXIT_FAILURE);
    }

    if (lookup == NULL)
    {
        printf("Memory allocation for lookup hashmap failed.\n");
        exit(EXIT_FAILURE);
    }

    if (reverse_lookup == NULL)
    {
        printf("Memory allocation for reverse lookup hashmap failed.\n");
        exit(EXIT_FAILURE);
    }

    lru -> length = 0;
    lru -> capacity = capacity;

    lru -> head = NULL;
    lru -> tail = NULL;

    lru -> lookup = lookup;
    lru -> reverse_lookup = reverse_lookup;

    return lru;
}

void lru_destructor(lru_t* lru)
{
    if (lru == NULL)
    {
        printf("LRU is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (lru -> lookup == NULL)
    {
        printf("LRU lookup is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (lru -> reverse_lookup == NULL)
    {
        printf("LRU reverse lookup is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    hashmap_destructor(lru -> lookup);
    hashmap_destructor(lru -> reverse_lookup);
    free(lru);
}

void update(lru_t* lru, int key, int value)
{
    // does key exist

    // if not, need to insert
        // if this exceeds capacity, evict

    // if it does, we need to update to front of list
    // and update value    
}

void get(lru_t* lru, int key)
{
    // verify that key exists in cache
    // get value by key

    // update value we found and move it front
    
    // return value found or NULL
}

int main(void)
{
    hashmap_t* hashmap = hashmap_factory();

    hashmap_insert(hashmap, 1, NULL);

    for (int i = 0; i < HASHMAP_MAX_SIZE; i++)
    {
        map_t* map = hashmap -> table[i];
        if (map == NULL) { continue; }

        int key = map -> key;
        node_t* value = map -> value;

        printf("Key %d for node %p in table position %d.\n", key, value, i);
    }

    hashmap_destructor(hashmap);

    return 0;
}