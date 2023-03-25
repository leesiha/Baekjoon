#include <stdio.h>
#include <stdlib.h>
/*
그림처럼 2차원 배열이 있다고 한다면, 순서대로 나열할 때 호출되는 index는

00

01
10

20
11
02

03
12
21
30
.
.
.

출력되는 결과는 해당 인덱스 + 1 한 값이다.
인덱스는 어느 한 숫자가 0이 될때까지 +1/-1을 반복하면서 변화한다
*/

int main()
{
    int x = 0, y = 0; // 인덱스는 00부터 시작
    // x는 열, y는 행. 좌표계로 생각하면 편하다

    int count;
    scanf("%d", &count);
    if (count == 1)
    {
        printf("%d/%d", y + 1, x + 1);
        return 0;
    }
    count--;
    while (count)
    {
        // 현재 인덱스 값이 0이 아닌 애를 하나 증가시킴
        if (x || (x == 0 && y == 0))
        {
            x++;
            count--;
            while (x && count)
            {
                x--;
                y++;
                count--;
            }
        }
        else if (y)
        {
            y++;
            count--;
            while (y && count)
            {
                y--;
                x++;
                count--;
            }
        }
    }
    printf("%d/%d", y + 1, x + 1);
}