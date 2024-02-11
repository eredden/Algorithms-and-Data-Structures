#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH_LENGTH 50
#define EMPTY_SPOT_INDICATOR -1234

typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
} node_t;

void walk(node_t* node, int path[])
{
    if (node == NULL) { return; }

    // get next empty spot in array
    int index = 0;
    for(index; index < MAX_PATH_LENGTH; index++)
    {
        if (path[index] == EMPTY_SPOT_INDICATOR) { break; }
        if (index == MAX_PATH_LENGTH - 1) { exit(-1); }
    }

    /* 
    the position of the path[index] assignment
    determines the order in which the tree is
    recrursed, e.g. this is pre-order.
    */

    path[index] = node -> value;
    walk(node -> left, path);
    walk(node -> right, path);
}

int* pre_order_search(node_t* head, int path[])
{
    walk(head, path);

    return path;
}

int main(void)
{
    node_t head;
    node_t node01, node02;
    node_t node11, node12;
    node_t node21, node22;

    head.left = &node01;
    head.right = &node02;

    node01.left = &node11;
    node01.right = &node12;

    node02.left = &node21;
    node02.right = &node22;

    node11.left = node11.right = NULL;
    node12.left = node12.right = NULL;
    node21.left = node21.right = NULL;
    node22.left = node22.right = NULL;

    head.value = 69;
    node01.value = 1;
    node02.value = 2;
    node11.value = 11;
    node12.value = 12;
    node21.value = 21;
    node22.value = 22;

    int path[MAX_PATH_LENGTH];

    for (int i = 0; i < MAX_PATH_LENGTH; i++)
    {
        path[i] = EMPTY_SPOT_INDICATOR;
    }

    pre_order_search(&head, path);

    printf("PATH: ");
    for (int i = 0; i < MAX_PATH_LENGTH; i++)
    {
        if (path[i] == EMPTY_SPOT_INDICATOR) { break; }
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}
