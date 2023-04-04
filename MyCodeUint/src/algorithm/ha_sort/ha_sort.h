/**
 * Date: 2021/12/15
 * Title: sort.h
 * Description: Sorting algorithm interface
 *
 */

#ifndef MYCODEUINT_HA_SORT_H
#define MYCODEUINT_HA_SORT_H

#include "../../basic/type/basic_type.h"
#include "cstdint"

typedef BOOL (*SORT)(int *array,int nums);

void Swap(int*, int*);
BOOL HaSortBubble(int *arr,int nums);
BOOL HaSortSelect(int *arr,int nums);
BOOL HaSortInsert(int *arr,int nums);
BOOL HaSortMerge(int *arr, int nums);
BOOL HaSortQuick(int *arr, int nums);
#endif //MYCODEUINT_HA_SORT_H