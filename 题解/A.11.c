/*约瑟夫问题*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,s,m,i=0,death=0,num=0;
    int *life;
    scanf("%d %d %d",&n,&s,&m);
    life=(int*)malloc(sizeof(int)*(n+1));/*存储每个人的状态*/

    for(i=1;i<=n;i++) life[i]=1;
    i=s;

    do
    {
        if(i>n) i=1;
        if(life[i]==1) num++;
        if(num==m)
        {
            printf("%d ",i);
            life[i]=0;
            death++;
            num=0;
            if(death==n-1) printf("\n赦免者是：");
        } 
        i++;
    } while (death!=n);
    
    return 0;
} 