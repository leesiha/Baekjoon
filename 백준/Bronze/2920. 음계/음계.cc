#include <iostream>

using namespace std;

bool ascending(int *arr)
{
    for (size_t i = 1; i < 8; i++)
    {
        if (arr[i] - arr[i-1] < 0)
            return false;
    }
    return true;
}

bool descending(int *arr)
{
    for (size_t i = 1; i < 8; i++)
    {
        if (arr[i] - arr[i - 1] > 0)
            return false;
    }
    return true;
}

int main()
{
    int arr[8];
    for (size_t i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }
    
    if (ascending(arr))
        cout << "ascending" << endl;
    else if (descending(arr))
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;
}