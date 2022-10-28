#include <stdio.h>

void print(int row, int high)/*判断输出数字还是输出空格*/
{
    int column;
    for(column=1;column<=high+row;column++)
    {
        if(column<=high-row||(column-high+row)%2==1)    printf(" ");
        else    printf("%d",row);              
    }
    printf("\n"); 
}

int main(void)
{
    int high, row;  /*high为高度，row为行数*/
    scanf("%d",&high);
    if(high>9)  return 1;  /*高度不大于9*/
    for(row=1;row<=high;row++)  /*金字塔上半层*/
    {
        print(row,high);
    }
    for(row-=2;row>=1;row--)  /*金字塔下半层*/
    {
        print(row,high);
    }
    getchar();
    getchar();
    return 0;
}