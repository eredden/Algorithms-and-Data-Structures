#include <stdio.h>
#include <stdlib.h>
#include "lru.h"

hashmap_t* hashmap_factory(void)
{
    hashmap_t* hashmap = (hashmap_t*) malloc(sizeof(hashmap_t));

    if (hashmap == NULL)
    {
        printf("Memory allocation failed for hashmap.\n");
        exit(EXIT_FAILURE);
    }

    hashmap -> table = (map_t**) malloc(HASHMAP_MAX_SIZE * sizeof(map_t));

    if (hashmap -> table == NULL)
    {
        printf("Memory allocation failed for hashmap table.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < HASHMAP_MAX_SIZE; i++)
    {
        hashmap -> table[i] = NULL;
    }

    return hashmap;
}

void hashmap_destructor(hashmap_t* hashmap)
{
    if (hashmap == NULL)
    {
        printf("Hashmap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (hashmap -> table == NULL)
    {
        printf("Hashmap table is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < HASHMAP_MAX_SIZE; i++)
    {
        map_t* map = hashmap -> table[i];

        if (map != NULL) { free(map); }
    }

    free(hashmap -> table);
    free(hashmap);
}

map_t* map_factory(int key, node_t* value)
{
    map_t* map = (map_t*) malloc(sizeof(map_t));

    if (map == NULL)
    {
        printf("Memory allocation failed for map.\n");
        exit(EXIT_FAILURE);
    }

    map -> key = key;
    map -> value = value;
    map -> next = NULL;

    return map;
}

void map_destructor(map_t* map)
{
    if (map == NULL)
    {
        printf("Map is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    free(map);
}

int hash(int key) { return key % HASHMAP_MAX_SIZE; }

void hashmap_insert(hashmap_t* hashmap, int key, node_t* value) 
{
    if (hashmap == NULL)
    {
        printf("Hashmap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (hashmap -> table == NULL)
    {
        printf("Hashmap table is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    int index = hash(key);
    map_t* map = map_factory(key, value);

    map -> next = hashmap -> table[index]; // may need adjustment
    hashmap -> table[index] = map;
}

map_t* hashmap_search(hashmap_t* hashmap, int key)
{
    if (hashmap == NULL)
    {
        printf("Hashmap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (hashmap -> table == NULL)
    {
        printf("Hashmap table is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    int index = hash(key);
    map_t* map = hashmap -> table[index];

    while (map != NULL)
    {
        if (map -> key == key) { return map; }
        if (map -> key != key && map -> next != NULL) { map = map -> next; }
        else { return NULL; }
    }

    return NULL;
}

void hashmap_remove(hashmap_t* hashmap, int key)
{
    if (hashmap == NULL)
    {
        printf("Hashmap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (hashmap -> table == NULL)
    {
        printf("Hashmap table is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    int index = hash(key);
    map_t* map = hashmap -> table[index];

    while (map != NULL)
    {
        map_t* next_map = map -> next;

        if (map -> key == key) 
        { 
            hashmap -> table[index] = next_map; 
            free(map);
            return;
        }

        if (next_map -> key == key) 
        {
            map -> next = next_map -> next;
            free(next_map);
            return;
        }

        map = next_map;
    }

    return;
}
