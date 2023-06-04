#include <iostream>
#define MAX 9

using namespace std;

size_t n, m, arr[MAX];

void dfs(size_t cnt)
{
    // 탈출 조건
    if (cnt == m)
    {
        for (size_t i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (size_t i = 1; i <= n; i++) // 1부터 N까지 자연수 중에서
    {
        arr[cnt] = i;
        dfs(cnt+1);
    }
}

int main()
{
    cin >> n >> m;
    dfs(0);
}