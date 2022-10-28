#include <stdio.h>

#define NUMBER(a) (sizeof(a)/sizeof(a[0]))

int main()
{
    double a[1123];
    printf("%d",(int)NUMBER(a));
    return 0;
}