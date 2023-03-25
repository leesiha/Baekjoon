#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        vector<pair<int, string> > v;
        for (int j = 0; j < N; j++)
        {
            pair<int, string> p;
            cin >> p.second >> p.first;
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        cout << v.back().second << endl;
    }
}