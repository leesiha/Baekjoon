// 참고 : 
// 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

size_t T;;

double getW(int S, int A)
{
    if (S == 0 && A == 0)
        return 0;
    return (double)(S * S) / (double)((S * S) + (A * A));
}

int main()
{
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        size_t n, m; // (n)은 팀 개수이며,(m)은 전체 경기 수
        cin >> n >> m;
        vector<pair<int, int> >v(n); // first : S, second : A
        double min_ = 1.0, max_ = -1.0;
        for (size_t i = 0; i < m; i++)
        {
            size_t a, b, p, q;
            cin >> a >> b >> p >> q;
            v[a - 1].first += p;
            v[a - 1].second += q;
            v[b - 1].second += p;
            v[b - 1].first += q;
        }
        // v 모두 출력
        // for (size_t i = 0; i < n; i++)
        //     cout << v[i].first << ' ' << v[i].second << endl;

        for (size_t i = 0; i < n; i++)
        {
            double tmp = getW(v[i].first, v[i].second);
            min_ = min(min_, tmp);
            max_ = max(max_, tmp);
        }
        cout << (int)(max_ * 1000) << '\n' << (int)(min_ * 1000) << endl;
    }
    return 0;
}