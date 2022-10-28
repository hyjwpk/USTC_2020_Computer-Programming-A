#include <stdio.h>
#include <stdlib.h>

int n;
int sum1;
int sum2;

void swap(int a[],int p,int num,int m);//交换函数
void sort(int a[],int p,int m);//排序函数


int main()
{
    int i;//n为元素个数
    scanf("%d",&n);
	int a[n],b[n];
    for(i=0;i<n;i++)
	{
        scanf("%d",&a[i]);
		b[i]=a[i];
    }
	sort(a,0,1);
	sort(b,0,2);
	if(sum1< sum2)//输出小的一种
	{
		printf("%d\n",sum1);
    	for(i=0;i<n;i++)
		{
        	printf("%d ",a[i]);
    	}
	}
	else
	{
		printf("%d\n",sum2);
    	for(i=0;i<n;i++)
		{
        	printf("%d ",b[i]);
    	}
	}
    return 0;
}

void swap(int a[],int p, int num,int m)
{
	int temp;
	temp=a[p];
	a[p]=a[num];
	a[num]=temp;
	if(m==1)
	{
		sum1++;
	}
	else
	{
		sum2++;
	}

	sort(a,p,m);
}

void sort(int a[],int p,int m)//m=1为从小到大，m=2为从大到小
{
	int num=0;
	for(int i=0;i<n;i++)
	{
		if(i==p)
		{
			continue;
		}
		if(m==1&&a[i]<a[p])
		{
			num++;
		}
		if(m==2&&a[i]>a[p])
		{
			num++;
		}
	}
	if(num!=p)
	{
		swap(a,p,num,m);
	}
	if(p<=n-2)
	{
		sort(a,p+1,m);
	}
	else
	{
		return;
	}
}


