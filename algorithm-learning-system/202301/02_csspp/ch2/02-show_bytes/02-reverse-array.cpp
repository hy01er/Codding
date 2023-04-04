// Êý×é·­×ª

#include <stdio.h>

void swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int arr[], int cnt)
{
    if (arr == NULL || cnt <= 0) {
        return;
    }
    int first, last;
    for(first = 0, last = cnt - 1; first < last; first++, last--) {
        swap(&arr[first], &arr[last]);
    }
    return;
}

int main ()
{
    int arr[5] = {646, 526, 999, 325, 451};
    reverse_array(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}