#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(x,y) {char* i = (char *)malloc(sizeof(x));memcpy(i, &x, sizeof(x));memcpy(&x, &y, sizeof(x));memcpy(&y, i, sizeof(x));}

int main()
{
    double a=1.1,b=2.2;
    printf("%f %f\n",a,b);
    SWAP(a,b);
    printf("%f %f\n",a,b);
    return 0;
}