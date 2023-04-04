#include <stdio.h>

typedef unsigned char *byte_point;

void show_bytes(byte_point pval, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%02x ", pval[i]);
    }
    putchar('\n');
}

unsigned Pcount(unsigned x)
{
    unsigned m = 0;
    while(x) {
        m += x & 0x1;
        x >>= 1;
    }
    return m;
}

int main ()
{
    /*float fval = 1.1F; // float类型看下底层的存储
    show_bytes((byte_point)&fval, sizeof(float));
    double dval = 1.1;
    show_bytes((byte_point)&dval, sizeof(double));

    double dval_f;
    double dval_lf;
    scanf("%f", &dval_f);
    scanf("%lf", &dval_lf);
    show_bytes((byte_point)&dval_f, sizeof(double));
    show_bytes((byte_point)&dval_lf, sizeof(double));
    */
   //printf("\n\n%u", Pcount(8));
   char s = -128;
   char s2 = -s;
   printf("%d\n", (int)s2);

    return 0;
}