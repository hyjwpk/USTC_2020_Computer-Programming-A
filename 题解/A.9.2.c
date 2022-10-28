#include <stdio.h>
/*尼克切丝定理：任何一个整数(a)的立方都可以表示为一串(a个)连续奇数之和*/
int main(void)
{
    int x,a,k,max;
    printf("请输入检测的整数的上限:");
    scanf("%d",&max);
    for(x=1;x<=max;x++)
    {
        a=x*x-x+1;
        printf("%d^3=%d",x,a);
        for(k=1;k<=x-1;k++)
        {
            printf("+%d",a+2*k);
        }
        printf("\n");
    }
    return 0;
}