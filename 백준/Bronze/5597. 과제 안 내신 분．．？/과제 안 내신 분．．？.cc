#include "stdio.h"
int checkAssignment[30];
int tmp;
int main()
{
    for (int i = 0; i < 28; i++)
    {
        scanf("%d", &tmp);
        checkAssignment[tmp-1] = 1;
    }
    for (int i = 0; i < 30; i++)
    {
        if (checkAssignment[i] == 0)
        {
            printf("%d\n", i+1);
        }
        
    }
}