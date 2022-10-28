/*输出str1中str2出现的位置*/
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    for(int i=0;i<=strlen(str1);i++)
        for(int k=0;str1[i]==str2[k];i++,k++)/*如果当前位相同继续比较下一位直至不同为止*/
            if(k==strlen(str2)-1)
            {
                printf("%d ",(int)(i-strlen(str2))+1);
                break;
            }
    return 0;
}
