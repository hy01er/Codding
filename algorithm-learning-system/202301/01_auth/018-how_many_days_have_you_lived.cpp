// 18.计算你活了多少天，程序需要输入你的生日，然后自动计算出你出生到现在经过了多少天

/*
 这里要用到time.h头文件提供的接口获取当前的年月日

 普通闰年：公历年份是4的倍数，且不是100的倍数的，为闰年（如2004年、2020年等就是闰年）。
 世纪闰年：公历年份是整百数的，必须是400的倍数才是闰年（如1900年不是闰年，2000年是闰年）。
*/

#include "stdio.h"
#include "time.h"

int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int flat[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date;
typedef struct date Date;
typedef Date *PtrDate;

typedef struct date{
    int year;
    int month;
    int day;
};

// 闰年判断
bool IsLeap(int year)
{
    if (year <= 0) {
        return false;
    }
    if (year % 400 ==0 || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    }
    return false;
}

// 获取某一年活的天数,返回值返回，分4中情况，分别用if-else if-else if -else划分
// (1) 出生年和当前年一致，求当年活的天数，需要单独计算
// (2) 出生年和当前年不一致，求出生年的天数
// (3) 出生年和当前年不一致，求当前年的天数
// (4) 出生年和当前年不一致，求中间年的天数
int GetYearLiveDays(int year, Date birth, Date current)
{
    int month;
    int days = 0;
    bool IsLeapYear = IsLeap(year);
    int *list = (IsLeapYear ? leap : flat);
    if (birth.year == current.year && year == current.year) { // 情况一
        int daysBirth = 0;
        int daysCurr = 0;
        month = 0;
        while(month < birth.month) {
            daysBirth += list[month];
            month++;
        }
        daysBirth += birth.day;
        month = 0;
        while(month < current.month) {
            daysCurr += list[month];
            month++;
        }
        daysCurr += current.day;
        days = daysCurr - daysBirth;
    } else if (year == birth.year) { // 情况二
        //printf("\n=1\n");
        month = birth.month;
        days += list[month] - birth.day;
        while(month + 1 < 12) {
            month++;
            days += list[month];
        }
    } else if (year == current.year) { // 情况三
        //printf("\n=2\n");
        days += current.day;
        month = 0;
        while(month < current.month) {
            days += list[month];
            month++;
        }
    } else {                            // 情况四
        //printf("\n=3\n");
        days += (IsLeapYear ? 366 : 365);
    }
    return days;
}

/* input:yours birthday year,month,day
   output:how many days have you lived
*/
int GetLiveDays(Date birth, Date current)
{
    int liveDays = 0;
    for (int i = birth.year; i <= current.year; i++) {
        //printf("Get-%d-days:", i);
        int iDays = GetYearLiveDays(i, birth, current);
        liveDays += iDays;
        //printf("+%d\n", iDays);
    }
    return liveDays;
}


int main()
{
    time_t t;
    struct tm *st;
    char *ch;
    time(&t);
    printf("time:%ld\n", t);

    ch = ctime(&t);
    printf("ctime:%s\n", ch);

    st = localtime(&t);
    Date current = {st->tm_year + 1900, st->tm_mon, st->tm_mday};
    printf("当前：year-month-day:%d-%d-%d\n\n", current.year, current.month + 1, current.day);

    Date birth;
    printf("请输入你的出生年月日，用空格间隔:");
    scanf("%d %d %d", &birth.year, &birth.month, &birth.day);
    birth.month -=1;
    printf("你的生日是：year-month-day:%d-%d-%d\n\n", birth.year, birth.month + 1, birth.day);
    printf("你一共活了%d天", GetLiveDays(birth, current));
    return 0;
}
