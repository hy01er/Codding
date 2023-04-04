// 15.猜数
#include "stdio.h"
#include "stdlib.h"

int main()
{
    int magic, guess, counter = 0;
    unsigned int seed;
    printf("please enter seed:");
    scanf("%u", &seed);
    srand(seed);
    magic = rand() % 100 + 1;

    do {
        printf("Please guess a number(1 <= num <= 100 ):");
        scanf("%d", &guess);
        counter++;
        if (guess > magic) {
            printf("Wrong!Too big!\n");
        } else if (guess < magic) {
            printf("Wrong!Too small!!\n");
        } else {
            printf("Right\n");
        }
    } while(guess != magic);
    printf("counter = %d", counter);
    return 0;
}
