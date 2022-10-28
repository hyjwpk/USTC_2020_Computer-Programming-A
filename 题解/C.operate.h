#ifndef _OPERATE_H

#define _OPERATE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define TYPE unsigned int
#define M 11//数组的一个元素存储M位2进制
#define MAXNUMBER 2047
int LENGTH ;
typedef struct BigNumber
{
	int M_number;
	int memory;
	TYPE *arr;
} Num;


void generate(Num *p, int length)//制造检测使用的数组
{
    p->M_number=(int)((length+M-1)/M);
    p->memory=p->M_number*2+1;
    p->arr=(TYPE *)malloc( sizeof(TYPE) * (p->memory+1));//给随机数p分配存储的空间
    memset(p->arr,0,sizeof(TYPE) * (p->memory+1));//初始化
    p->arr[0]=length;//数组的第一个元素存储数组中的二进制位数
    p->arr[1]=733;
    p->arr[2]=1370;
}

void random(Num *p, int length)//产生随机的指定位数大数
{
    int position=1,left=0;
    p->M_number=(int)( (length+M-1)/M );
    p->memory=p->M_number*2+1;
    p->arr=(TYPE *)malloc( sizeof(TYPE) * (p->memory+1));//给随机数p分配存储的空间
    memset(p->arr,0,sizeof(TYPE) * (p->memory+1));//初始化
    p->arr[0]=length;//数组的第一个元素存储数组中的二进制位数
	for (int bit=1; bit<=length; bit++) //循环length次
    {
        
		if (bit==1||bit==length) 
            p->arr[position]+=1<<(left++);//让末位是1，生成一个奇数；让首位是1，保证位数足够
		else 
            p->arr[position]+=(rand()&1)<<(left++);
		if (bit%M==0) //如果达到了单个元素存储上限
        {
                position++;
                left=0;
        }
	}
}

void add(Num *num1,Num *num2)
{
    int position;
    TYPE c=0;
    for(position=1;position<=num1->M_number||position<=num2->M_number;position++)
    {
        if(num2->arr[position]!=0)
            num1->arr[position]+=num2->arr[position];
        else
             break;
    }
    for (position=1; position<=num1->memory; position++) //计算新的M_number
    {
        c+=num1->arr[position];//用c来存储当前position的值
        num1->arr[position]=c&MAXNUMBER;//把范围内的值重新存进当前position
        c>>=M;//把进位的值存进c
        if (num1->arr[position]!=0) num1->M_number=position;//如果当前块不为0,当前长度为i+1
    }
    num1->arr[0]=M*(num1->M_number-1);
    for(int top=num1->arr[num1->M_number];top>0;top>>=1) 
        num1->arr[0]++;
}

int minus(Num *num1,Num *num2)
{
    int position,borrow=0;
    if(num1->arr[0]<num2->arr[0]) return -1;
    else if(num1->arr[0]==num2->arr[0])
	    for (position=num1->M_number;position>=1;position--) //对num1与num2逐位比较
        {
		    if (num1->arr[position]>num2->arr[position]) break;//如果某一位大,那么num1大于2num
		    else if (num1->arr[position]<num2->arr[position]) return -1;//如果某一位小于那么num1小于2num,return结束函数
	    }
	//相减
	for (position=1;position<=num1->M_number;position++) //从低位到高位逐位相减
    {
		if (num1->arr[position]>=num2->arr[position]+borrow) 
        {
			num1->arr[position]-=num2->arr[position]+borrow;
			borrow=0;
		}
		else 
        {
			num1->arr[position]+=MAXNUMBER+1-(num2->arr[position]+borrow);//借位
			borrow=1;
		}
	}
	for (position=num1->M_number;position>=1;position--)//计算新的M_number
		if (num1->arr[position]==0) num1->M_number--;
		else break; 
    num1->arr[0]=M*(num1->M_number-1);
    for(int top=num1->arr[num1->M_number];top>0;top>>=1) 
        num1->arr[0]++; 
    return 1;
}

