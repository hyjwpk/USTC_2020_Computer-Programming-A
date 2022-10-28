#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
    double pi = 2;
    double dps;
    int i = 1;
    scanf("%lf",&dps);
    do
    {
        pi = pi*4*i/(2*i-1)*i/(2*i+1);
        i++;
    } while (M_PI-pi>dps);
    printf("%.*f\n",(int)(-log10(dps))+1,pi);/*输出小数位数为精度位数+1*/
    printf("i=%d",i-1);
    getchar();
    getchar();
    return 0;
}