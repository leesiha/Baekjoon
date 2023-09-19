// 참고 : 
// 
#include <iostream>
using namespace std;
#define MAX 10000

int N, M;
int back=0, front=0, now, cnt;
int arr[MAX];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    now = arr[front];
    while(front < N)
    {
        if (now == M)
        {
            cnt++;
            front++;
            now += arr[front];
        }
        else if (now < M)
        {
            front++;
            now += arr[front];
        }
        else if (now > M)
        {
            now -= arr[back];
            back++;
        }
    }
    cout << cnt;
}