#include <stdio.h>

int main(void)
{
    char a;
    a = 255;
    printf("%d %d",sizeof(a),a);/*若a显示为-1则为有符号数,若显示为255则为无符号数*/
    return 0;
}