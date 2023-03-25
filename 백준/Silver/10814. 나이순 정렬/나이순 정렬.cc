// 참고 : https://velog.io/@matcha_/%EB%B0%B1%EC%A4%80-10814-%EB%82%98%EC%9D%B4%EC%88%9C-%EC%A0%95%EB%A0%AC-C-%EC%A0%95%EB%A0%AC
// stable_sort와 sort의 차이에 대해 알자.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    pair<int, string> p;
    vector<pair<int, string> > v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    stable_sort(v.begin(), v.end(), compare);
    for (vector<pair<int, string> >::iterator iter = v.begin(); iter < v.end(); iter++)
    {
        p = *iter;
        cout << p.first << ' ' << p.second << '\n';
    }
}