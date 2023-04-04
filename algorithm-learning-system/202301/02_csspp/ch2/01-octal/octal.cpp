// ch2 -1 N进制打印，将N进制K次方以内的数按照N进制码打印出来，如 十进制二次方形式 15:15  十六进制二次方形式 15：0f

#include <stdio.h>
#include <math.h>
#include "octal.h"

#define OCTAL               (2)                   // N进制的N值
#define K                   (4)                   // N进制的K次方以内的数，K值
#define MAX_HIGH_BIT        (K - 1)

CodeArray g_codeArray = NULL;

OctalCodeList g_octalCodeList[MAX_OCTAL_TYPE] = {
    {BINARY, BinCode},
    {DECIMAL, DecCode},
    {HEX, HexCode},
};

void OctalModeInit()
{
    int octalN = OCTAL;
    for (int i = 0; i < sizeof(g_octalCodeList) / sizeof(OctalCodeList); i++) {
        if (g_octalCodeList[i].octal == octalN) {
            g_codeArray = g_octalCodeList[i].codeArray;
        }
    }
}

void OctalPrintByteBit(int nums)                    // N进制K次方以内的数字打印
{
    if (nums < 0 || nums > (int)pow(OCTAL, K)) {
        return;
    }
    if (g_codeArray == NULL) {
        return;
    }

    int i = (int)pow(OCTAL, MAX_HIGH_BIT);
    while (i) {
        int index = nums / i;
        printf("%c", g_codeArray[index]);
        nums %= i;
        i /= OCTAL;
    }
    return;
}

void OctalPrintNums()
{
    for (int i = 0; i < (int)pow(OCTAL, K); i++) {
        printf("%-3d: ", i);
        OctalPrintByteBit(i);
        putchar('\n');
    }
}

int main()
{
    OctalModeInit();
    OctalPrintNums();
    return 0;
}