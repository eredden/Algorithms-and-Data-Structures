#include <stdio.h>

int binary_search(int haystack[], int min, int max, int needle)
{
    while (min < max)
    {
        int midpoint = min + (max - min) / 2;
        int value = haystack[midpoint];

        if (value == needle) { return 1; }
        if (value > needle)  { max = midpoint; }
        if (value < needle)  { min = midpoint + 1; }
    }

    return 0;
}

int main(void)
{
    int haystack[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int min = 0;
    int max = sizeof(haystack) / sizeof(haystack[0]);

    for (int needle = 0; needle < 15; needle++) 
    {
        int result = binary_search(haystack, min, max, needle);

        if (result) { printf("%d was found!\n", needle); }
        else { printf("%d was NOT found!\n", needle); }
    }

    return 0;
}
