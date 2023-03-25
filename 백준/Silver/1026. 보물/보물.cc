

#include <iostream>
#include <algorithm>
using namespace std;
int arr1[50], arr2[50];

bool compare(int num1, int num2)
{
    return num1 > num2;
}
int main()
{
    int N, result = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr1[i];
    for (int i = 0; i < N; i++)
        cin >> arr2[i];
    sort(arr1, arr1+N);
    sort(arr2, arr2+N, compare);
    for (int i = 0; i < N; i++)
        result += arr1[i] * arr2[i];
    cout << result;
}