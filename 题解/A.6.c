#include <stdio.h>
#define blank "     "

int present_year_sum(int y,int m)/*计算当前年份的天数总和*/
{   
    int x,n;
    n=0;
    x = ((y%400==0)||(y%4==0&&y%100!=0))?29:28;  /* 判断是否为闰年 */

    switch (m)
    {
        case    12:n += 30;  /* 十一月 */
        case    11:n += 31;  /* 十月 */
        case    10:n += 30;  /* 九月 */
        case    9:n  += 31;  /* 八月 */
        case    8:n  += 31;  /* 七月 */
        case    7:n  += 30;  /* 六月 */
        case    6:n  += 31;  /* 五月 */
        case    5:n  += 30;  /* 四月 */
        case    4:n  += 31;  /* 三月 */
        case    3:n  += x;   /* 二月 */
        case    2:n  += 31;  /* 一月 */
        default:n    += 1;   /* 当前月 */
    }
    /* 从某一个case进入，中间没有设置break，而是一直进行到switch语句末尾依次加上各个月份的日期 */

    return n;
}

int previous_day_sum(int y,int m)/* 计算从1600年1月1日到当前日期天数总和 */
{
    int i = 0,sum=0;

    for(i=1600;i<y;i++)
    {
        if((i%400==0)||(i%4==0&&i%100!=0)) sum += 366;
        else sum += 365;
    }

    sum += present_year_sum(y,m);
    return sum;
}

int mounth_day(int y,int m)/*判断当前月份的天数*/
{
    switch (m)
    {
        case 12: return 31;                                       /* 十一月 */
        case 11: return 30;                                       /* 十一月 */
        case 10: return 31;                                       /* 十月 */
        case 9 : return 30;                                       /* 九月 */
        case 8 : return 31;                                       /* 八月 */
        case 7 : return 31;                                       /* 七月 */
        case 6 : return 30;                                       /* 六月 */
        case 5 : return 31;                                       /* 五月 */
        case 4 : return 30;                                       /* 四月 */
        case 3 : return 31;                                       /* 三月 */
        case 2 : return ((y%400==0)||(y%4==0&&y%100!=0))?29: 28;  /* 二月 */
        case 1 : return 31;                                       /* 一月 */
    }  
}

int print(int weekday,int d)/*格式化输出*/
{
    int m,num=weekday;
    if(weekday==0) num = 7;

    printf("Sun%sMon%sTur%sWed%sThu%sFri%sSat\n",blank,blank,blank,blank,blank,blank);
    for(m=1;m<=num-1;m++) printf("   %s",blank);/*输出前导空格*/
    for(m=1;m<=d;m++)
    {
        printf("%2d ",m);
        if((m+weekday-1)%7==0) printf("\n");
        else printf("%s",blank);
    }
}

int main(void)
{
    int y,m;
    scanf ("%d-%d",&y,&m);  /* 输入年-月*/
    if(y<1600) return -1;
    print(((previous_day_sum(y,m)+6)% 7),mounth_day(y,m));
    getchar();
    getchar();
    return 0;
}