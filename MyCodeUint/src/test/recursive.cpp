/**
 * Date: 2021/12/15
 * Title: recursive.cpp
 * Description: some recursive example test
 *
 */
#include "../basic/type/basic_type.h"

/* 1. Print from begin to end */
typedef void (*PRINT) (int, int);
void print1(int begin, int end);
void print2(int begin, int end);

PRINT g_print = NULL;

BOOL PrintInit()
{
    g_print = print1;
}

void print1(int begin, int end)
{
    if (begin > end) {
        return;
    }
    printf("%d\t", begin);
    return print1(begin + 1, end);
}

void print2(int begin, int end)
{
    if (begin > end) {
        return;
    }
    printf("%d\t", end);
    return print2(begin, end - 1);
}

/* 2. */