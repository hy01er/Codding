// 14 bmi身体质量指数，是BMI（Body Mass Index [4]  ）指数，简称体质指数，是国际上常用的衡量人体胖瘦程度以及是否健康的一个标准。
// 计算公式为：BMI=体重÷身高^2。（体重单位：千克；身高单位：米。）s

#include "stdio.h"
#include "math.h"

#define BEST_BMI 20
#define BEST_WEIGHT_RANGE 2

int main()
{
    double height = 0; // 身高
    double weight = 0; // 体重
    printf("请输入体重和身高（空格间隔，体重kg 身高 m）:");
    scanf("%lf %lf", &weight, &height);
    double bmi = weight / pow(height, 2.0);
    printf("你的BMI为：%.2f\n", bmi);
    double bestWeight = BEST_BMI * pow(height, 2.0);
    printf("你的最佳体重为：%.2f\n", bestWeight);
    if (fabs(bestWeight - weight) < BEST_WEIGHT_RANGE) {
        printf("你的身体体型：正常,且处于最佳体重，继续保持！");
    } else if (bestWeight > weight) {
        printf("你的身体体型：偏瘦,您需要增加体重%.2fKg", bestWeight - weight);
    } else if (bestWeight < weight) {
        if (bmi > 25 && bmi < 30) {
            printf("你的身体体型：偏胖");
        }
        if (bmi > 30) {
            printf("你的身体体型：超重");
        }
        printf("您需要减轻体重%.2fKg, 也就是%.2f斤!", weight - bestWeight, 2 * (weight - bestWeight));
    } else {
        printf("你的身体体型：未知");
    }
    putchar('\n');
    return 0;
}
