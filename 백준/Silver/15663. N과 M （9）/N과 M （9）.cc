// 참고 : https://m.blog.naver.com/js568/221857286945
// DFS, backtracking

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 9
using namespace std;

int N, M;
vector <int> v;
bool visited[MAX];
int result[MAX];

void dfs(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << result[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if ((i != N-1) && v[i] == v[i+1]) // 마지막 원소가 아니고, 현재 원소와 다음 원소가 같다면
        {
            if (!visited[i+1]) // 다음 원소가 방문되지 않았다면 continue
                continue;
        }
        if (!visited[i])
        {
            visited[i] = true;
            result[cnt] = v[i];
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    dfs(0);
}
