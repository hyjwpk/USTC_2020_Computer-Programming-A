#include <stdio.h>
/*尼克切丝定理：任何一个整数的立方都可以表示为一串连续奇数之和*/
int main(void)
{
    int x,a,n,k,flag,max;
    printf("请输入检测的整数的上限:");
    scanf("%d",&max);
    for(x=2;x<=max;x++)
    {
        flag=0;
        for(a=1;(1+a)*(1+1)<=x*x*x;a+=2)
        {
            for(n=1;(n+a)*(n+1)<=x*x*x;n++)
            {
                if((n+a)*(n+1)==x*x*x)
                {
                    flag=1;
                    printf("%d^3=%d",x,a);
                    for(k=1;k<=n;k++)
                    {
                        printf("+%d",a+2*k);
                    }
                    break;
                }
            }
            if(flag==1) break;
        }
        printf("\n");
        if(flag!=1) break;
    }
    return 0;
}