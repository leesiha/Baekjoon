#include <iostream>

using namespace std;

size_t N, M, a, b, dp[100001];

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M; // 첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다
    short num;
    for (size_t i = 1; i <= N; i++)
    {
        // 수는 1,000보다 작거나 같은 자연수이다
        cin >> num;
        dp[i] = num + dp[i-1];
    }

    while (M--)
    {
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << '\n';
    }
}