#include <stdio.h>
using namespace std;

bool is_it_prime(size_t num)
{
    size_t j = 2;
    while (j * j <= num)
    {
        if (num % j == 0)
            return false;
        j++;       
    }
    return true;
}
int main()
{
    size_t M, N;
    scanf("%ld %ld", &M, &N);
    if (M <= 2)
    {
        printf("2\n");
        M = 3;
    }
    
    for (size_t i = M; i <= N; i++)
    {
        if (is_it_prime(i))
            printf("%lu\n", i);
    }
}