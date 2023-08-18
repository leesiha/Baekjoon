// 참고 :
// 풀이 방법 - bfs
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int map[101];      // not use index 0
bool visited[101]; // not use index 0
int result = 100;
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; // 사다리의 수 N(1 ≤ N ≤ 15)과 뱀의 수 M(1 ≤ M ≤ 15)이 주어진다.
    cin >> n >> m;

    for (int i = 0; i < n; i++) // 사다리
    {
        int x, y;
        cin >> x >> y;
        map[x] = y;
    }
    for (int i = 0; i < m; i++) // 뱀
    {
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }

    q.push(make_pair(1, 0));
    visited[1] = true;

    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (now == 100)
        {
            result = min(result, cnt);
            break; // 목표에 도달하면 종료
        }

        for (int i = 1; i <= 6; i++)
        {
            int next = now + i;
            if (next <= 100 && !visited[next])
            {
                visited[next] = true;
                if (map[next])
                {
                    q.push(make_pair(map[next], cnt + 1));
                }
                else
                {
                    q.push(make_pair(next, cnt + 1));
                }
            }
        }
    }

    cout << result;
}
