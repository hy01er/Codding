// 13 素数筛 就是
#include "stdio.h"
#include "math.h"

// 特征，求10000以内的素数，或者素数个数，这里10000可以换成10万  100万  1000万等

// 常见做法
#define N 10000000

bool IsPrime1(int num)
{
    if (num == 0 || num == 1 || num < 0) {
        return false;
    }
    for (int i = 2; i <= sqrt(num);i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int FindPrinmN1()
{
    int counts = 0;
    for (int i = 2; i < N; i++) {
        if (IsPrime1(i)) {
            //printf("%d\t", i);
            counts++;
        }
    }
    return counts;
}

// 素数筛
int prime[N];
int FindPrinmN2()
{
    int counts = 0;
    int i;
    for (i = 0;i < N; i++) {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    for (i = 2; i < N; i++) {
        if (prime[i] == 1) {
            for (int j = 2; i * j < N; j++) {
                if (prime[i * j] == 1) {
                    prime[i * j] = 0;
                }
            }
        }
    }
    for (i = 0; i < N; i++) {
        if (prime[i] == 1) {
            //printf("%d\t", i);
            counts++;
        }
    }
    return counts;
}

int main()
{
    printf("-------------------------2\n\n");
    printf("\n\n--%d\n", FindPrinmN2());
    printf("-------------------------1\n\n");
    printf("\n\n--%d\n", FindPrinmN1());
}
