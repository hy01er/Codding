// 19.判断三角形

#include "stdio.h"
#include "math.h"

#define EPS 1e-1

int main19()
{
    double a, b, c;
    int flag = 0;
    printf("请输入三角形的三边长度，用空格间隔：");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a + b < c || b + c < a || a + c < b) {
        printf("不是三角形\n");
        return 0;
    }
    if (fabs(a - b) <= EPS && fabs(b - c) < EPS && fabs(c - a) < EPS) {
        printf("等边");
        flag = 1;
    } else if(fabs(a - b) <= EPS || fabs(b - c) <= EPS || fabs(c - a) <= EPS) {
        printf("等腰");
        flag = 1;
    }
    if (fabs(a * a + b * b - c * c) <= EPS ||
        fabs(b * b + c * c - a * a) <= EPS ||
        fabs(c * c + a * a - b * b) <= EPS) {
        printf("直角");
        flag = 1;
    }
    if (!flag) {
        printf("一般");
    }
    printf("三角形\n");
    return 0;
}
