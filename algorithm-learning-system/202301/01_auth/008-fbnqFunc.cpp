// 8.斐波那契数列，通项公式 F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）
// 斐波那契数列（Fibonacci sequence），又称黄金分割数列，因数学家莱昂纳多·斐波那契（Leonardo Fibonacci）
// 以兔子繁殖为例子而引入，故又称为“兔子数列”，
// 在现代物理、准晶体结构、化学等领域，斐波那契数列都有直接的应用

#include "stdio.h"

// 1. 递归法
// 课本上的斐布那切数列递归式写法,求斐布那切数列第N项的值，这种方法比较容易理解，但是由于递归层数太多，速度会非常慢，所以
// 求比较高的项用这种方法就不行了，需要用其他方法
int Fibonacci(int n)
{
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 2.数组法求第55项的值
double g_Fibonacci[60] = {0}; // 哪怕用long long也存不下了
void GetFibonacciValue()
{
    g_Fibonacci[0] = 0;
    g_Fibonacci[1] = 1;
    for (int i = 2; i < 60; i++) {
        g_Fibonacci[i] = g_Fibonacci[i - 1] + g_Fibonacci[i - 2];
    }
    return;
}

int main()
{
    printf("\n\n--------递归法----------\n\n"); // 递归法求到第35项左右已经很费劲了
    printf("F(0)=0\n");
    printf("F(1)=1\n");
    for (int i = 2; i < 40; i++) {
        printf("F(%d)=%d\n", i, Fibonacci(i));
    }
    printf("\n\n--------数组法----------\n\n");
    GetFibonacciValue();
    for (int j = 0; j < 55; j++) {
        printf("F(%d) = %f\n", j, g_Fibonacci[j]);
    }
    // 引入问题一.这里想到一道比较有名的问题，求斐波那契数列的第100项的后5位数字，非常经典，虽然表示不出来这样大的数，只让求后5位
    // 引入问题二.知乎看到有人问：C 语言如何利用数组输出斐波那契数列前 100 项？
    return 0;
}
