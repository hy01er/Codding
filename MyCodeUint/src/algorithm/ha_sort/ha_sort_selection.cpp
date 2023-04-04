/**
 * Date: 2021/12/15
 * Title: selection_sort.cpp
 * Description: Implement selection sort
 *
 */

#include "ha_sort.h"

BOOL HaSortSelect(int *arr,int nums)
{
    if (arr == NULL || nums <= 0) {
        printf("Error!! nums :%d", nums);
        return FAIL;
    }
    int min;
    for (int i = 0; i < nums - 1; i++) {
        min = i; // init min index
        for (int j = i + 1; j < nums; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(&arr[min], &arr[i]);
        }
    }
    return SUCCESS;
}