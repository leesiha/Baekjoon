#include <iostream>
char str[5][15];
int main()
{
    for (int i = 0; i < 5; i++)
        scanf("%s", str[i]);
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (str[j][i] != 0)
                printf("%c", str[j][i]);
        }
    }
}