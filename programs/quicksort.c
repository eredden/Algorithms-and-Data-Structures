#include <stdio.h>

int partition(int array[], int lo, int hi)
{
    int pivot_value = array[hi];
    int pivot_index = lo - 1;

    // finds values less than pivot
    // swaps them over to the left
    for (int i = lo; i < hi; ++i)
    {
        if (array[i] <= pivot_value)
        {
            pivot_index++;

            int tmp = array[i];
            array[i] = array[pivot_index];
            array[pivot_index] = tmp;
        }
    }

    // ensures index is at least 0
    pivot_index++;

    array[hi] = array[pivot_index];
    array[pivot_index] = pivot_value;

    return pivot_index;
}

void quicksort(int array[], int lo, int hi)
{
    if (lo >= hi) { return; }

    int pivot_index = partition(array, lo, hi);

    quicksort(array, lo, pivot_index - 1);
    quicksort(array, pivot_index + 1, hi);
}

int main(void)
{
    int array[16];
    int array_size = sizeof(array) / sizeof(array[0]);

    // add various filler numbers
    for (int i = 0; i < array_size; i++)
    {
        int value;

        if (i % 2 == 0) { value = i + 5; }
        if (i % 2 != 0) { value = i + 10; }

        array[i] = value;
    }

    printf("BEFORE QUICKSORT:\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    quicksort(array, 0, array_size - 1);

    printf("AFTER QUICKSORT:\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    return 0;
}
