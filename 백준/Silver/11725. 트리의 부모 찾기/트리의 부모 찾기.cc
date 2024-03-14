// 참고 : https://tooo1.tistory.com/173
// dfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000001
int parent[MAX];
bool visited[MAX];
vector <int> tree[MAX];

// 1 | 6 4
// 2 | 4
// 3 | 6 5
// 4 | 1 2 7
// 5 | 3
// 6 | 1 3
// 7 | 4

void bfs(void)
{
    queue <int> q;
    int node;
    q.push(1);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        visited[node] = true;
        for (int i = 0; i < tree[node].size(); i++)
        {
            int next = tree[node][i];
            if (!visited[next])
            {
                q.push(next);
                parent[next] = node;
            }
        }
    }
}

void dfs(int node)
{
    visited[node] = true;
    for (int i = 0; i < tree[node].size(); i++)
    {
        int next = tree[node][i];
        if (!visited[next])
        {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main(void)
{
    int N;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // dfs(1);
    bfs();
    for (int i = 2; i <= N; i++) cout << parent[i] << "\n";
}