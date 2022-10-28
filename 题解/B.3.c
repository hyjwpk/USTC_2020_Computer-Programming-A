#include <stdio.h>
#include <string.h>

int mod(int a,int b,int c);

int main()
{
    char a[32768]={0};
    int i,result=0,r;
    a[0]='1';
    scanf("%s",&a[1]);
    scanf("%d",&r);
    a[0]=strlen(a)-1+'0';
    for(i=1;i<=strlen(a)-1;i++)/*逐位读取,每读一个数取一次模*/
    {
        result=mod(result,(int)(a[i]-'0'),r);
    }
    printf("%d\n",result);
    if(!result) printf("能整除");
    else printf("不能整除");
    return 0;
}

int mod(int a,int b,int c)
{
    if(b==1)
    {
        return (a*2+1)%c;
    }
    else
    {
        return (a*2)%c;
    }
    
}