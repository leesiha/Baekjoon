#include <iostream>
#include <array>
using namespace std;
size_t num;

int main()
{
    cin >> num;
    size_t *arr = new size_t[num+1];
    arr[0] = 0;
    arr[1] = 1;
    for (size_t i = 2; i <= num; i++)
        arr[i] = arr[i-1] + arr[i-2];
    cout << arr[num];
}