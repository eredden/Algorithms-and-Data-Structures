#include <stdio.h>
#include <stdlib.h>
#include "array-list.h"

typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
} node_t;

void walk(node_t* node, arraylist_t* path)
{
    if (node == NULL) { return; }

    /* the position of the insert end 
    function determines the order 
    which the tree is recursed, e.g. 
    this is pre-order. */

    arraylist_insert_end(path, node -> value);
    walk(node -> left, path);
    walk(node -> right, path);
}

// int returned here is meant to be bool
int find(node_t* head, int needle)
{
    if (head == NULL) { return 0; }

    if (head -> value == needle) { return 1; }
    else if (head -> value > needle) { find(head -> left, needle); }
    else if (head -> value < needle) { find(head -> right, needle); }
}

void insert(node_t* head, node_t* parent, int needle)
{
    if (head != NULL)
    {
        if (head -> value >= needle) { insert(head -> left, head, needle); }
        if (head -> value <  needle) { insert(head -> right, head, needle); }
    }

    if (head == NULL)
    { 
        /* this causes a memory leak as dynamically allocated memory 
        is not freed; added this to prevent the node from disappearing 
        outside the scope of this function */
        node_t* node = (node_t*) malloc(sizeof(node_t));
        node -> left = node -> right = NULL;
        node -> value = needle;

        if (parent -> value >= needle) { parent -> left  = node; }
        if (parent -> value <  needle) { parent -> right = node; }
    }
}

int main(void)
{
    // initializing proper binary tree
    // as well as prefilled path array
    node_t head;
    node_t node01, node11, node12;
    node_t node02, node21, node22;

    head.left = &node01;
    head.right = &node02;

    node01.left = &node11;
    node01.right = &node12;
    node11.left = node11.right = NULL;
    node12.left = node12.right = NULL;

    node02.left = &node21;
    node02.right = &node22;
    node21.left = node21.right = NULL;
    node22.left = node22.right = NULL;

    head.value = 10;
    
    node01.value = 5;
    node11.value = 2;
    node12.value = 7;

    node02.value = 15;
    node21.value = 12;
    node22.value = 17;

    arraylist_t *path = arraylist_factory(2);

    // using walk()
    walk(&head, path);
    printf("Tree path: ");

    for (int i = 0; i < path -> size; i++)
    {
        if (path -> list[i] == EMPTY_SPOT_INDICATOR) { break; }
        printf("%d ", path -> list[i]);
    }

    printf("\n");

    // using find() and insert()
    int needle = 11;
    insert(&head, &head, needle);

    int result = find(&head, needle);

    if (result) { printf("Needle %d was found.\n"); }
    else        { printf("Needle %d not found.\n"); }

    return 0;
}
