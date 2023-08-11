// 참고 : https://chanhuiseok.github.io/posts/algo-50/
// 풀이 방법 - 플로이드-워셜(Floyd-Warshall) 알고리즘
#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int dist[MAX][MAX];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> dist[i][j];
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] == 1)
                    continue;
                
                if (dist[i][k] + dist[k][j] > 1)
                    dist[i][j] = 1;
                // dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
