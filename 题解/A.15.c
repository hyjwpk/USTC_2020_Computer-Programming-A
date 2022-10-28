#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char num[100];
    double temp=0;
    int i,k,q,flag;
    gets(num);
    for(i=0;i<=strlen(num);i++)
    {
        if (num[i]=='0') flag++;
        if(num[i]=='.'||num[i]=='\0')/*若读取到小数点或到达字符串尾*/
        {
            if(i==0||i==flag)/*若数字小于0*/
            {
                for(q=1;num[i+q]=='0';q++);/*一直读取直到读到不为0的小数*/
                printf("%c",num[i+q]);/*输出不为0的小数作为整数部分*/
                if(num[i+q+1]!='\0') printf(".");/*若精度允许,输出小数点*/
                for(i+=q+1;num[i]!='\0';i++) printf("%c",num[i]);/*输出尾数部分*/
                printf("E-%d",q);
                break;
            }
            else/*若数字大于0*/
            {
                for(k=i-1;k>=0;k--)/*用temp暂时存储整数部分*/
                {
                    temp+=(num[k]-'0')*pow(10,(i-k-1));
                }
                for(q=0;temp>=10;q++)/*整数部分不断除10*/
                {
                    temp/=10;
                }
                printf("%.*f",q,temp);/*输出整数部分除到10以下的结果*/
                if(q==0&&num[i]=='.'&&num[i+1]!='\0') printf(".");/*若整数部分已经小于10且后续有小数部分,补充小数点*/
                for(i+=(num[i]!='\0')?1:0;num[i]!='\0';i++) printf("%c",num[i]);/*若有后续部分,输出小数*/
                printf("E+%d",q);
                break;
            }

        }
    }

    
    return 0;
}