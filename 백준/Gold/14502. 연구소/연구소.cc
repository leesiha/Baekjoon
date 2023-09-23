// 참고 : 
// 
#include <iostream>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;
#define MAX 8

int N, M, result;
int map[MAX][MAX];
int map_copy[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue <pair<int, int> > q;

void copy()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            map_copy[n][m] = map[n][m];
        }
    }
}

void infect()
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (map[n][m] == 2)
                q.push(make_pair(n, m));
        }
    }
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int move_r = row + dy[i];
            int move_c = col + dx[i];
            if (move_r >= 0 && move_r < N && move_c >= 0 && move_c < M)
            {
                if (map_copy[move_r][move_c] == 0)
                {
                    map_copy[move_r][move_c] = 2;
                    q.push(make_pair(move_r, move_c));
                }
            }
        }
    }
    // if (map_copy[1][0]==1 && map_copy[0][1]==1 && map_copy[3][5]==1)
    // {
    //     cout << "infect" << endl;

    //     for (int n = 0; n < N; n++)
    //     {
    //         for (int m = 0; m < M; m++)
    //         {
    //             cout << map_copy[n][m] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
}

int count_safe_place()
{
    int cnt = 0;
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (map_copy[n][m] == 0)
                cnt++;
        }
    }
    return cnt;
}

void dfs(int cnt)
{
    if (cnt == 3)
    {
        copy();
        infect();
        result = max(result, count_safe_place());
        return;
    }
    else
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if (map[n][m] == 0)
                {
                    map[n][m] = 1;
                    visited[n][m] = true;
                    dfs(cnt + 1);
                    visited[n][m] = false;
                    map[n][m] = 0;
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            cin >> map[n][m];
        }
    }
    dfs(0);
    cout << result;
}