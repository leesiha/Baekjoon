#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    long long num;
    cin >> N;
    vector<long long> v;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        if (binary_search(v.begin(), v.end(), num))
            cout << "1\n";
        else
            cout << "0\n";
    }
}