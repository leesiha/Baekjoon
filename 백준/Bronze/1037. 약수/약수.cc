#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N;
    vector<int> v;
    cin >> N;
    for (unsigned i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << v.front() * v.back();
}