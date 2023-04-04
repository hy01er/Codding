/**
 * Date: 2021/12/15
 * Title: Bubblesort.cpp
 * Description: Implement bubble sort of various data types
 *
 */

#include "ha_sort.h"

BOOL HaSortBubble(int *arr,int nums)
{
    if (arr == NULL || nums <= 0) {
        printf("Error!nums:%d\n", nums);
        return FAIL;
    }
    UINT32 i;
    UINT32 j;
    for (i = 0; i < nums - 1; i++) {
        for (j = 0; j < nums - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                Swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    return SUCCESS;
}