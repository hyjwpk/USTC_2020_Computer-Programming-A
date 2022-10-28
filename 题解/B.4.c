#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void print(char a[][10]);/*输出当前状态*/
void direct(char a[][10],int *i,int *p);/*生成随机方向*/
int fault(char a[][10],int i,int p);/*判断是否失败*/
int keyboard();/*键盘输入检测*/

int main(void)
{
    char dot[10][10];
    int i_1,p_1,i_2,p_2,k;

    for(i_1=0;i_1<=9;i_1++)/*初始化*/
        for(p_1=0;p_1<=9;p_1++)
            dot[i_1][p_1]='.';
    scanf("%d %d",&i_1,&p_1);
    scanf("%d %d",&i_2,&p_2);
    dot[i_1][p_1]='A';
    dot[i_2][p_2]='a';
    system("cls");/*清屏*/
    print(dot);
    k=1;

    do
    {   
        if(k==26) k=0;/*走到Z重新从A开始*/

        printf("player1:");
        direct(dot,&i_1,&p_1);
        dot[i_1][p_1]='A'+k;
        system("cls");
        print(dot);
        if(fault(dot,i_1,p_1)==1) 
        {
            printf("player2win\n");
            break;
        }

        printf("player2:");
        direct(dot,&i_2,&p_2);
        dot[i_2][p_2]='a'+k;
        system("cls");
        print(dot);
        if(fault(dot,i_2,p_2)==1) 
        {
            printf("player1win\n");
            break;
        }

        k++;
    }while(1);

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
    switch (keyboard())
	{
	case 1: 
        if(*i-1>=0&&a[*i-1][*p]=='.')
        {
            *i-=1;
        }
        else 
        {
            printf("fault\n");
            direct(a,i,p);
        }
        break;
	case 2: 
        if(*i+1<=9&&a[*i+1][*p]=='.')
        {
            *i+=1;
        }
        else 
        {
            printf("fault\n");
            direct(a,i,p);
        }
        break;
	case 3: 
        if(*p-1>=0&&a[*i][*p-1]=='.')
        {
            *p-=1;
        }
        else 
        {
            printf("fault\n");
            direct(a,i,p);
        }
        break;
	case 4: 
        if(*p+1<=9&&a[*i][*p+1]=='.')
        {
            *p+=1;
        }
        else 
        {
            printf("fault\n");
            direct(a,i,p);
        }
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

int keyboard()
{
    int key1,key2; 
    do
    {
        key1 =_getch();
		key2 =_getch();
		if(key1 ==0)
		{
			switch(key2)
			{
			case 72:
				return 1;/*up*/
				break;
			case 75:
				return 3;/*left*/
				break;
			case 77:
				return 4;/*right*/
				break;
			case 80:
				return 2;/*down*/
				break;
			}	
		}
    }while(1);
}