#include <stdio.h>
#include <stdlib.h>
#include "lru.h"

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

int hash(int key, int size) { return key % size; }

map_t* search(map_t** hash_map, int size, int key)
{
    if (hash_map == NULL)
    {
        printf("Hash map is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    int index = hash(key, size);
    map_t* map = hash_map[index];

    while (map -> key != 0)
    {
        if (map -> key == key) { return map; }
        if (map -> key != key && index < size) { index++; }
        else { break; }
    }
}