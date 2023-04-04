// 1.冒泡排序并输出

#include "stdio.h"

#define ARRAR_LENGTH_MAX 6
typedef void (*PrintArray)(int *, int);
typedef void (*sortFunc)(int *, int);

void PrintIntArray(int arr[], int length)
{
    if (arr == NULL || length <= 0) {
        printf("ERROR, param invalid!");
        return;
    }
    for (int i = 0; i < length; i++) {
        printf("%d\t", arr[i]);
    }
    putchar('\n');
    return;
}

static void TwoIntExchange(int *num1, int *num2)
{
    if (num1 == NULL || num2 == NULL) {
        printf("ERROR, param invalid!");
        return;
    }
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return;
}

void BubbleSort(int *arr, int length)
{
    if (arr == NULL || length <= 0) {
        printf("ERROR, param invalid!!");
        return;
    }
    for (int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                TwoIntExchange(&arr[j], &arr[j + 1]);
            }
        }
    }
    return;
}

int main()
{
    int arr[ARRAR_LENGTH_MAX] = {56, 90, -9, 52, 80, 20};
    PrintArray print1 = PrintIntArray;
    sortFunc maopao = BubbleSort;
    printf("冒泡排序前：\n");
    print1(arr, ARRAR_LENGTH_MAX);
    printf("冒泡排序后：\n");
    maopao(arr, ARRAR_LENGTH_MAX);
    print1(arr, ARRAR_LENGTH_MAX);
}
