//循环小数
#include <stdio.h>
#include <math.h>

int main()
{
    int p2=0,p5=0,p,temp;//p2,p5为分母中2,5的因子个数
    int a,b,a1;//a1存储a
    scanf("%d %d",&a,&b);
    //分解出2与5的因子个数
    temp=b&(-b);//lowbit
    while((temp=temp>>1)) p2++;
    temp=b;
    while(temp%5==0)
    {
        temp/=5; 
        p5+=1;
    }
    //p为2和5的因子个数中的最大数
    p=p2>p5?p2:p5;
    printf("%d.",a/b);//输出整数部分
    //约去分子分母中的公因数10
    while(p>0&&a%10==0)
    {
        a/=10;
        b/=10;
        p2--;
        p5--;
        p--;
    }
    //输出不循环部分
    for(int i=1;i<=p;i++)
    {
        a*=10;
        //约分
        if(p2>0)
        {
            a/=2;
            b/=2;
            p2--;
        }
        if(p5>0)
        {
            a/=5;
            b/=5;
            p5--;
        }
        printf("%d",(a/b)%10);
    }
    //输出循环节
    temp=a%b;
    a1=a;
    do
    {
        a*=10;
        printf("%d",(a/b)%10);
        a=a%b;
    } while (a!=temp);
    //输出带有括号的循环节
    a=a1;
    printf("(");
    do
    {
        a*=10;
        printf("%d",(a/b)%10);
        a=a%b;
    } while (a!=temp);
    printf(")");
    getchar();
    getchar();
    return 0;
}
