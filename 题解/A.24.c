#include <stdio.h>
#define MyLpha(c) ((c>='a'&&c<='z')?1:0)

int main()
{
    char ch;
    while((ch=getchar())!='\n')
    {
        printf("%c",(MyLpha(ch)==1)?(ch-('a'-'A')):(ch+('a'-'A')));
    }
    return 0;
}