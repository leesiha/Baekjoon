// 참고 : 
// 풀이 방법 - bfs
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int n, m, result;
int map[MAX][MAX];
queue <pair<int, int> > q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int row, int col)
{
    for (int i = 0; i < 4; i++)
    {
        int cur_row = row + dx[i];
        int cur_col = col + dy[i];
        if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m)
        {
            if (map[cur_row][cur_col] == 0)
            {
                map[cur_row][cur_col] = 1;
                q.push(make_pair(cur_row, cur_col));
            }
        }        
    }
    
}

int main()
{
    cin >> m >> n;
    int check = m * n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                q.push(make_pair(i, j));
            else if (map[i][j] == -1)
                check--;
        }
    }
    
    while (true)
    {
        int size = q.size();
        check -= size;
        for (int i = 0; i < size; i++)
        {
            int index_row = q.front().first;
            int index_col = q.front().second;
            q.pop();
            dfs(index_row, index_col);
        }
        if (q.empty())
            break;
        result++;
    }
    if (check != 0)
        result = -1;
    
    cout << result;
}