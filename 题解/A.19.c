
/*回文信息判断*/
#include <stdio.h>
#include <string.h>
 
int palindrome(const char *str);
 
int main()
{
 
    printf("请输入消息:\n");
    char str[100];
    gets(str);
    if (palindrome(str))printf("该消息是回文");
    else printf("该消息不是回文");
    return 0;
}
 
int palindrome(const char *str)
{
    int end=strlen(str),i; /*end标志末尾位置*/
    for (i=0;i<=end;i++)
        if(str[i]==str[end - 1])end--;
        else return 0;
    return 1;
}