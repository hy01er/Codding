/**
 * Date: 2021/12/15
 * Title: merge_sort.cpp
 * Description: Implement merge sort
 *
 */

#include "ha_sort.h"

static void HaMerge(int *arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int b[n1 + 1];
    int c[n2 + 1];
    int bIndex = 0;
    int cIndex = 0;
    for (int i = p; i <= r; i++) {
        if (i <= q) {
            b[bIndex] = arr[i];
            bIndex++;
        } else {
            c[cIndex] = arr[i];
            cIndex++;
        }
    }
    b[n1] = INT32_MAX;
    b[n2] = INT32_MAX;
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

BOOL HaSortMerge(int *arr, int p, int r)
{
    if (arr == NULL || p >= r) {
        return false;
    }
    int q = (p +r) / 2;
    HaSortMerge(arr, p, q);
    HaSortMerge(arr, q + 1, r);
    HaMerge(arr, p, q, r);
    return true;
}
