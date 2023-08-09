// 참고 : https://9967han.tistory.com/15
// 풀이 방법 - dfs + 백트래킹
#include <iostream>
#include <algorithm>
#define MAX 500
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M, result = 0;

void dfs(int row, int col, int cnt, int cur_num)
{
    if (cnt == 4)
    {
        if (result < cur_num) result = cur_num;
        return;
    }
    for (int i = 0; i < 4; i++) // 상 하 좌 우 순으로 탐색
    {
        int cur_row = row + dy[i];
        int cur_col = col + dx[i];
        if (cur_row >= 0 && cur_col >= 0 && cur_row < N && cur_col < M && !visited[cur_row][cur_col])
        {
            visited[cur_row][cur_col] = true;
            dfs(cur_row, cur_col, cnt + 1, cur_num + map[cur_row][cur_col]);
            visited[cur_row][cur_col] = false;
        } 
    }

    // ㅗ ㅜ ㅏ ㅓ 확인 (하드코딩)
    if (row - 1 >= 0 && col - 1 >= 0 && row + 1 < N)
    { // ㅓ
        result = max(result, (map[row - 1][col] + map[row][col - 1] + map[row][col] + map[row + 1][col]));
    }
    if (row - 1 >= 0 && col + 1 < M && row + 1 < N)
    { // ㅏ
        result = max(result, (map[row - 1][col] + map[row][col + 1] + map[row][col] + map[row + 1][col]));
    }
    if (row - 1 >= 0 && col - 1 >= 0 && col + 1 < M)
    { // ㅗ
        result = max(result, (map[row][col] + map[row - 1][col] + map[row][col - 1] + map[row][col + 1]));
    }
    if (col - 1 >= 0 && col + 1 < M && row + 1 < N)
    { // ㅜ
        result = max(result, (map[row][col - 1] + map[row][col] + map[row + 1][col] + map[row][col + 1]));
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = true;
            dfs(i, j, 1, map[i][j]);
            visited[i][j] = false; // 백트래킹
        }
    }
    cout << result << endl;
}
