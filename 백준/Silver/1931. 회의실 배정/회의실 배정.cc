// 참고 : https://cocoon1787.tistory.com/147
// 풀이 방법 - 그리디
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, start, end_, meeting_count = 1;
vector <pair<int, int> > v;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end_;
        v.push_back(make_pair(end_, start));
    }
    sort(v.begin(), v.end());
    int time = v[0].first;
    for (int i = 1; i < N; i++)
    {
        if (time <= v[i].second)
        {
            meeting_count++;
            time = v[i].first;
        }
    }
    cout << meeting_count;
}