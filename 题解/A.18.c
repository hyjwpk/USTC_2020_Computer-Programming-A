/*两字符串相减*/
#include <stdio.h>
#include <string.h>

void char_delete(char *str1,char *str2);

int main()
{
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    char_delete(str1,str2);
    printf("%s",str1);
    return 0;
}

void char_delete(char *str1,char *str2)
{
    int num=0,position;
    for(int i=0;i<strlen(str1);i++)
        for(int k=0;str1[i]==str2[k];i++,k++)
            if(k==strlen(str2)-1)
            {
                num++;/*判断是否在str1中找到了str2*/
                position=i;
                break;
            }
    if (num!=0) memcpy(&str1[position-strlen(str2)+1],&str1[position+1],strlen(str1)-position);
}