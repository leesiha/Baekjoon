#include <stdio.h>
#include <stdlib.h>

int find(int H, int W, int N)
{
    if (N % H == 0)
        return (H * 100 + (N / H));
    else
        return ((N % H) * 100 + (N / H) + 1);
}

int main(void)
{
    int line;
    scanf("%d", &line);
    int *array = (int *)malloc(sizeof(int) * line);
    for (int i = 0; i < line; i++)
    {
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);
        array[i] = find(H, W, N);
    }
    for (int i = 0; i < line; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}