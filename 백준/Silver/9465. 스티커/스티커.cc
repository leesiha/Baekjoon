// 참고 : https://omyodevelop.tistory.com/51
// 풀이 방법 - dp(나중에 다시 코드 짜보자)
#include <iostream>
#include <algorithm>

using namespace std;

int sticker[2][100000];
int dp[2][100000];
int T, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> sticker[0][i];
        for (int i = 0; i < n; i++)
            cin >> sticker[1][i];
        
        // 최댓값 계산
        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    }
    
}