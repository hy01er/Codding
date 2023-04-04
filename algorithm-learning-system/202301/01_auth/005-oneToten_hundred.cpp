// 5. 用递归的方式打印 1-100，主要是体会递归的思想

#include "stdio.h"

typedef void (*PrintNum)(int, int);

void PrintIntNum(int begin, int end)
{
    if (begin > end) {
        return;
    }
    printf("%4d\t", begin);
    if (begin % 5 == 0) {
        putchar('\n');
    }
    return PrintIntNum(begin + 1, end);
}

int main()
{
    PrintNum p1 = PrintIntNum;
    p1(1, 100);
}
