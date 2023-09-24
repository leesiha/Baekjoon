// 참고 : https://blog.naver.com/ndb796/221234424646, https://www.acmicpc.net/board/view/118178
// 다익스트라
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <queue>
using namespace std;
#define V_MAX 20000
#define E_MAX 300000
#define INF 999999999

int V, E, K;
int u, v, w;
vector <pair <int, int> > graph[E_MAX + 1];
int dist[V_MAX + 1];

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue <pair <int, int> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) 
    {   
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if (dist[current] < distance) continue;
        for (unsigned long i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int nextDistance = distance + graph[current][i].second;
            
            if (nextDistance < dist[next])
            {
                dist[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> K;
    // arr 초기화
    for (int i = 1; i <= V; i++)
        dist[i] = INF;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    // 다익스트라
    dijkstra(K);
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}