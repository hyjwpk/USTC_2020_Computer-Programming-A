/*n皇后问题*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#define n 8

int column[n+1],row[n+1],num=0;
void solve(int queen);

int main()
{    
    clock_t t = clock();
    solve(1);
    printf("共有%d种解法\n",num);
    printf("Time: %f ", 1.0 * (clock() - t) / CLOCKS_PER_SEC);
    return  0;
}

void  solve(int queen)
{

    for(int x=1;x<=n;x++)
    {
        if(column[x]==0)/*如果当前列未放置*/
        {
            int flag=1;/*标志是否可行*/
            for(int last=1;last<queen;last++)/*判断是否与之前的皇后冲突*/
            {
                if(queen-last==abs(x-row[last]))
                {
                    flag=0;
                    break;
                }
        	}
            if(flag)/*如果可行*/
            {
                row[queen] = x;/*存储当前列至当前行*/
                column[x]=1;/*将当前列标志为占用*/
                if(queen==n)/*找到一种解*/
                {
                    num++;
                    /*for(int k=1;k<=n;k++)
                    {
                        printf("%d ",row[k]);
                    }
                    printf("\n");*/
                }
                else solve(queen+1);
                column[x]=0;
            }
        }
    }
}