
#include "src/basic/type/basic_type.h"
#include "src/algorithm/ha_sort/ha_sort.h"
#include "src/basic/print/basic_print.h"

#define MAX_ARRAY_LENGTH 10
#define BIGGER_NUM 56
#define SIMER  42

int main()
{
    INT32 arr[MAX_ARRAY_LENGTH] = {566, 852,23, 12, 526, -52, -96, 85, -446, 96586};
    int *pArray = arr;
    HaSortMerge(pArray, 0, MAX_ARRAY_LENGTH);
    PrintArray(pArray, MAX_ARRAY_LENGTH);
    int a = BIGGER_NUM;
    int b = SIMER;
    Swap(&a, &b);
    printf("\n%d %d", a, b);
    return 0;
}