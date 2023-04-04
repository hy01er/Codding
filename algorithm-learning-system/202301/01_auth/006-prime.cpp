// 6. 素数判断，不管是学校的期末考试还是ACM的入门考试，这个题是经典题

// 思路：素数的定义：素数指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数，也叫质数

#include "stdio.h"

bool IsPrime(int num)
{
    if (num == 0 || num == 1 || num < 0) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    printf("打印1-100的素数：\n");
    int temp = 0; // 用于打印一行数字后换行
    for (int i = 1; i<= 100; i++) {
        if (IsPrime(i)) {
            printf("%4d\t\t", i);
            temp++;
            if (temp % 5 == 0) {
                printf("\n\n");
            }
        }
    }
    printf("1-100的素数共%d个\n\n", temp);
    printf("\n\n\n------------1-100素数分布图---------------\n\n");
    for (int i = 1; i<= 100; i++) {
        if (IsPrime(i)) {
            printf("%4d\t", i);
        } else {
            printf("   _\t");
        }
        if (i % 10 == 0) {
            printf("\n\n");
        }
    }
    return 0;
}