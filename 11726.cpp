#include <iostream>

using namespace std;

int arr[1001];
int main(void)
{
    arr[1] = 1;
    arr[2] = 2;
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] = arr[i] % 10007;
    }
    cout << (arr[n]);
}