/**
 * Date: 2021/12/15
 * Title: insert.cpp
 * Description: Implement insert sort
 *
 */

#include "ha_sort.h"

BOOL HaSortInsert(int *arr, int nums)
{
    if (arr == NULL || nums <= 0) {
        printf("Error!! nums :%d", nums);
        return FAIL;
    }
    for (int i = 1; i < nums; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    return SUCCESS;
}