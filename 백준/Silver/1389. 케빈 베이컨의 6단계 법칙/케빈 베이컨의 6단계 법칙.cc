// 참고 : https://hackids.tistory.com/86
// 풀이 방법 - 플로이드 와샬 알고리즘
#include <iostream>
#define MAX 101
using namespace std;

int rel[MAX][MAX]; // index 0 미사용
int min_bacon = 600, answer;
int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= n; i++) // 초기화
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            rel[i][j] = 6; // 모든 사람들은 최대 6단계 이내에서 서로 아는 사람으로 연결될 수 있다.
        }
    }

    for (int i = 0; i < m; i++) // 관계 입력
    {
        cin >> a >> b;
        rel[a][b] = 1;
        rel[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (rel[i][j] == 1) // 서로 아는사이
                    continue;
                if (rel[i][k] + rel[k][j] > 1) // k를 끼고 아는사이
                    rel[i][j] = min(rel[i][j], rel[i][k] + rel[k][j]);
            }
        }
    }

    // 답 찾기
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++) // i 유저의 케빈 베이컨 수
        {
            tmp += rel[i][j];
        }
        if (tmp < min_bacon)
        {
            min_bacon = tmp;
            answer = i;
        }
    }

    cout << answer << endl;
}