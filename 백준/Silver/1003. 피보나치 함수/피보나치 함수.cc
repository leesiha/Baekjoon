#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t T, N;

    vector<pair<int, int> > v;
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(0, 1));
    for (size_t i = 2; i <= 40; i++)
        v.push_back(make_pair(v[i - 2].first + v[i - 1].first, v[i - 2].second + v[i - 1].second));

    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> N;
        cout << v[N].first << ' ' << v[N].second << endl;
    }
}