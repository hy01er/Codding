/**
 * Date: 2021/12/15
 * Title: quick_sort.cpp
 * Description: Implement quicksort
 *
 */
#include "ha_sort.h"

int position(int *arr, int p, int r)
{
    int q = p;
    for (int u = p; u <= r - 1; u++) {
        if (arr[u] <= arr[r]) {
            Swap(&arr[u], &arr[q]);
            q++;
        }
    }
    Swap(&arr[r], &arr[q]);
    return q;
}

BOOL HaSortQuickHandle(int *arr, int p, int r)
{
    if (arr == NULL || p >= r) {
        return false;
    }
    int q = position(arr, p, r);
    HaSortQuickHandle(arr, p, q - 1);
    HaSortQuickHandle(arr, q + 1, r);
    return true;
}

BOOL HaSortQuick(int *arr, int nums)
{
    return HaSortQuickHandle(arr, 0, nums - 1);
}