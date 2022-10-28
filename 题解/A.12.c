#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(char a[][10]);/*输出当前状态*/
void direct(char a[][10],int *i,int *p);/*生成随机方向*/
int fault(char a[][10],int i,int p);/*判断是否失败*/

int main(void)
{
    char dot[10][10];
    int i,p,k,flag=1;

    for(i=0;i<=9;i++)/*初始化*/
        for(p=0;p<=9;p++)
            dot[i][p]='.';
    srand((unsigned)time(NULL)); 
    scanf("%d %d",&i,&p);
    dot[i][p]='A';
    
    for(k=1;k<=25;k++)
    {   
        if(fault(dot,i,p)==1) 
        {
            flag=0;
            break;
        }
        direct(dot,&i,&p);
        dot[i][p]='B'+k-1;
    }
    print(dot);
    if(flag==0) printf("fault");
    else printf("win");
    return 0;
}

void print(char a[][10])
{
    int i,p;
    for(i=0;i<=9;i++)
    {
        for(p=0;p<=9;p++)
        {
            printf("%c ",a[i][p]);
        }
        printf("\n");
    }
}

void direct(char a[][10],int *i,int *p)
{
    int random;
    random=rand()%4+1;/*生成随机方向*/
    switch (random)
	{
	case 1: 
        if(*i-1>=0&&a[*i-1][*p]=='.')
        {
            *i-=1;
        }
        else direct(a,i,p);
        break;
	case 2: 
        if(*i+1<=9&&a[*i+1][*p]=='.')
        {
            *i+=1;
        }
        else direct(a,i,p);
        break;
	case 3: 
        if(*p-1>=0&&a[*i][*p-1]=='.')
        {
            *p-=1;
        }
        else direct(a,i,p);
        break;
	case 4: 
        if(*p+1<=9&&a[*i][*p+1]=='.')
        {
            *p+=1;
        }
        else direct(a,i,p);
        break;
	}
}

int fault(char a[][10],int i,int p)
{
    if(i-1>=0&&a[i-1][p]=='.')
    {
        return 0;
    }
    if(i+1<=9&&a[i+1][p]=='.')
    {
        return 0;
    }
    if(p-1>=0&&a[i][p-1]=='.')
    {
        return 0;
    }
    if(p+1<=9&&a[i][p+1]=='.')
    {
        return 0;
    }
    return 1;
}