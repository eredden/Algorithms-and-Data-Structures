#include <stdio.h>
#include <stdlib.h>

#define EMPTY_SPOT_INDICATOR -1234

typedef struct arraylist
{
    int list[2];
    int size;
} arraylist_t;

arraylist_t* arraylist_factory()
{ 
    arraylist_t* arraylist = (arraylist_t*) malloc(sizeof(arraylist_t));

    if (arraylist == NULL)
    {
        printf("Memory allocation in arraylist_factory() failed.\n");
        exit(EXIT_FAILURE);
    }

    arraylist -> size = 0;

    int* list = arraylist -> list;
    int  list_size = sizeof(list) / sizeof(list[0]);

    for (int i = 0; i < list_size; i++)
    {
        list[i] = EMPTY_SPOT_INDICATOR;
    }

    return arraylist;
}

arraylist_t arraylist_destructor(arraylist_t* arraylist)
{
    if (arraylist == NULL) 
    { 
        printf("Null pointer passed to arraylist_destructor().\n");
        exit(EXIT_FAILURE);
    }

    free(arraylist);
}

int main(void)
{
    arraylist_t* list = arraylist_factory();
    arraylist_destructor(list);

    return 0;
}