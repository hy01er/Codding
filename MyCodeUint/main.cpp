
#include "src/algorithm/ha_sort/ha_sort.h"
#include "src/basic/print/basic_print.h"

int main()
{
    INT32 arr[] = {566, 999,23, 12, 526, -52, -96, 85, -446, 96586};
    SORT sort = HaSortQuick;
    sort(arr, SIZE_ARRAY(arr));
    PrintArray(arr, SIZE_ARRAY(arr));
    return 0;
}
