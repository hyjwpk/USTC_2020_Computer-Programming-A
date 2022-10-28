#include<stdio.h>

int main()
{
    int a,b,c;
    for(a=1;a<=3;a++)/*1代表X，2代表Y，3代表Z*/
    {
        for(b=1;b<=3;b++)
        {
            for(c=1;c<=3;c++)
            {
                if(a!=1&&c!=1&&c!=3&&a!=b&&b!=c&&a!=c)
                    {
                        printf("%c与A是情侣\n",'X'+a-1);
                        printf("%c与B是情侣\n",'X'+b-1);
                        printf("%c与C是情侣\n",'X'+c-1);
                    }
            }
        }
    }
    return 0;
}