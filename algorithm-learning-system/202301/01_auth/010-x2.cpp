// 10 一元二次方程的解，这个是学校经典考题，期末考试经典题目

#include "stdio.h"
#include "math.h"

// 一元二次方程 ax^2 + bx + c = 0
// 求根公式为：x = (-b +-(b^2 - 4 * a *c)^(1/2)) / 2a
// 根的判别式 disc = b^2 - 4 * a *c,当判别式> 0时，方程有两个不相等的实数根；当判别式 = 0，方程有两个相等的实数根，
// 当判别式 < 0时，方程无实数解

int main()
{
    double a, b, c;
    double disc = 0; // 根的判别式
    double res = 0;
    double res1 = 0, res2 = 0;
    printf("请输入a,b,c（请用空格间隔）:");
    scanf("%lf %lf %lf", &a, &b, &c);
    disc = b * b  - 4 * a * c;

    if (disc < -(1e-8)) { // 这里要注意
        printf("方程无实数解。\n");
        return 0;
    } else if (fabs(disc - 0) < 1e-8) {
        res = -b / (2 * a);
        printf("x1 = x2 = %.2f\n", res);
    } else if (disc > 1e-8) {
        res1 = (-b + sqrt(disc)) / (2 * a);
        res2 = (-b - sqrt(disc)) / (2 * a);
        printf("x1 = %.2f, x2 = %.2f\n", res1, res2);
    } else {
        printf("EOOOR CASE!\n");
    }
    return 0;
}
