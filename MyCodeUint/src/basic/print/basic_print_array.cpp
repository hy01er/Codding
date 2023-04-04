/**
 * Date: 2021/12/15
 * Title: print_array.cpp
 * Description: 
 *
 */

#include "../type/basic_type.h"

void PrintArray(int *arr, int nums)
{
    if (arr == NULL || nums <= 0) {
        printf("Error!nums:%d\n", nums);
        return;
    }
    int count = 0;
    printf("----Print Array Begin----\n");
    for (int i = 0; i < nums; i++) {
        printf("%d ", arr[i]);
        count++;
        if (count % 10 == 0) {
            putchar('\n');
        }
    }
    printf("\n----Print Array End----\n");
    return;
}