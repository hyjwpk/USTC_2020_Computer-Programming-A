#include "C.operate.h"
#include "C.millerrabin.h"
int main()
{
    Num p;
    //srand((unsigned int)(time(NULL)));
    scanf("%d",&LENGTH);
    clock_t t = clock();
    for(int i=1;;i++)
    {   
        printf("try %d\n",i);
        random(&p,LENGTH);
        if(millerRabin(&p)==true)
        {
            print(&p);
            printf("success in %d\n",i);
            printf("Time: %f \n", 1.0 * (clock() - t) / CLOCKS_PER_SEC); 
            break;
        }
        system("cls");
        free(p.arr);   

    }
    getchar();
    getchar();
    return 0;
}