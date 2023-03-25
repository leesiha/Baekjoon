#include <stdio.h>

int is_it_prime(int num)
{
    if (num < 2)
        return 0;

    int tmp = 2; // 수는 1,000 이하이므로 overflow 발생 X
    while (tmp * tmp <= num)
    {
        if (num % tmp == 0)
            return 0;
        tmp++;
    }
    return 1;
}

int main()
{
    int N, num, count = 0;
    scanf("%d", &N); // N은 100 이하. 수는 1,000 이하
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (is_it_prime(num))
            count++;
    }
    printf("%d", count);
}
