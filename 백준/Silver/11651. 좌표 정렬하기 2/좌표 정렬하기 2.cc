#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    pair<int, int> p;
    vector<pair<int, int> > v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
}