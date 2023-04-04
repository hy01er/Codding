// 17.九的九次方
/*标题：明码
汉字的字形存在于字库中，即便在今天，16点阵的字库也仍然使用广泛。16点阵的字库把每个汉字看成是16x16个像素信息。并把这些信息记录在字节中。

一个字节可以存储8位信息，用32个字节就可以存一个汉字的字形了。
把每个字节转为2进制表示，1表示墨迹，0表示底色。每行2个字节，
一共16行，布局是：

第1字节，第2字节
第3字节，第4字节
....
第31字节, 第32字节

具体的值已经放在文件9^9.txt中了

这道题目是给你一段多个汉字组成的信息，每个汉字用32个字节表示，这里给出了字节作为有符号整数的值。

题目的要求隐藏在这些信息中。你的任务是复原这些汉字的字形，从中看出题目的要求，并根据要求填写答案。

这段信息是（一共10个汉字）：

注意：需要提交的是一个整数，不要填写任何多余内容。
*/
// 文件读写练习

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

#define ONE_BYTE_BITS_NUM 8

// 将一个十进制数，转换为二进制，用.表示1，用空格表示0，打印出来
// 这里有一个知识点，32位有符号补码转换成32位无符号补码，底层二进制是不变的，只是对它的符号位解释变了
void PrintToByte(int input)
{
    int byte[ONE_BYTE_BITS_NUM] = {0}; // 一个字节有8位，我们用一个8长度的数组来存储每位是0还是1
    memset(byte, 0, ONE_BYTE_BITS_NUM);
    int index = 0;
    unsigned int num = (unsigned int)input;
    while (num != 0 && index != ONE_BYTE_BITS_NUM - 1) {
        byte[index] = num % 2;
        num /= 2;
        index++;
    }
    for (int i = ONE_BYTE_BITS_NUM - 1; i > 0; i--) {
        printf(byte[i] == 1 ? "." : " ");
    }
    return;
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    FILE *fp;
    if ((fp = fopen("9^9.txt", "r")) == NULL) {
        printf("文件不存在...");
        return 0;
    }
    while (!feof(fp)) {
        fscanf(fp, "%d %d", &num1, &num2);
        PrintToByte(num1); // 十进制转换成二进制题目要求的形式打印出来
        PrintToByte(num2);
        printf("\n");
    }
    fclose(fp);
    printf("\n9的9次方等于%.2f\n", pow(9, 9));
    return 0;
}
