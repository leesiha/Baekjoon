// 참고 : 
// 풀이 방법 - bfs
#include <iostream>
#include <queue>
#include <tuple>
#define MAX 100
using namespace std;

int M, N, H, result;
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int map[MAX][MAX][MAX];
queue<tuple<int, int, int> > q;

void bfs(int hight, int row, int col)
{
    for (int i = 0; i < 6; i++)
    {
        int cur_h = hight + dz[i];
        int cur_row = row + dy[i];
        int cur_col = col + dx[i];
        if (cur_row >= 0 && cur_col >= 0 && cur_h >= 0 && cur_row < M && cur_col < N && cur_h < H)
        {
            if (map[cur_h][cur_row][cur_col] == 0)
            {
                map[cur_h][cur_row][cur_col] = 1;
                q.push(make_tuple(cur_h, cur_row, cur_col));
            }
            
        }
    }
}

int main()
{
    cin >> N >> M >> H;
    int check = M * N * H;
    for (int h = 0; h < H; h++)
    {
        for (int m = 0; m < M; m++)
        {
            for (int n = 0; n < N; n++)
            {
                cin >> map[h][m][n];
                if (map[h][m][n] == 1)
                {
                    q.push(make_tuple(h, m, n));
                }
                else if (map[h][m][n] == -1)
                    check--;
            }
        }
    }

    while (true)
    {
        int size = q.size();
        check -= size;
        for (int i = 0; i < size; i++)
        {
            int index_h = get<0>(q.front());
            int index_row = get<1>(q.front());
            int index_col = get<2>(q.front());
            q.pop();
            bfs(index_h, index_row, index_col);
        }
        if (q.empty())
            break;
        result++;
    }
    if (check != 0)
        result = -1;

    cout << result;
}
