// 참고 : https://code-kh-studio.tistory.com/5
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
int adj[50][50];
bool visited[50][50];
int mvX[4] = {1, -1, 0, 0};
int mvY[4] = {0, 0, 1, -1};
int M, N, K;

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int nX = x + mvX[i];
        int nY = y + mvY[i];
        if (nX < 0 || nY < 0 || nX >= M || nY >= N)
            continue;
        if (adj[nY][nX] && !visited[nY][nX])
        {
            visited[nY][nX] = true;
            dfs(nY, nX);
        }
    }
}

int dfsAll()
{
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (adj[i][j] && !visited[i][j])
            {
                count++;
                visited[i][j] = true;
                dfs(i, j);
            }
    return count;
}

int main()
{
    int T;
    int x, y;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        memset(adj, 0, sizeof(adj));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            cin >> x >> y;
            adj[y][x] = 1;
        }
        cout << dfsAll() << endl;
    }
}