void randoma(Num *p, int length)//产生millerrabin算法的随机底数a
{
    int position=1,left=0;
    p->M_number=(int)( (length+M-1)/M );
    p->memory=(int)( (LENGTH+M-1)/M )*2+1;
    p->arr=(TYPE *)malloc( sizeof(TYPE) * (p->memory+1));//给随机数p分配存储的空间
    memset(p->arr,0,sizeof(TYPE) * (p->memory+1));//初始化
	for (int bit=1; bit<=length; bit++) //循环length次
    {

        p->arr[position]+=(rand()&1)<<(left++);
		if (bit%M==0) //如果达到了单个元素存储上限
        {
                position++;
                left=0;
        }
	}
    for (position=p->M_number;position>=1; position--)//验证最高位是否为0
    {
        if (p->arr[position]==0)
            p->M_number--;//
        else break;//如果最高位不是0,跳出循环
    }
    if(p->M_number!=0)p->arr[0]=M*(p->M_number-1);
    for(int top=p->arr[p->M_number];top>0;top>>=1) 
        p->arr[0]++;
    if ((p->arr[0]==1 && p->arr[1]<=2)||p->arr[0]==0) //如果a为1或者2,认为这次a的生成失败
    {
        free(p->arr);//释放内存
        randoma(p,length);//重新生成
    }
}

int subtract(Num *num1, Num *p, unsigned long q, int n)//用于实现模运算的减法
{
    int result;
	if (q==0) return(-1);
    Num p_copy;
    p_copy.M_number=p->M_number+n;
    p_copy.memory=p->memory;
    p_copy.arr=(TYPE *)malloc( sizeof(TYPE) * (p->memory+1));
    memset(p_copy.arr,0,sizeof(TYPE) * (p->memory+1));
    int c=0;//c初始化
    for (int position=1; position<=p->M_number; position++) 
    {
        c+=p->arr[position]*q;//用c来存储当前位置的p
        p_copy.arr[position+n]=c&MAXNUMBER;//最多存储M比特位
        c=c>>M;//右移M
        if (p_copy.arr[position+n]!=0) p_copy.M_number=position+n;//如果当前块不为0,当前长度为position+n
    }
	if (c!=0) 
        p_copy.arr[++p_copy.M_number]=c;//循环结束若c不为0,再将c的最后部分加上
    p_copy.arr[0]=M*(p_copy.M_number-1);
    for(int top=p_copy.arr[p_copy.M_number];top>0;top>>=1)
    {
        p_copy.arr[0]++;
    } 
        
    result=minus(num1,&p_copy);
    free(p_copy.arr);
	return result;
}

void Mod(Num *num1,Num *p)//取模
{
    int n;//n为模数左移位数
	unsigned long q;
	n=num1->M_number-p->M_number;//n为大数与取模数的比特位之差
	num1->arr[num1->M_number+1]=0;//最高位前面一项的空间置0
	for (;n>=0;n--) 
    {
        do{
            //判断num1与p的最高位大小
            q=(num1->arr[p->M_number+n+1]*(MAXNUMBER+1)+num1->arr[p->M_number+n]) / (p->arr[p->M_number]+1);
            if (q==0) q=(num1->arr[p->M_number+n+1]*(MAXNUMBER+1)+num1->arr[p->M_number+n]) / (p->arr[p->M_number]);
        } while(subtract(num1,p,q,n)!=-1);
	}
}

