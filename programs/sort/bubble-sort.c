#include <stdio.h>

// used a different format for brackets here, sorry!
void bubble_sort(int array[], int length)
{
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                const int temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
            }
        }  
    }
}

int main(void)
{
    int array[10] = {21, 1, 3, 11, 12, 7, 4, 14, 2, 8};
    int length = sizeof(array) / sizeof(array[0]);

    printf("PRE-BUBBLE SORT:  ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubble_sort(array, length);

    printf("POST-BUBBLE SORT: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
