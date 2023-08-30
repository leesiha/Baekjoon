// 참고 : https://jaimemin.tistory.com/1255
// DFS 재귀 공부
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 8
using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];
vector <int> v;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = v[i];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    dfs(0);
}