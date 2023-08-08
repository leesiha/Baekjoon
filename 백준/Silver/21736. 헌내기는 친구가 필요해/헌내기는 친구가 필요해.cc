// 참고 :
// 풀이 방법 - bfs
#include <iostream>
#include <queue>
#define MAX 600
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char map[MAX][MAX];
bool visited[MAX][MAX] = {
    false,
};
queue<pair<int, int>> q;
int N, M, count_person;

void bfs()
{
    while (!q.empty())
    {

        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cur_row = row + dy[i];
            int cur_col = col + dx[i];
            if (cur_row >= 0 && cur_col >= 0 && cur_row < N && cur_col < M && !visited[cur_row][cur_col])
            {
                visited[cur_row][cur_col] = true;
                if (map[cur_row][cur_col] == 'O')
                {
                    q.push(make_pair(cur_row, cur_col));
                }
                else if (map[cur_row][cur_col] == 'P')
                {
                    count_person++;
                    q.push(make_pair(cur_row, cur_col));
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
        string tmp;
        cin >> tmp;
        for (int m = 0; m < M; m++) // O는 빈 공간, X는 벽, I는 도연이, P는 사람
        {
            map[n][m] = tmp[m];
            if (map[n][m] == 'I')
            {
                q.push(make_pair(n, m)); // 시작 위치
            }
        }
    }
    bfs();

    if (count_person == 0)
        cout << "TT";
    else cout << count_person;
}
