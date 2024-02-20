#include <stdio.h>
#include <stdlib.h>
#include "array-list.h"

arraylist_t* arraylist_factory(int capacity)
{ 
    arraylist_t* arraylist = (arraylist_t*) malloc(sizeof(arraylist_t));

    if (arraylist == NULL)
    {
        printf("Memory allocation for arraylist in arraylist_factory() failed.\n");
        exit(EXIT_FAILURE);
    }

    arraylist -> list = (int*) malloc(capacity * sizeof(int));

    if (arraylist -> list == NULL)
    {
        printf("Memory allocation for list in arraylist_factory() failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < capacity; i++)
    {
        arraylist -> list[i] = EMPTY_SPOT_INDICATOR;
    }

    arraylist -> size = 0;
    arraylist -> capacity = capacity;

    return arraylist;
}

// ensures arraylist doesn't use null pointers
// otherwise freeing it will screw things up
void validate_arraylist(arraylist_t* arraylist)
{
    if (arraylist == NULL)
    {
        printf("Arraylist is a null pointer.\n");
        exit(EXIT_FAILURE);
    }

    if (arraylist -> list == NULL)
    {
        printf("List inside arraylist is a null pointer.\n");
        exit(EXIT_FAILURE);
    }
}

void arraylist_destructor(arraylist_t* arraylist)
{
    validate_arraylist(arraylist);

    free(arraylist -> list);
    free(arraylist);
}

void arraylist_insert(arraylist_t* arraylist, int value, int position)
{
    validate_arraylist(arraylist);

    int size = arraylist -> size;
    int capacity = arraylist -> capacity;

    if (position < 0 || position > capacity - 1)
    {
        printf("Position is out of bounds.\n");
        exit(EXIT_FAILURE);
    }

    if (size == capacity) 
    {
        int  new_capacity = capacity * 2;
        int* new_list = (int*) malloc(new_capacity * sizeof(int));

        if (new_list == NULL)
        {
            printf("Memory allocation failed for new list.\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < position; i++)
        {
            new_list[i] = arraylist -> list[i];
        }

        new_list[position] = value;

        for (int i = position; i < size + 1; i++)
        {
            new_list[i + 1] = arraylist -> list[i];
        }

        for (int i = size + 1; i < new_capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);

        arraylist -> list = new_list;
        arraylist -> capacity = new_capacity;
    }

    else 
    { 
        int* new_list = (int*) malloc(capacity * sizeof(int));

        if (new_list == NULL)
        {
            printf("Memory allocation failed for new list.\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < position; i++)
        {
            new_list[i] = arraylist -> list[i];
        }

        new_list[position] = value;

        for (int i = position; i < capacity; i++)
        {
            new_list[i + 1] = arraylist -> list[i];
        }
        
        free(arraylist -> list);
        arraylist -> list = new_list;
    }

    arraylist -> size++;
}

void arraylist_insert_beginning(arraylist_t* arraylist, int value)
{
    validate_arraylist(arraylist);

    int size = arraylist -> size;
    int capacity = arraylist -> capacity;

    if (size == capacity) 
    {
        int  new_capacity = capacity * 2;
        int* new_list = (int*) malloc(new_capacity * sizeof(int));

        if (new_list == NULL)
        {
            printf("Memory allocation failed for new list.\n");
            exit(EXIT_FAILURE);
        }

        new_list[0] = value;

        for (int i = 1; i < size + 1; i++)
        {
            new_list[i] = arraylist -> list[i - 1];
        }

        for (int i = size + 1; i < new_capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);

        arraylist -> list = new_list;
        arraylist -> capacity = new_capacity;
    }

    else 
    { 
        int* new_list = (int*) malloc(capacity * sizeof(int));

        if (new_list == NULL)
        {
            printf("Memory allocation failed for new list.\n");
            exit(EXIT_FAILURE);
        }

        new_list[0] = value;

        for (int i = 1; i < size + 1; i++)
        {
            new_list[i] = arraylist -> list[i - 1];
        }

        for (int i = size + 1; i < capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);
        arraylist -> list = new_list;
    }

    arraylist -> size++;
}

void arraylist_insert_end(arraylist_t* arraylist, int value)
{
    validate_arraylist(arraylist);

    int size = arraylist -> size;
    int capacity = arraylist -> capacity;

    if (size == capacity) 
    {
        int  new_capacity = capacity * 2;
        int* new_list = (int*) malloc(new_capacity * sizeof(int));

        if (new_list == NULL)
        {
            printf("Memory allocation failed for new list.\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < size; i++)
        {
            new_list[i] = arraylist -> list[i];
        }

        for (int i = size; i < new_capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);

        arraylist -> list = new_list;
        arraylist -> capacity = new_capacity;
    }

    arraylist -> list[size] = value;
    arraylist -> size++;
}

void arraylist_remove(arraylist_t* arraylist, int position)
{
    validate_arraylist(arraylist);

    int size = arraylist -> size;
    int capacity = arraylist -> capacity;

    if (size == 0) 
    {
        printf("List is already empty.\n");
        exit(EXIT_FAILURE);
    }

    if (position < 0 || position > size - 1)
    {
        printf("Position is out of bounds.\n");
        exit(EXIT_FAILURE);
    }

    if (size == capacity / 2 + 1) 
    {
        int  new_capacity = capacity / 2;
        int* new_list = (int*) malloc(new_capacity * sizeof(int));

        for (int i = 0; i < position; i++)
        {
            new_list[i] = arraylist -> list[i];
        }

        for (int i = position + 1; i < size; i++)
        {
            new_list[i - 1] = arraylist -> list[i];
        }

        for (int i = size; i < new_capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);

        arraylist -> list = new_list;
        arraylist -> capacity = new_capacity;
    }

    else 
    {
        int* new_list = (int*) malloc(capacity * sizeof(int));

        for (int i = 0; i < position; i++)
        {
            new_list[i] = arraylist -> list[i];
        }

        for (int i = position + 1; i < size; i++)
        {
            new_list[i - 1] = arraylist -> list[i];
        }

        for (int i = size; i < capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);
        arraylist -> list = new_list;
    }

    arraylist -> size--;
}

void arraylist_remove_beginning(arraylist_t* arraylist)
{
    validate_arraylist(arraylist);

    int size = arraylist -> size;
    int capacity = arraylist -> capacity;

    if (size == 0) 
    {
        printf("List is already empty.\n");
        exit(EXIT_FAILURE);
    }

    if (size == capacity / 2 + 1) 
    {
        int  new_capacity = capacity / 2;
        int* new_list = (int*) malloc(new_capacity * sizeof(int));

        for (int i = 1; i < size; i++)
        {
            new_list[i - 1] = arraylist -> list[i];
        }

        for (int i = size; i < new_capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);

        arraylist -> list = new_list;
        arraylist -> capacity = new_capacity;
    }

    else
    {
        int* new_list = (int*) malloc(capacity * sizeof(int));

        for (int i = 1; i < size; i++)
        {
            new_list[i - 1] = arraylist -> list[i];
        }

        for (int i = size; i < capacity; i++)
        {
            new_list[i] = EMPTY_SPOT_INDICATOR;
        }
        
        free(arraylist -> list);
        arraylist -> list = new_list;
    }

    arraylist -> size--;
}

void arraylist_remove_end(arraylist_t* arraylist)
{
    validate_arraylist(arraylist);

    int size = arraylist -> size;
    int capacity = arraylist -> capacity;

    if (size == 0) 
    {
        printf("List is already empty.\n");
        exit(EXIT_FAILURE);
    }

    if (size == capacity / 2 + 1) 
    {
        int  new_capacity = capacity / 2;
        int* new_list = (int*) malloc(new_capacity * sizeof(int));

        for (int i = 0; i < new_capacity; i++)
        {
            new_list[i] = arraylist -> list[i];
        }
        
        free(arraylist -> list);

        arraylist -> list = new_list;
        arraylist -> capacity = new_capacity;
    }

    arraylist -> size--;
}
