#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 10; j++)
            scanf("%d", &arr[j]);
        sort(arr, arr + 10, compare);
        cout << arr[7] << '\n';
    }
}