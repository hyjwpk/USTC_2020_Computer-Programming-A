#include <stdio.h>

int main(void)
{
    int a;
    unsigned short b;
    printf("%d %d\n",sizeof(a),sizeof(b));
    a = 131071;  /*131071的补码1,1111,1111,1111,1111*/
    b = a;
    printf("%d %d\n",a,b);
    return 0;
}