// 참고 : https://eungulife.tistory.com/368
// 풀이 방법 - bfs
#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int> > q;
int mx[4] = {0, 0, 1, -1};
int my[4] = {1, -1, 0, 0};
int n, m;

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x_now = x + mx[i];
            int y_now = y + my[i];
            if (x_now >= 0 && x_now < n && y_now >= 0 && y_now < m)
            {
                if (visited[x_now][y_now] == false)
                {
                    map[x_now][y_now] = map[x][y] + 1;
                    visited[x_now][y_now] = true;
                    q.push(make_pair(x_now, y_now));
                }
                
            }
            
        }
        
    }
    
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                q.push(make_pair(i, j)); // 2 쓰인 위치에서 길 찾기 시작
                map[i][j] = 0;
                visited[i][j] = true;
            }
            else if (map[i][j] == 0)
            {
                visited[i][j] = true;
            }
            
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false)
                cout << "-1 ";
            else
                cout << map[i][j] << ' ';
        }
        cout << "\n";
    }
}