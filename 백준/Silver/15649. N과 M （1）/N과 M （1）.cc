// 참고 : https://cryptosalamander.tistory.com/54
// DFS 재귀 공부
#include <iostream>
#define MAX 8 //visited에서 0은 사용하지 않는다.
using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];

void dfs(int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i-1])
        {
            visited[i-1] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i-1] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(0);
}