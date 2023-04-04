// 11 计算阶乘   n!=1×2×3×...×(n-1)×n

// 这种看起来有两种方式  一种是递归法  一种是循环法

#include "stdio.h"

#define ERROR -9999
typedef int (*Factorial)(int n);

// 递归法
int factorial1(int n)
{
    if (n < 0) {
        return ERROR;
    }
    if (n == 1) {
        return 1;
    }
    return factorial1(n - 1) * n;
}

// 循环法
int factorial2(int n)
{
    if (n < 0) {
        return ERROR;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res  *= i;
    }
    return res;
}

int main()
{
    Factorial f1 = factorial1;
    Factorial f2 = factorial2;
    int n = 9;
    printf("f1：9! = %d\n", f1(9));
    printf("f2：9! = %d\n", f2(9));
    return 0;
}
