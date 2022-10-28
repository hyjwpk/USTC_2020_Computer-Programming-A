#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSINON 1e-4

typedef struct
{
	int a[4];
	int size;
} stack;

int top(stack *p);/*获得栈顶的符号*/
void pop(stack *p);/*进栈*/
void push(stack *p, int a);/*退栈*/
int empty(stack *p);/*检测栈是否为空*/
int compare(int a);/*优先级比较*/
void calculate(float *a, float b, int c);/*单个计算*/
char transchar(int a);/*字符转换*/
float result(int *sym,const float temp[]);/*计算算式结果*/

int main()
{
	float num[5],expect;
	int sym[4],i,m,p,k;
	printf("请依次输入5个数字:\n");
	scanf("%f %f %f %f %f",&num[0],&num[1],&num[2],&num[3],&num[4]);
	printf("请输入期望结果:\n");
	scanf("%f",&expect);
	for(i=1;i<=4;i++)
		for(m=1;m<=4;m++)
			for(p=1;p<=4;p++)
				for(k=1;k<=4;k++)
				{
					sym[0]=i;
					sym[1]=m;
					sym[2]=p;
					sym[3]=k;
					if(fabsf(result(sym,num)-expect)<EPSINON)
						printf("%f %c %f %c %f %c %f %c %f=%f\n"
						,num[0],transchar(sym[0]),num[1],transchar(sym[1]),num[2],transchar(sym[2]),num[3],transchar(sym[3]),num[4],expect);
				}	
	getchar();
	getchar();				
	return 0;
}

int top(stack *p)
{	
	if (p->size == 0) return 0;
	else return p->a[p->size - 1];
}
void pop(stack *p)
{
	if (p->size != 0) --(p->size);
}
void push(stack *p, int a)
{
	if (p->size<=3)
	{
		p->a[p->size] = a;
		++p->size;
	}

}
int empty(stack *p)
{
	return p->size == 0;
}
int compare(int a)
{
	switch (a)
	{
	case 0: return 0;
	case 1: return 1;
	case 2: return 1;
	case 3: return 2;
	case 4: return 2;
	}
}
void calculate(float *a, float b, int c)
{
	if (c==1)(*a) += b;
	if (c==2)(*a) -= b;
	if (c==3)(*a) *= b;
	if (c==4)(*a) /= b;
}
char transchar(int a)
{
	switch (a)
	{
	case 1: return '+';
	case 2: return '-';
	case 3:	return '*';
	case 4:	return '/';
	}
}
float result(int *sym,const float temp[])
{
	int i,position = -1;;
	float num[5];
	stack *char_stack = (stack*)malloc(sizeof(stack));
	char_stack->size = 0;
	for(i=0;i<=3;i++)
	{	
		position+=1;
		num[position]=temp[i];
		if (empty(char_stack)) push(char_stack, sym[i]);/*若栈为空存入符号*/
		else/*若栈不为空*/
		{
			while (compare(sym[i])<=compare(top(char_stack)))/*若当前符号优先级不大于栈顶符号*/
			{
				calculate(&num[position - 1], num[position], top(char_stack));
				pop(char_stack);
				--position;
			}
			push(char_stack, sym[i]);
		}
	}
	
	position+=1;
	num[position]=temp[i];
	while (!empty(char_stack))/*全部表达式输入后若栈不空*/
	{
		calculate(&num[position - 1], num[position], top(char_stack));
		pop(char_stack);
		--position;
	}
	return num[0];
}