#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first != p2.first) // x좌표가 증가하는 순
        return p1.first < p2.first;
    // else if (p1.first == p2.first) // x좌표가 같으면 y좌표가 증가하는 순
    return p1.second < p2.second;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << "\n";
}