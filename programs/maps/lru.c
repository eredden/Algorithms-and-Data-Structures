#include <stdio.h>
#include <stdlib.h>
#include "lru.h"

typedef struct lru
{
    int length;
    node_t* head, tail;

    // add lookup attribute here
    // should be map type with key/value pair
    // value needs to be node
} lru_t;

void update(int key, int value)
{
    // does key exist

    // if not, need to insert
        // if this exceeds capacity, evict

    // if it does, we need to update to front of list
    // and update value    
}

void get(int key)
{
    // verify that key exists in cache

    // update value we found and move it front
    
    // return value found or NULL
}