/*strcmp*/
#include <stdio.h>
#include <string.h>
#define N 5

int compare(char *str1,char *str2);

int main()
{
    char str1[N]={'a','b','c','d','f'},str2[N]={'a','b','c','d','e'};
    printf("%d",compare(str1,str2));
    return 0;
}

int compare(char *str1,char *str2)
{
    int i;
    int flag1=0,flag2=0;
    for(i=0;i<=4;i++)if(str1[i]=='\0') flag1=1;
    for(i=0;i<=4;i++)if(str1[i]=='\0') flag2=1;
    if(flag1&&flag2)
    {
        for(i=0;i<strlen(str1)&&i<strlen(str2)&&str1[i]==str2[i];i++);
        if(i==strlen(str1)&&i==strlen(str2)) return 0;
        if(str1[i]>str2[i]) return 1;
        if(str1[i]<str2[i]) return -1;
    }
    else
    {
        for(i=0;i<N&&i<N&&str1[i]==str2[i];i++);
        if(i==N&&i==N) return 0;
        if(str1[i]>str2[i]) return 1;
        if(str1[i]<str2[i]) return -1;
    }
    return 0;
}
