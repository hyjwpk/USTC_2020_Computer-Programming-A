#include <stdio.h>

int main(void)
{
    short a;
    unsigned short b;
    printf("%d %d\n",sizeof(a),sizeof(b));
    a = -2;
    b = a;
    printf("%d %d\n",a,b);  /*-2的补码为1111,1111,1111,1110B */
    b = 65535;
    a = b;      /*-1的补码为1111,1111,1111,1111B*/
    printf("%d %d\n",a,b);
    return 0;
}