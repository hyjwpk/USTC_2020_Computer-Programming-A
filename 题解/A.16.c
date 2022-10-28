#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 3

typedef struct {
	int start_hour[21];
    int start_minute[21];
    int end_hour[21];
    int end_minute[21];
} arrange;

void random(arrange *a,int count,int c);

int main()
{
    srand((unsigned int)(time(NULL)));
    arrange city;
    arrange *a=&city;
    printf("出发 城市   到达 城市   出发 时间   到达 时间\n");
    for(int i=1;i<=N*(N-1)/2;i++)
    {
        random(a,rand()%7+4,i);
    }
    
    
}

void random(arrange *a,int count,int c)
{
    char start,end;
    int temp=c;
    for(int k=N-1;k>=1;k--)/*通过顺序判断起点终点*/
    {   
        temp-=k;
        if(temp<=0)
        {
            temp+=k;
            start='A'+N-1-k;
            end=start+temp;
            break;
        }

    }
    for(int i=1;i<=count;i++)
    {
        while(1)/*随机生成时间再判断是否满足需求*/
        {
            int flag=1;
            a->start_hour[i]=rand()%24;
            a->start_minute[i]=rand()%61;
            a->end_hour[i]=rand()%24;
            a->end_minute[i]=rand()%61;
            if(a->end_hour[i]*60+a->end_minute[i]<=a->start_hour[i]*60+a->start_minute[i]) flag=0;
            for(int k=1;k<i&&flag==1;k++)
            {
                if(abs((a->end_hour[k]*60+a->end_minute[k]-a->start_hour[k]*60-a->start_minute[k])-(a->end_hour[i]*60+a->end_minute[i]-a->start_hour[i]*60-a->start_minute[i]))>120)
                flag=0;
            }
            if(flag) break;
        }
        printf("    %c           %c        %02d : %02d     %02d : %02d \n",start,end,a->start_hour[i],a->start_minute[i],a->end_hour[i],a->end_minute[i]);
    }
    printf("\n");

}