void multiply(Num *num1,Num *num2,Num *p)//边乘边取模
{
    Num num1_copy;
    num1_copy.M_number=num1->M_number;
    num1_copy.memory=p->memory;
    num1_copy.arr=(TYPE *)malloc( sizeof(TYPE) * (num1_copy.memory+1));
    memcpy(num1_copy.arr,num1->arr,sizeof(TYPE) * (num1_copy.memory+1));
    memset(num1->arr,0,sizeof(TYPE) * (num1->memory+1));//初始化
    for (int position2=1; position2<=num2->M_number; position2++) //从低至高遍历num2中的所有元素
    {
        for (int position1=1;position1<=num1_copy.M_number;position1++)
            num1->arr[position1+position2-1]+=num1_copy.arr[position1]*num2->arr[position2];
    }
    int c=0;//c初始化
    num1->M_number=1;
    for (int position=1; position<=num1->memory; position++) //重新计算新的M_number
    {
        c+=num1->arr[position];//用c来存储当前位置的p
        num1->arr[position]=c&MAXNUMBER;//最多存储M比特位
        c=c>>M;//右移M
        if (num1->arr[position]!=0) num1->M_number=position;//如果当前块不为0,当前长度为i+1
    }
    num1->arr[0]=M*(num1->M_number-1);
    for(int top=num1->arr[num1->M_number];top>0;top>>=1) 
        num1->arr[0]++;
    free(num1_copy.arr);
    Mod(num1,p);//取模运算
}

void power(Num *num1,Num *num2,Num *p)//边幂运算边取模
{
    int mask;
    int index,position=num2->M_number;
    Num num1_initial;
    num1_initial.M_number=num1->M_number;
    num1_initial.memory=num1->memory;
    num1_initial.arr=(TYPE *)malloc( sizeof(TYPE) * (num1_initial.memory+1));
    memcpy(num1_initial.arr,num1->arr,sizeof(TYPE) * (num1_initial.memory+1));

    Num num1_copy;
    num1_copy.arr=(TYPE *)malloc( sizeof(TYPE) * (num1->memory+1));
    if(num2->arr[position]==1) 
    {
        position--;
        mask=1<<(M-1);
    }
    else if(num2->arr[0]%M==0) 
        mask=1<<(M-2);
    else mask=1<<((num2->arr[0]%M)-2);
    for(index=num2->arr[position];index!=0;)
    {
        num1_copy.M_number=num1->M_number;
        num1_copy.memory=num1->memory;
        memcpy(num1_copy.arr,num1->arr,sizeof(TYPE) * (num1_copy.memory+1));
        multiply(num1,&num1_copy,p);//指数乘2

        if((index&mask)) 
            multiply(num1,&num1_initial,p);//指数+1
        mask>>=1;
        if(mask==0) index=0;
        if(mask==0&&position>1)
        {
            index=num2->arr[--position];
            mask=1<<(M-1);
        }
  
    }

    free(num1_initial.arr);
    free(num1_copy.arr);
}

_Bool coresidual(Num *num1,Num *num2)//同余判断
{
    if (num1->M_number==1 && num1->arr[1]==1) return true;
    if (num1->arr[0]!=num2->arr[0]) return false;//如果a与mod位数不同,不可能同余为-1
    if (num1->arr[1]!=num2->arr[1]-1) return false;//如果最后一位不是相差1,不可能同余为-1
    for (int position=2; position<=num1->M_number;position++)//逐位比较,如果某一位不相同,不可能同余为-1
        if (num1->arr[position]!=num2->arr[position]) return false;
    return true;
}

void print(Num *num1)//输出二进制大数
{
	int j,k=0;
    int b=0,flag=0;
    int position=num1->M_number;
	unsigned char bits[M+1];
	for (int i=1; i<=num1->M_number; i++,position--)
    {
        b=num1->arr[position];
		for (j=1; j<=M; j++) 
        {
            bits[j]=(unsigned char)(b&1);
            b>>=1;
		}
		for (j--; j>=1; j--) 
        {
            if(!(flag==0&&bits[j]=='\0'))
            {
                flag=1;
                printf("%d",bits[j]);
                k++;
            }
            if(k!=0)
            {
                if ((k%64==0) || (i==num1->M_number&&j==1)) printf("\n");
                else if (k%8==0) printf(" ");
            }

		}
	}
}

#endif