/* 16.--八皇后问题：这是一个经典问题，是经常考察的问题，也相当有难度

 问题描述：八皇后问题，是一个古老而著名的问题，是回溯算法的典型案例。
 该问题是国际西洋棋棋手马克斯·贝瑟尔于1848年提出：
 在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上，
 问有多少种摆法。 高斯认为有76种方案。1854年在柏林的象棋杂志上不同的作者发表了40种不同的解，
 后来有人用图论的方法解出92种结果。计算机发明后，有多种计算机语言可以解决此问题。
*/

#include "stdio.h"
#include "math.h"

int a[100], n, num;

bool Check(int a[], int n)
{
    for (int i = 1; i < n; i++) {
        if (fabs(a[i] - a[n]) == fabs(i - n) || a[i] == a[n]) {
            return false;
        }
    }
    return true;
}

void GetPos(int k)
{
    if (k > n) {
        printf("第%d种答案：\n", num + 1);
        for (int i = 0; i<= 8; i++) {
            for (int j = 1; j<= a[i]; j++) {
                printf(j == a[i] ? "*" : " ");
            }
            putchar('\n');
        }
        printf("\n-------------------\n");
        num++;
    } else {
        for (int i = 1; i <= n; i++) {
            a[k] = i;
            if (Check(a, k) == true) {
                GetPos(k + 1);
            }
        }
    }
}

int main()
{
    n = 8;
    num = 0;
    GetPos(1);
    printf("The ways of queen is %d", num);
    return 0;
}
