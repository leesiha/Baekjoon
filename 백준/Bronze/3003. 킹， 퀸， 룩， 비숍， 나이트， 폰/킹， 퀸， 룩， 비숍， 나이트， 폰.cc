#include <stdio.h>

int K, Q, L, B, N, P;

int main()
{
    scanf("%d %d %d %d %d %d", &K, &Q, &L, &B, &N, &P);
    printf("%d %d %d %d %d %d", 1 - K, 1 - Q, 2 - L, 2 - B, 2 - N, 8 - P);
}