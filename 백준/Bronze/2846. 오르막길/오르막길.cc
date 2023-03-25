#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> uphill_road;
    uphill_road.push_back(0);
    int N, num1 = 0, num2 = 0, height = 0;
    cin >> N;
    cin >> num1;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> num2;
        if (num1 < num2)
        {
            height += (num2 - num1);
        }
        else
        {
            uphill_road.push_back(height);
            height = 0;
        }
        num1 = num2;
    }
    if (height)
    {
        uphill_road.push_back(height);
        height = 0;
    }

    // for (vector<int>::iterator iter = uphill_road.begin(); iter < uphill_road.end(); iter++)
    // {
    //     cout << *iter << ' ';
    // }
    cout << *max_element(uphill_road.begin(), uphill_road.end());
}