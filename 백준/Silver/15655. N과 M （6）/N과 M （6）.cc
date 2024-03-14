// 참고 : https://cryptosalamander.tistory.com/55
// DFS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9
vector<int> v;
int arr[MAX];
bool visited[MAX];
int N, M;

void dfs(int idx, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i != M; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i = idx; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = v[i];
            dfs(i+1, cnt+1);
            visited[i] = false;
        }
    }   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    dfs(0, 0);
}
