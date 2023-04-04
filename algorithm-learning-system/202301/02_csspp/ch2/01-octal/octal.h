// 进制打印头文件

#ifndef _OCTAL_H_
#define _OCTAL_H_

#define MAX_OCTAL_TYPE  10

typedef char *CodeArray;

typedef enum Octal {
    BINARY = 2,
    DECIMAL = 10,
    HEX = 16
} Octal;

typedef struct {
    Octal octal;
    CodeArray codeArray;
} OctalCodeList;

typedef enum CodeNums {
    BINARY_CODE_NUMS = 2,                         // 二进制的数码： 0  1
    DECIMAL_CODE_NUMS = 10,                       // 二进制的数码： 0  1  2  3  4  5  6  7  8  9
    HEX_CODE_NUMS = 16                            // 十六进制数码： 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
} CodeNums;

char BinCode[BINARY_CODE_NUMS] = {'0', '1'};
char DecCode[DECIMAL_CODE_NUMS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char HexCode[HEX_CODE_NUMS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

#endif