// 참고 : N과 M (7)
// DFS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9
vector<int> v;
int arr[MAX];
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
        arr[cnt] = v[i];
        dfs(i, cnt+1);
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
