// ch2 show_bytes

#include "stdio.h"
#include "string.h"
#include "stdint.h"

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for(i = 0; i < len; i++) {
        printf("%02x ", start[i]);
    }
    putchar('\n');
    return;
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main ()
{
    test_show_bytes(12345); // ��ʾint, float, int *���ڴ�Ķ�����λ��ע�⵱ǰ������С��ģʽ
    putchar('\n');
    printf("size-int:%d\n", sizeof(int));
    printf("sizeof-long:%d\n", sizeof(long));
    printf("sizeof-long long:%d\n", sizeof(long long));
    printf("sizeof-*:%d\n", sizeof(void *));         // �������õ���64λCPU��ϵͳ���Լ�64λGCC������ָ����8�ֽڵ�
    putchar('\n');

    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    putchar('\n');

    char const *p = "hello world";
    show_bytes((byte_pointer)p, strlen(p));
    putchar('\n');

    // ����һ�µ��޷��������з�����������һ�µ�
    short val2 = 12345;
    short val3 = -val2;
    unsigned short val4 = val3;
    show_bytes((byte_pointer)&val2, sizeof(short));
    show_bytes((byte_pointer)&val3, sizeof(short));
    show_bytes((byte_pointer)&val4, sizeof(unsigned short)); // ��61�е�short��unsigned short���ڴ�������ͬ���λģʽ
    putchar('\n');

    short v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n\n", v, uv);

    int c = -1;
    unsigned int uc = 2147483648; // 2 to the 31st ��31λ��1������λ��0
    printf("c = %u = %d\n", c, c);
    show_bytes((byte_pointer)&c, sizeof(int));
    printf("uc = %u = %d\n", uc, uc);
    show_bytes((byte_pointer)&uc, sizeof(unsigned));
    
    return 0;
}