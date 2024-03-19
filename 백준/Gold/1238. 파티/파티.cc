// 참고 : https://hagisilecoding.tistory.com/135
// Dijkstra
// 정점의 개수가 최대 1000개, 간선의 개수가 최대 100000개 이므로 O(|V||E|) = 10,000,000 이 되어 1초안에 동작한다.
// priority_queue 들어가 있어서 좀 어렵게 느껴진다. 나중에 다시 한 번 풀어볼 것.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1000
#define INF 98765432
int N, M, X;
vector<pair<int, int> > v[MAX+1];
int dst[MAX + 1];
int result;

int Dijkstra(int A, int B)
{
    memset(dst, INF, sizeof(dst));
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
    pq.push({0, A}); //{거리, 시작노드}. priority 정렬을 위해 거리를 앞에 뒀음
    dst[A] = 0;

    while (!pq.empty())
    {
        int cur_n = pq.top().second; //current node
        int cur_dst = pq.top().first;
        // cout << "cur_n : " << cur_n << " cur_dst : " << cur_dst << "\n";
        pq.pop();

        if (cur_n == B) //목적지에 도착했다면
            return dst[cur_n];

        for (size_t i = 0; i < v[cur_n].size(); i++) //연결된 노드 확인
        {
            int next_n = v[cur_n][i].first;
            int next_dst = v[cur_n][i].second + cur_dst;
            // cout << "next_n : " << next_n << " next_dst : " << next_dst << " dst[next_n] : " << dst[next_n] << "\n";
            if (dst[next_n] > next_dst) // 현재 저장된 dst값보다 작다면
            {
                dst[next_n] = next_dst;
                pq.push({next_dst, next_n});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    int A, B, T;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> T;
        v[A].push_back({B, T});
    }
    int goto_party, comeback_home; //각 노드별로 거리 계산
    int answer = 0;                // N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간
    for (int i = 1; i <= N; i++)
    {
        goto_party = Dijkstra(i, X);
        comeback_home = Dijkstra(X, i);
        if (answer < goto_party + comeback_home)
            answer = goto_party + comeback_home;
    }
    cout << answer << "\n";
}
