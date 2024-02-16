#include <stdio.h>
#include <stdlib.h>

#define EMPTY_SPOT_INDICATOR 0

typedef struct arraylist
{
    int  size;
    int  capacity;
    int* list;
} arraylist_t;

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

void arraylist_destructor(arraylist_t* arraylist)
{
    if (arraylist == NULL) 
    { 
        printf("Null pointer (arraylist) passed to arraylist_destructor().\n");
        exit(EXIT_FAILURE);
    }

    if (arraylist -> list == NULL) 
    { 
        printf("Null pointer (list) passed to arraylist_destructor().\n");
        exit(EXIT_FAILURE);
    }

    free(arraylist -> list);
    free(arraylist);
}

void arraylist_insert_end(arraylist_t* arraylist, int value)
{
    if (arraylist == NULL) 
    { 
        printf("Null pointer passed to arraylist_insert_end().\n");
        exit(EXIT_FAILURE);
    }

    int size = arraylist -> size;
    int capacity = arraylist -> capacity;

    if (size == capacity) 
    {
        int  new_capacity = capacity * 2;
        int* new_list = (int*) malloc(new_capacity * sizeof(int));

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

void arraylist_remove_end(arraylist_t* arraylist)
{
    if (arraylist == NULL) 
    { 
        printf("Null pointer passed to arraylist_remove_end().\n");
        exit(EXIT_FAILURE);
    }

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

int main(void)
{
    arraylist_t* list = arraylist_factory(2);

    for (int i = 1; i < 5; i++)
    {
        arraylist_insert_end(list, i);
        arraylist_insert_end(list, i + 1);
        arraylist_remove_end(list);
    }

    printf("Contents of the arraylist: ");
    
    for (int i = 0; i < list -> size; i++) 
    {
        printf("%d ", list -> list[i]);
    }

    printf("\n");

    arraylist_destructor(list);

    return 0;
}