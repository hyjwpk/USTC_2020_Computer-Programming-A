//迷宫密码
#include <stdio.h>

int m,n;
int sigma(int a[m+1][n+1],int p[]);

int main()
{
	int max=0;
	int position[4];//存储最大情况的坐标
	int current;
	scanf("%d %d",&m,&n);
	int a[m+1][n+1];
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=n;k++)
		{
			scanf("%d",&a[i][k]);
		}
	}
	//遍历
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int c=i;c<=m;c++)
			{
				for(int q=k;q<=n;q++)
				{
					int p[]={i,k,c,q};
					current=sigma(a,p);
					if(current>max)
					{
						max=current;
						position[0]=p[0];
						position[1]=p[1];
						position[2]=p[2];
						position[3]=p[3];
					}
				}
			}
		}
	}
	printf("(%d,%d) (%d,%d)\n %d ",position[0],position[1],position[2],position[3],max);
	return 0;
}

int sigma(int a[][n+1],int p[])
{
	int sum=0;
	for(int i=p[0];i<=p[2];i++)
	{
		for(int k=p[1];k<=p[3];k++)
		{
			sum+=a[i][k];
		}
	}
	return sum;
}


/*
**样例
5 4
-1 -2 -3 -4
-3 -2 2 4
-3 -4 3 5
4 -5 3 6
-3 -2 -1 0
**
*/