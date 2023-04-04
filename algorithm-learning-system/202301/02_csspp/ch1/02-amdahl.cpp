// 02 - Amdahl.cpp 阿姆达尔定律

/*
    当我们对系统的某个部分加速的时候，对系统的整体影响取决于该部分的重要程度和加速速度
    阿姆达尔定律公式： T old:系统原始用时，T new：改进后系统用时，α：系统某部分用时占比，k:系统该部分的加速指数
    系统加速比  S = T old / T new = 1/((1-α) + α / k)
*/

#include <stdio.h>
#include <math.h>
#define TEST_MODE 0

#define EPS 1e-6

int main()
{
    double arf = 0;
    double k = 0;
    double s = 0;
    printf("请输入系统该部分的时间占用比例arf（0-1，如0.3）：");
    scanf("%lf", &arf);
    if (arf > 1 || arf < 0) {
        printf("ERROR ARF!\n");
        return 0;
    }
    printf("请输入系统该部分的加速指数k：");
    scanf("%lf", &k);
    s = 1 / ((1 - arf) + (arf / k));
    printf("系统的整体加速指数为：%.2f\n", s);
#if TEST_MODE
    printf("加速指数探究：arf(0.1 - 0.9), k(2-20):\n\n");
    for (double i = 0.1; fabs(i - 0.9) > EPS; i += 0.1) {
        for (double j = 2; fabs(j - 20) > EPS; j += 2) {
            s = 1 / ((1 - i) + (i / j));
            printf("arf:%f, k:%f, s:%f\n", i, j, s);
        }
    }
#endif
    return 0;
}