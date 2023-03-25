#include <iostream>

using namespace std;
int main()
{
    unsigned int com;
    cin >> com;
    unsigned int arr[101] = {
        0,
    }; // arr[0]은 안 쓴다.

    unsigned int N;
    cin >> N;

    int num = 1;
    // link
    for (unsigned int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        if (!arr[a] && arr[b])
            arr[a] = arr[b];
        else if (arr[a] && !arr[b])
            arr[b] = arr[a];
        else if (!arr[a] && !arr[b])
        {
            arr[a] = arr[b] = num;
            num++;
        }
        else
        {
            // 이전에 연결되어 있었던 애의 숫자도 바꿔준다
            for (unsigned int i = 1; i <= com; i++)
            {
                if (i != b && arr[i] == arr[b])
                    arr[i] = arr[a];
            }
            arr[b] = arr[a];
        }
    }

    num = 0;
    // find
    for (unsigned int i = 2; i <= com; i++)
    {
        if (arr[i] == arr[1])
            num++;
    }
    cout << num;
}