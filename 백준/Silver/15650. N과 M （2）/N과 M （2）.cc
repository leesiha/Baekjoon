#include <iostream>
#define MAX 9
using namespace std;

size_t n, m, arr[MAX];
bool visited[MAX];

void dfs(size_t num, size_t cnt)
{
    if (cnt == m)
    {
        for (size_t i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (size_t i = num; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i+1, cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 0);  
}