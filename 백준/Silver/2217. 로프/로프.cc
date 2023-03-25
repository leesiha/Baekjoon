#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int max = 0;
    for (int i = 0; i < N; i++)
        max = v[i] * (N-i) > max ? v[i] * (N-i) : max;
    cout << max;
}