#include <iostream>

using namespace std;
size_t arr[1001];
int main()
{
    size_t n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 3;
    for (size_t i = 3; i <= n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] * 2;
        arr[i] %= 10007;
    }
    cout << arr[n];
}