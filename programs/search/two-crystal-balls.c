#include <stdio.h>
#include <math.h>

int two_crystal_balls(int haystack[], int max)
{  
    int jump_amount = (int)sqrt(max);
    int position = jump_amount;

    for (position; position <= max; position += jump_amount)
    {
        if (haystack[position]) { break; }
    }

    position -= jump_amount;

    for (position; position <= (position + jump_amount); position++)
    {
        if (haystack[position]) { return position; }
    }

    return -1;
}

int main(void)
{
    int haystack[10] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1};
    int max = sizeof(haystack) / sizeof(haystack[0]);

    int result = two_crystal_balls(haystack, max);

    printf("The crystal balls break at position %d!\n", result);

    return 0;
}
