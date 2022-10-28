#include<stdio.h>
#define num 3 /*总共的情侣对数*/

void rid(int row,int column,int c[num][num])/*排除法划掉不可能的关系*/
{
    int i;
    for(i=0;i<=num-1;i++)
    {
        c[row][i]=1;
    }
    for(i=0;i<=num;i++)
    {
        c[i][column]=1;
    }
    c[row][column]=2;
}

int detect_row(int row,int c[num][num]) /*横行检测*/
{
    int i;
    int flag=0;
    int n;
    for(i=0;i<=num-1;i++)
    {
        if(c[row][i]==1) flag++;
        if(c[row][i]!=1) n=i;
    }
    if(flag==num-1) 
    {
        if(c[row][n]!=2) 
        {
            rid(row,n,c);
            return 1;
        }
        
    }
    return 0;
}

int detect_column(int column,int c[num][num]) /*纵行检测*/
{
    int i;
    int flag=0;
    int n;
    for(i=0;i<=num-1;i++)
    {
        if(c[i][column]==1) flag++;
        if(c[i][column]!=1) n=i;
    }
    if(flag==num-1) 
    {
        if(c[n][column]!=2) 
        {
            rid(n,column,c);
            return 1;
        }
        
    }
    return 0;
}

int main(void)
{
    int i,m;
    int a,b,relevant;
    int c[num][num]={0};
    printf("请输入已知的关系数目:\n");
    scanf("%d",&m);
    printf("请按[人物a](0代表X,1代表Y,2代表Z以此类推) [人物b](0代表A,1代表B,2代表C以此类推) [关系](1代表两人不为情侣,2代表两人为情侣)输入\n例如:0 0 1代表X与A不是情侣\n");
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&relevant);
        c[a][b]=relevant;
    }

    do/*检测每一横行与每一竖行能否推出未知信息*/
    {
        for(i=0;i<=num-1;i++)
        {
            if(detect_row(i,c)==1) i=0;
        }
        
        for(m=0;m<=num-1;m++)
        {
            if(detect_column(m,c)==1)
            {
                m=0;
                i=0;
            } 
        }
    } while (i!=num);
    
    for(i=0;i<=num-1;i++)
    {
        for(m=0;m<=num-1;m++)
        {
            if(c[i][m]==2) 
            {
                printf("%c与%c是情侣\n",'X'+i,'A'+m);
                break;
            }
        }
    }
    return 0;
}