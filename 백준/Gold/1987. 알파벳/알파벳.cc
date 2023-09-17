// 참고 : https://yabmoons.tistory.com/84
// DFS 백트래킹. visited[26]아이디어를 못 떠올렸다
#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int R, C, result;
char map[MAX][MAX];
bool visited[26] = {false, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int row, int col, int cnt)
{
    // cout << "row: " << row << " col: " << col << " cnt: " << cnt << " result: " << result << "\n";
    result = max(result, cnt);
    for (int i = 0; i < 4; i++)
    {
        int cur_row = row + dy[i];
        int cur_col = col + dx[i];
        if ((cur_row >= 0 && cur_row < R && cur_col >= 0 && cur_col < C) 
            && !visited[map[cur_row][cur_col] - 'A'])
        {
            visited[map[cur_row][cur_col] - 'A'] = true;
            dfs(cur_row, cur_col, cnt+1);
            visited[map[cur_row][cur_col] - 'A'] = false;
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
    visited[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << result;
}