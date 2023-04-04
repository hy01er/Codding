/* 二30.闰年的判断
   什么是闰年？
   1.如果是世纪年的话，必须被400整除
   2.如果不是世纪年，被4整除的年是闰年
*/

#include "stdio.h"

bool IsLeapYear(int year)
{
    if (year <= 0) {
        return false;
    }
    if (year % 100 == 0 && year % 400 == 0) {
        return true;
    } else if (year % 100 != 0 && year % 4 == 0) {
        return true;
    }
    return false;
}

int main30 ()
{
    int leapYearNums = 0;
    printf("输出1997-2023年的闰年：\n");
    for (int i = 1997; i < 2023; i++) {
        bool IsLeapI = IsLeapYear(i);
        printf(IsLeapI ? "%4d\t" : "", i);
        if (IsLeapI) {
            leapYearNums++;
        }
        if (leapYearNums % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n\n1997 - 2023 leap year nums:%d", leapYearNums);
    return 0;
}
