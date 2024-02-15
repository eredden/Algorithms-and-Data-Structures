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
        printf("Memory allocation in arraylist_factory() failed.\n");
        exit(EXIT_FAILURE);
    }

    arraylist -> list = (int*) malloc(capacity * sizeof(int));

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
        printf("Null pointer passed to arraylist_destructor().\n");
        exit(EXIT_FAILURE);
    }

    free(arraylist -> list);
    free(arraylist);
}

void arraylist_insert_end(arraylist_t* arraylist, int value)
{
    int* list = arraylist -> list;
    int  size = arraylist -> size;
    int  capacity = arraylist -> capacity;

    if (size == capacity) 
    {
        int  new_capacity = arraylist -> capacity * 2;
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

int main(void)
{
    arraylist_t* list = arraylist_factory(2);

    arraylist_insert_end(list, 1);
    arraylist_insert_end(list, 2);
    arraylist_insert_end(list, 3);
    arraylist_insert_end(list, 4);

    printf("Contents of the arraylist: ");
    
    for (int i = 0; i < list -> size; i++) 
    {
        printf("%d ", list -> list[i]);
    }

    printf("\n");

    arraylist_destructor(list);

    return 0;
}