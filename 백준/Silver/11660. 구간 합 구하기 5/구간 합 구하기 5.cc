// 참고 : https://donggoolosori.github.io/2020/10/13/boj-11660/
// (DP)누적합
#include <iostream>
using namespace std;

#define MAX 1024
size_t dp[MAX + 1][MAX + 1];       // 누적합을 저장할 배열. 문제에서 0번째 인덱스 미사용으로 인해 +1
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t N, M;
    cin >> N >> M;

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            cin >> dp[i][j];
            // 누적합 저장
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    // dp 배열 출력
    // for (size_t i = 1; i <= N; i++)
    // {
    //     for (size_t j = 1; j <= N; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // M번 합 구하기
    for (size_t i = 0; i < M; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // cout << "dp[" << x2 << "][" << y2 << "] - dp[" << x2 << "][" << y1 - 1 << "] - dp[" << x1 - 1 << "][" << y2 << "] + dp[" << x1 - 1 << "][" << y1 - 1 << "] = ";
        int result = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
        cout << result  << "\n"; //endl이 아닌 \n 사용
    }
}
