#include <stdio.h>
#include <stdlib.h>
#include "../sort/queue.h"

int breadth_first_search(node_t* head, int needle)
{
    if (head == NULL)
    {
        printf("Head is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    queue_t queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.length = 0;

    enqueue(&queue, head);

    while (queue.length)
    {
        node_t* curr = deque(&queue);

        if (curr -> value == needle) { return 1; }

        if (curr -> left != NULL)
        {
            enqueue(&queue, curr -> left);
        }

        if (curr -> right != NULL)
        {
            enqueue(&queue, curr -> right);
        }
    }

    return 0;
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

    int needle;

    printf("What number should be searched for? ");
    scanf("%d", &needle);

    int result = breadth_first_search(&head, needle);
    
    if (result) { printf("%d was found!\n", needle); }
    else { printf("%d not found.\n", needle); }

    return 0;
}