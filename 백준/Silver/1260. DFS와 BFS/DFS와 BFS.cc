#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1001];
vector<int> graph[10001];

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];

        if (!visited[y])
            dfs(y);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main(void)
{
    int N, M, V, A, B;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    //입력받은 뒤 간선들 정렬(정점 작은 순)
    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    fill_n(visited, 1001, 0);
    cout << '\n';
    bfs(V);
}