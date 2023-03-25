// 참고 : https://jaimemin.tistory.com/634
#include <iostream>
using namespace std;
int arr[1001];

void make_triangular_number()
{
    arr[0] = 0; // index 0은 사용하지 않음
    for (int i = 1; i <= 1000; i++)
        arr[i] = i + arr[i - 1];
}

bool check(int num)
{
    for (int i = 1; arr[i] <= num; i++)
    {
        for (int j = 1; arr[j] <= num; j++)
        {
            for (int k = 1; arr[k] <= num; k++)
            {
                if ((arr[i] + arr[j] + arr[k]) == num)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    make_triangular_number();
    int K, num;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        // brute force
        if (check(num))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}