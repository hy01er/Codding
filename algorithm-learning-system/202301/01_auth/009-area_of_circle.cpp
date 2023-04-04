// 9.求圆的面积，这里主要是用一下math.h里面的数学Func，以及一些浮点数的知识

#include "stdio.h"
#include "math.h"

#define PAI 3.14

// double power (double x, double y)
// 用于计算x的y次幂，参数和返回值都是double类型

double GetCircleArea(double r)
{
    return PAI * (pow(r, 2));
}

int main()
{
    double r = 0;
    printf("请输入圆的半径:");
    scanf("%lf", &r); // 注意scanf的double格式化输入符是%lf,参数要加取地址符
    printf("面积为：%.2f\n", GetCircleArea(r));
    return 0;
}
