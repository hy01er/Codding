/**
 * Date: 2021/12/15
 * Title: merge_sort.cpp
 * Description: Implement merge sort
 *
 */

#include "ha_sort.h"

static void HaMerge(int *arr, int p, int q, int r)
{
    if (arr == NULL) {
        return;
    }
    int n1 = q - p + 1;
    int n2 = r - q;
    int b[n1 + 1];
    int c[n2 + 1];
    int bIndex = 0;
    int cIndex = 0;
    for (int i = p; i <= r; i++) {
        if (i <= q) {
            b[bIndex++] = arr[i];
        } else {
            c[cIndex++] = arr[i];
        }
    }
    b[n1] = INT32_MAX;
    c[n2] = INT32_MAX;
    bIndex = 0;
    cIndex = 0;
    for (int i = p; i <= r; i++) {
        if (b[bIndex] <= c[cIndex]) {
            arr[i] = b[bIndex++];
        } else {
            arr[i] = c[cIndex++];
        }
    }
}

BOOL HaSortMergeHandle(int *arr, int p, int r)
{
    if (arr == NULL || p >= r) {
        return false;
    }
    int q = (p +r) / 2;
    HaSortMergeHandle(arr, p, q);
    HaSortMergeHandle(arr, q + 1, r);
    HaMerge(arr, p, q, r);
    return true;
}

BOOL HaSortMerge(int *arr, int nums)
{
    return HaSortMergeHandle(arr, 0, nums - 1);
}
