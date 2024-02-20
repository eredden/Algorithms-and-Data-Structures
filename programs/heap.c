#include <stdio.h>
#include <stdlib.h>
#include "array-list.h"

int getLeft(int index)   { return 2 * index + 1; }
int getRight(int index)  { return 2 * index + 2; }
int getParent(int index) { return (index - 1) / 2; }

void heapifyUp(arraylist_t* heap, int index)
{   
    if (heap == NULL)
    {
        printf("Heap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    int value = heap -> list[index];

    int parent_index = getParent(index);
    int parent_value = heap -> list[parent_index];

    if (parent_index < 0) { return; }

    if (parent_value > value)
    {
        heap -> list[index] = parent_value;
        heap -> list[parent_index] = value;

        heapifyUp(heap, parent_index);
    }
}

void heapifyDown(arraylist_t* heap, int index)
{
    if (heap == NULL)
    {
        printf("Heap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (index >= heap -> size ) { return; }

    int value = heap -> list[index];

    int left_index = getLeft(index);
    int left_value = heap -> list[left_index];

    int right_index = getRight(index);
    int right_value = heap -> list[right_index];

    if (left_index >= heap -> size)  { return; }

    if (left_value > right_value && value > right_value) 
    { 
        heap -> list[index] = right_value;
        heap -> list[right_index] = value;

        heapifyDown(heap, right_index);
    }

    if (left_value < right_value && value > left_value) 
    { 
        heap -> list[index] = left_value;
        heap -> list[left_index] = value;

        heapifyDown(heap, left_index);
    }
}

void heap_insert(arraylist_t* heap, int value)
{
    if (heap == NULL)
    {
        printf("Heap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    arraylist_insert_end(heap, value);
    heapifyUp(heap, heap -> size - 1);
}

int heap_remove(arraylist_t* heap)
{
    if (heap == NULL)
    {
        printf("Heap is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (heap -> size == 0)
    {
        printf("No items in the heap.\n");
        exit(EXIT_FAILURE);
    }

    int head_value = heap -> list[0];
    int end_index = heap -> size - 1;
    int end_value = heap -> list[end_index];

    arraylist_remove_beginning(heap);

    if (heap -> size == 1) { return head_value; }

    arraylist_insert_beginning(heap, end_value);
    arraylist_remove_end(heap);

    heapifyDown(heap, 0);

    return head_value;
}

int main(void)
{
    arraylist_t* heap = arraylist_factory(2);

    // fill heap with 1 to 7
    for (int i = 1; i <= 7; i++) 
    { 
        arraylist_insert_end(heap, i); 
    }

    // insert 0, then remove it again
    heap_insert(heap, 0);
    heap_remove(heap);

    // should output 1 to 7
    for (int i = 0; i < heap -> size; i++)
    {
        printf("%d ", heap -> list[i]);
    }

    printf("\n");

    return 0;
}