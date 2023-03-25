#include <stdio.h>

void get_digits(int num, int *result)
{
    if (num <= 9)
    {
        *result += num;
        return;
    }
    get_digits(num / 10, result);
    get_digits(num % 10, result);
}

int main()
{
    int result[10000];
    // initialize
    for (int i = 0; i < 10000; i++)
        result[i] = i + 1;

    int tmp;
    for (int num = 1; num <= 10000; num++)
    {
        tmp = 0;
        get_digits(num, &tmp);
        tmp += num;
        if (tmp <= 10000)
            result[tmp - 1] = -1;
    }

    // print
    for (int i = 0; i < 10000; i++)
    {
        if (result[i] != -1)
            printf("%d\n", result[i]);
    }
}