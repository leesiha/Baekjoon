#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;

int N, M;
char map[101][101];
bool visited[101][101];
int dist[101][101];
int mvX[4] = {0, 0, -1, 1};
int mvY[4] = {-1, 1, 0, 0};

void bfs(int x, int y)
{
    visited[x][y] = true;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) //상하좌우 확인
        {
            int nextX = x + mvX[i];
            int nextY = y + mvY[i];
            if (0 <= nextX && 0 <= nextY && nextX < N && nextY < M)
            {
                if (map[nextX][nextY] == '1' && !visited[nextX][nextY])
                {
                    dist[nextX][nextY] = dist[x][y] + 1;
                    visited[nextX][nextY] = true;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", map[i]);
    }
    bfs(0, 0);
    cout << dist[N - 1][M - 1] + 1;
}
