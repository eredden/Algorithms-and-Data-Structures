#include <stdio.h>
#include <stdlib.h>
#include "lru.h"

lru_t* lru_factory(int capacity)
{
    lru_t* lru = (lru_t*) malloc(sizeof(lru_t));
    map_t* lookup = (map_t*) malloc(capacity * sizeof(map_t));
    map_t* reverse_lookup = (map_t*) malloc(capacity * sizeof(map_t));

    if (lru == NULL)
    {
        printf("Memory allocation for LRU failed.\n");
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

    free(lru -> lookup);
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
    lru_t* lru = lru_factory(10);

    printf("LRU has been created!\n");

    // note how we manually state the position of the array
    // map hash function needs to do this for us
    // work on hashing function
    lru -> lookup[hash(9, 10)] = *map_factory(100, node_factory(100));

    for (int i = 0; i < 10; i++)
    {
        printf("On iteration %d:\n", i);
        map_t map = lru -> lookup[i];
        printf("%d key for %p value in position %d.\n", map.key, map.value, i);
    }

    return 0;
}