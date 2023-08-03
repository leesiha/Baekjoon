// 참고 :
// 풀이 방법 - dfs
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;

int n, house;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int row, int col)
{
    visited[row][col] = true;
    for (int i = 0; i < 4; i++)
    {
        int cur_row = row + dx[i];
        int cur_col = col + dy[i];
        if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < n)
        {
            if (map[cur_row][cur_col] && !visited[cur_row][cur_col])
            {
                house++;
                dfs(cur_row, cur_col);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = str[j] - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                house = 1;
                dfs(i, j);
                if (house)
                    v.push_back(house);
            }
        }
    }

    cout << v.size() << endl;
    // 각 단지에 속하는 집의 수를 오름차순으로 정렬
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}