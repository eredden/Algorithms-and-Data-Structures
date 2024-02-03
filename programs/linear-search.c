#include <stdio.h>

int linear_search(int haystack[], int size, int needle)
{
    for (int position = 0; position <= size; position++)
    {
        if (haystack[position] == needle) { return 1; }
    }

    return 0;
}

int main(void)
{
    int haystack[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(haystack) / sizeof(haystack[0]);

    for (int needle = 0; needle < 15; needle++) 
    {
        int result = linear_search(haystack, size, needle);

        if (result) { printf("%d was found!\n", needle); }
        else { printf("%d was NOT found!\n", needle); }
    }

    return 0;
}
