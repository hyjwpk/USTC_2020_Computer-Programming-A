#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define N 10

void produce(short a[],int b);
int sort(short a[],int b);/*插入排序*/
void insert(short a[],int b,int c);

int main()
{
    short arr[MAX],i;
    srand((unsigned int)(time(NULL)));
    for(i=0;i<=N;i++)
    {
        produce(arr,i);/*在short型范围内生成数字*/
        if(i!=0) insert(arr,sort(arr,i),i);
    }
    for(i=0;i<=N;i++)
    {
        printf("%d ",arr[i]);
    }
}

void produce(short a[],int b)
{
    a[b]=(int)((double)rand() / RAND_MAX * 65536)-32768;
}

int sort(short a[],int b)
{
    int i;
    if(a[b]<a[0]) return 0; 
    for(i=0;i<b;i++)
    {
        if(a[b]>=a[i]&&a[b]<=a[i+1]) return i+1;
    }
    return b;
}

void insert(short a[],int b,int c)/*插入*/
{
    int temp=a[c];
    int i;
    for(i=c;i>b;i--)
    {
        a[i]=a[i-1];
    }
    a[b]=temp;
}
