// 참고 : https://4z7l.github.io/2021/02/02/algorithms-boj-10026.html
// 풀이 방법 - dfs
#include <iostream>
#define MAX 100

using namespace std;
int N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char drawing[MAX][MAX];
bool visited[MAX][MAX] = {
    false,
};
int count_boundary;

void dfs(int row, int col, char color)
{
    visited[row][col] = true;
    for (int i = 0; i < 4; i++)
    {
        int cur_row = row + dy[i];
        int cur_col = col + dx[i];
        if (cur_row >= 0 && cur_col >= 0 && cur_row < N && cur_col < N && !visited[cur_row][cur_col])
        {
            if (drawing[cur_row][cur_col] == color)
            {
                dfs(cur_row, cur_col, color);
            }
        }
    }
}

int main()
{
    cin >> N;
    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            drawing[i][j] = tmp[j];
        }
    }

    count_boundary = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                count_boundary++;
                dfs(i, j, drawing[i][j]);
            }
        }
    }
    cout << count_boundary << ' ';

    // 적록색맹이 보는 그림으로 가공
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (drawing[i][j] == 'G')
                drawing[i][j] = 'R';
            visited[i][j] = false;
        }
    }

    count_boundary = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                count_boundary++;
                dfs(i, j, drawing[i][j]);
            }
        }
    }
    cout << count_boundary;
}
