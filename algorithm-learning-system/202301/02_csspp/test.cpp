#include "stdlib.h"
#include "stdio.h"

void print(int a)
{
    return;
}

int bit1_count(int a)
{
    if (a == 0) {
        return 0;
    }
    return (a & 1) + bit1_count(a >> 1);
}

int main()
{
    int a[2][3] = {1, 6, 3, 5, 9, 3};
    int (*pa1)[3] = a;;
   for(int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", (*(*(pa1 + i) + j)));
    }
   }
   printf("\n\n%d %d", sizeof(*pa1), sizeof(a));
   printf("\n%x %x %x %x", pa1, &pa1,*pa1, a);
    int b[3] = {1 , 2, 3};
    int (*p)[3] = &b;
    char* (*pc)[3];
    for (int j = 0; j < 3; j++) {
        printf("  %d ", p[0][j]);
    }
    int v[9][2] = {0};
    print(**v);
    putchar('\n');
    for (int m = 0; m < 16; m ++) {
        printf("%d:%d\n", m, bit1_count(m));
    }
    return 0;
}