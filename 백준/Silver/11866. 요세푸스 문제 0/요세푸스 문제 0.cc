#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    int *circle = (int *)malloc(sizeof(int) * N);
    // 사람 앉히기 
    for (int i = 1; i <= N; i++)
        circle[i-1] = i;

    cout << '<';
    int index = -1;
    int n = N;
    while (n) // N명 모두 나갈때까지 반복
    {
        int k = K;
        while(k) // k번째 사람 제거
        {
            index++;
            if (index >= N)
                index = 0;
            while (!circle[index])
            {
                index++;
                if (index >= N)
                index = 0;
            }
            k--;
        }
        cout << circle[index];
        if(n != 1)
            cout << ", ";
        circle[index] = 0;
        n--;
    }
    cout << '>';
}