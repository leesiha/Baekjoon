#include <stdio.h>
#include <stdlib.h>

int N, v, result;
int main()
{
    scanf("%d", &N);
    int *arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
    scanf("%d", &v);

    for (int i = 0; i < N; i++)
    {
        if(arr[i] == v) result++;
    }

    printf("%d", result);
}