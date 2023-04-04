// 12. 水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身。例如：1^3 + 5^3+ 3^3 = 153
// 输出1000内的所有水仙花数

#include "stdio.h"
#include "math.h"

typedef bool (*IsNarcissisticNumber)(int n);

// 判断是否是水仙花数
bool IsNarcissisticNumber1(int n)
{
    if (n < 100 || n > 999) { // 不是三位数
        return false;
    }
    // 分解它的百位 十位 个位
    int hundred = n / 100;
    int ten = (n - hundred * 100) / 10;
    int bit = n % 10;
    int s1 = hundred * hundred * hundred;
    int s2 = ten * ten * ten;
    int s3 = bit * bit * bit;
    int s = s1 + s2 + s3;
    if (n == s) {
        return true;
    }
    return false;
}

// 使用math函数
bool IsNarcissisticNumber2(int n)
{
    if (n < 100 || n > 999) { // 不是三位数
        return false;
    }
    // 分解它的百位 十位 个位
    int hundred = n / 100;
    int ten = (n - hundred * 100) / 10;
    int bit = n % 10;
    double s = pow(hundred, 3) + pow(ten, 3) + pow(bit, 3);
    if (fabs(s - n) < 1e-8) {
        return true;
    }
    return false;
}


int main()
{
    IsNarcissisticNumber f1, f2;
    f1 = IsNarcissisticNumber1;
    f2 = IsNarcissisticNumber2;
    int i;
    for (i = 0; i < 1000; i++) {
        if (f1(i)) {
            printf("%3d\t", i);
        }
    }
    putchar('\n');
    for (i = 0; i < 1000; i++) {
        if (f2(i)) {
            printf("%3d\t", i);
        }
    }
    return 0;
}
