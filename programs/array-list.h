#ifndef ARRAY_LIST
#define ARRAY_LIST

#define EMPTY_SPOT_INDICATOR 0

typedef struct arraylist
{
    int  size;
    int  capacity;
    int* list;
} arraylist_t;

arraylist_t* arraylist_factory(int capacity);
void arraylist_destructor(arraylist_t* arraylist);

void validate_arraylist(arraylist_t* arraylist);

void arraylist_insert(arraylist_t* arraylist, int value, int position);
void arraylist_insert_beginning(arraylist_t* arraylist, int value);
void arraylist_insert_end(arraylist_t* arraylist, int value);

void arraylist_remove(arraylist_t* arraylist, int position);
void arraylist_remove_beginning(arraylist_t* arraylist);
void arraylist_remove_end(arraylist_t* arraylist);

# endif // ARRAY_LIST
