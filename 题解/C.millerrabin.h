/* Miller_Rabin 素性检验算法 */
#ifndef _MILLERABIN_H

#define _MILLERABIN_H
#define TIMES 10

_Bool millerRabin(Num *p)
{
    int low=p->arr[1]-1,right,position,k,i;
    Num *q=(Num *)malloc(sizeof(Num));
    Num a,a_copy;
    _Bool flag=true;
    for (right=0,position=1;low%2==0;) //一直提取2的因子直到为奇数q,k存储右移的位数
    {
        right++;
        low>>=1;
        if (right%M==0) low=p->arr[++position];//如果右移了M位,说明这一元素末尾全为0,再取下一元素继续右移
	}
    //给除去2的因子后的q分配存储的空间
    q->M_number=(int)((p->arr[0]-right+M-1)/M);
    q->memory=q->M_number*2+1;
    q->arr=(TYPE *)malloc( sizeof(TYPE) * (q->memory+1));
    memset(q->arr,0,sizeof(TYPE) * (q->memory+1));
    q->arr[0]=p->arr[0]-right;
    //将去除2的因子后的大数复制到q中
    for (int bit=0,positionq=1,positionp=1,left=0;bit<q->arr[0];)
    {
        if((right+bit)%M==0) low=p->arr[++positionp];
        bit++;//bit存储现在已经复制的比特位 
        q->arr[positionq]+=(low&1)<<(left++);
        if (bit%M==0) //如果已经复制了M的倍数位
        {
            positionq++;//移动到下一个元素
            left=0;//左移值清零
        }
        low>>=1;//存储后low右移1位
	}

    a_copy.arr=(TYPE *)malloc( sizeof(TYPE) * (p->memory+1));
    
    for(i=1;i<=TIMES;i++)//验证times次
    {
        randoma(&a, 3);//生成随机底数a
        power(&a,q,p);//计算(a^q)%p
        if(coresidual(&a,p)==true) 
        {
            free(a.arr);
            a.arr=NULL;
            printf("pass %d\n",i);
            continue;//如果a^q通过
        }
        for(k=1;k<=right;k++)//判断序列中是否有能通过检测的项
        {
            a_copy.M_number=a.M_number;
            a_copy.memory=a.memory;
            memset(a_copy.arr,0,sizeof(TYPE) * (p->memory+1));
            memcpy(a_copy.arr,a.arr,sizeof(TYPE) * (a.memory+1));
            multiply(&a,&a_copy,p);
            if (coresidual(&a,p)==true) break;
        }
        free(a.arr);
        if (k==right+1) 
        {
            flag=false;
            break;
        }
        printf("pass %d\n",i);
    }
    free(q->arr);
    free(q);
    free(a_copy.arr);
    return flag;
}

#endif