//约翰抓牛
#include <stdio.h>
struct Condition{
    int position;
    int step;
    struct Condition *last;
}condition[100000];//存储每个顶点
char state[100001];//存储每个顶点的状态是否被经过

int main()
{
    int n,k;
    int i=0,j=0;
    int a,b,c;//存储三种动作的结果坐标
    int s;
    struct Condition *p; 
    scanf("%d %d",&n,&k);
    if(k<=n)//剪枝
    {
        printf("%d",n-k);
        return 0;
    }
    //初始化
    condition[0].position=n;
    condition[0].step=0;
    condition[0].last=NULL;
    state[n]=1;
    do
    {
        a=condition[i].position+1;
        b=condition[i].position-1;
        c=condition[i].position*2;
        if(a<=100000&&state[a]==0)
        {
            j++;
            condition[j].position=a;
            condition[j].step=condition[i].step+1;
            condition[j].last=&condition[i];
            if(a==k) 
            {
                break;
            }
            state[a]=1;
        }
        if(b>=0&&state[b]==0)
        {
            j++;
            condition[j].position=b;
            condition[j].step=condition[i].step+1;
            condition[j].last=&condition[i];
            if(b==k) 
            {
                break;
            }
            state[b]=1;
        }
        if(c<=100000&&state[c]==0)
        {
            j++;
            condition[j].position=c;
            condition[j].step=condition[i].step+1;
            condition[j].last=&condition[i];
            if(c==k) 
            {
                break;
            }
            state[c]=1;
        }
        i++;
    } while (i<=j);
    s=condition[j].step;
    int solve[s+1];
    p=&condition[j];
    i=s;
    //存储每步的步骤
    do
    {
        solve[i--]=p->position;
        p=p->last;
    } while (p!=NULL);
    //输出步骤
    for(i=0;i<=s;i++)
    {
        printf("%d ",solve[i]);
    }
    printf("\n%d",s);
    return 0;
}