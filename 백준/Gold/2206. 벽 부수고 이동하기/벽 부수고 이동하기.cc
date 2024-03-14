// 참고 : https://velog.io/@blublue_02/%EB%B0%B1%EC%A4%802206%EB%B2%88%ED%92%80%EC%9D%B4
// bfs, 누적합

#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
using namespace std;

int dx[4] = {-1, 1, 0 , 0};
int dy[4] = {0 , 0, -1, 1};
int maze[MAX][MAX][2]; 
//[?][?][0] 부수기 전 최단거리 
//[?][?][1] 부순 후 최단거리

int BFS(int N, int M)
{
    queue<pair<int, pair<int, int> > > q;
    q.push({ 0, { 0, 0 } });

    while (!q.empty())
    {
        int crash = q.front().first; // 기존에 벽 깼는지 확인
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if (y == N-1 && x == M-1)
            return maze[N-1][M-1][crash] + 1;

        for (int i=0; i<4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
                continue;
            
            // 메모리 초과
            // if (crash == 0)
            // {
            //     if (maze[next_y][next_x][0] == 1)
            //     {
            //         // 벽 부수기
            //         maze[next_y][next_x][1] = maze[y][x][0] + 1;
            //         q.push({ 1, {next_y, next_x}});
            //     }
            // }
            // else if (crash == 1)
            // {
            //     if (maze[next_y][next_x][1] == 1)
            //         continue;
            //     maze[next_y][next_x][1] = maze[y][x][1] + 1;
            //     q.push({ 1, {next_y, next_x}});
            // }

            // 갈 수 있는 위치라면, 어느 미로 맵을 확인해야 하는지 선택
            if (maze[next_y][next_x][0] == 1)
            {
                if (crash == 0)
                {
                    maze[next_y][next_x][1] = maze[y][x][0] + 1;
                    q.push({1, {next_y, next_x}});
                }
            }
            else if (maze[next_y][next_x][0] == 0)
            {
                if (crash == 1 && maze[next_y][next_x][1])
                    continue;
                maze[next_y][next_x][crash] = maze[y][x][crash] + 1;
                q.push({crash, {next_y, next_x}});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char tmp;
            cin >> tmp;
            maze[i][j][0] = tmp - '0';
        }
    }
    cout << BFS(N,M);
    return 0;
}