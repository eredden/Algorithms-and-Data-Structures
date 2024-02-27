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

void lru_update(lru_t* lru, int key, int value)
{
    node_t* node = hashmap_get(lru -> lookup, key);

    if (node == NULL) 
    { 
        node_t* new_node = node_factory(value);
        lru -> length++;

        lru_prepend(lru, new_node);
        lru_trim_cache(lru);

        hashmap_insert(lru -> lookup, key, new_node);
        hashmap_insert(lru -> reverse_lookup, value, node_factory(key));
    }

    else
    {
        lru_detach(lru, node);
        lru_prepend(lru, node);
        node -> value = value;
    }
}

void lru_detach(lru_t* lru, node_t* node) 
{
    if (node -> prev) { node -> prev -> next = node -> next; }
    if (node -> next) { node -> next -> prev = node -> prev; }

    if (lru -> length == 1) { lru -> head = lru -> tail = NULL; }

    if (lru -> head == node) { lru -> head = node -> next; }
    if (lru -> tail == node) { lru -> tail = node -> prev; }

    node -> prev = NULL;
    node -> next = NULL;
}

void lru_prepend(lru_t* lru, node_t* node) 
{
    if (!(lru -> head)) 
    { 
        lru -> head = lru -> tail = node; 
        return;
    }

    node -> next = lru -> head;
    lru -> head -> prev = node;

    lru -> head = node;
}

void lru_trim_cache(lru_t* lru)
{
    if (lru -> capacity >= lru -> length) { return; }

    node_t* tail = lru -> tail;
    lru_detach(lru, tail);

    int key = tail -> value;

    hashmap_remove(lru -> lookup, key);
    hashmap_remove(lru -> reverse_lookup, key);

    lru -> length--;
}

int lru_get(lru_t* lru, int key)
{
    node_t* node = hashmap_get(lru -> lookup, key);

    if (node == NULL) { return -1; }

    lru_detach(lru, node);
    lru_prepend(lru, node);

    return node -> value;
}

// temporarily here for testing as this program broke
int main(void)
{
    lru_t* lru = lru_factory(HASHMAP_MAX_SIZE);

    lru_update(lru, 9, 10);
    lru_update(lru, 11, 12);
    lru_update(lru, 13, 14);

    printf("%p head, %p tail, %d length, %d capacity.\n", 
        lru -> head, lru -> tail, lru -> length, lru -> capacity);

    lru_destructor(lru);

    return 0;
}