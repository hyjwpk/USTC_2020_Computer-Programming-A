#include <stdio.h>
#include <math.h>

int prime(int p)  /*判断某个数是否是质数*/
{
    int i;
    for( i = 2; i <=sqrt(p); i++)
        if( p % i == 0) return 0;
    return 1;
}

int member(int a,int p[])  /*判断某个数是否是已知的质数*/
{
    int i;
    for(i=0;i<=167;i++)
        if(p[i]==a) return 1;
    return 0;
}

int main(void)
{
    int n, m = 2, flag;
    int p[168];  /*存放1000以内的质数*/
    for(n=0;n<=167;++n)  /*将1000以内的质数存放到数组*/
        for(;m<=1000;m++)
            if(prime(m)==1) 
            {
                p[n] = m;
                m++;
                break;
            }

    for(m=6;m<=1000;m+=2)  /*判断6至1000的偶数能否表示为两个素数之和*/
    {
        flag = 0;
        for(n=0;p[n]<=m/2;++n)
            if(member(m-p[n],p)==1)
            {
                printf("%d=%d+%d\n",m,p[n],m-p[n]);
                flag = 1;
                break;
            }
        if(flag==0) break;
    }
    getchar();
    return 0;
}