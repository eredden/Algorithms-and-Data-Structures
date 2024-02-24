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

// to-do: actually implement hash
int hash(int key) { return key; }