//取胜之道
#include <stdio.h>

int player[2];

int max(int a,int b)
{
    return a>b?a:b;
}

int point(int num[],int *a,int *b,int turn)
{
    int sum=0;//sum为当前剩余数字的总和
    int best;
    if(b==a) return 0;//两指针相遇,则下一轮无数可取,最劣情况为0
    //每一个问题可以分为第一次取最开始和最末尾两种,取了开始或末尾的一个后,轮到另一人取数,再加上对另一个人最优,对当前这个人最劣情况
    int condition1=*a+point(num,a+1,b,0);
    int condition2=*b+point(num,a,b-1,0);
    for(int *i=a;i<=b;i++)
    {
        sum+=*i;
    }
    best=max(condition1,condition2);//存储最优的情况
    if(turn) //只有第一次turn为1
    {
        player[0]=best;
        player[1]=sum-best;
    }
    else //最劣情况=总和-最优情况
        return sum-best;
    return 0;
}

int main()
{
    int n;//n为数的个数
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    point(num,&num[0],&num[n-1],1); 
    printf("%d %d",player[0],player[1]);
}