/*n皇后问题(非递归)*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#define n 8

int column[n+1],row[n+1],num=0;

int place(int queen,int x)
{
    for(int last=1;last<queen;last++)/*判断是否与之前的皇后冲突*/
    {
        if(queen-last==abs(x-row[last]))
        {
            return 0;
        }
    }
    return 1;
}

void solve(void)
{
    int x=1,k;//当前放置第x个皇后，k为尝试的列数
    while(x>=1)
    {
        for(k=row[x]+1;k<=n;k++)
        {
            if(column[k]==0&&place(x,k))
            {
                column[k]=1;
                row[x]=k;
                break;
            }
        }
        if(k==n+1)
        {
            column[row[x]]=0;
            row[x--]=0;
            column[row[x]]=0;
        }
        else
        {
            if(x==n)
            {
                num++;
                column[row[x]]=0;
                row[x--]=0;
                column[row[x]]=0;
            }
            else
            {
                x++;
            }
        }
    }
}


int main()
{    
    clock_t t = clock();
    solve();
    printf("共有%d种解法\n",num);
    printf("Time: %f ", 1.0 * (clock() - t) / CLOCKS_PER_SEC);
    return  0;
}


