// 참고 : https://code-kh-studio.tistory.com/5
#include <iostream>
#include <vector>

using namespace std;
vector<vector <int> >adj;
vector<bool> visited;

void dfs(int here)
{
    visited[here] = true;
    for (int i = 0; i < (int)adj[here].size(); i++)
    {
        int there = adj[here][i];
        if (!visited[there])
            dfs(there);
    }
}

int dfsAll()
{
    int count = 0;
    for (int i = 0; i < (int)adj.size(); i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i);
        }
    }
    return count - 1;
}

int main()
{
    int N, M;
    int u, v;
    cin >> N >> M;
    adj.assign(N+1, vector<int>(N+1, 0));
    visited.assign(adj.size(), false);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfsAll() << endl;
}