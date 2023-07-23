// 참고 : https://ongveloper.tistory.com/261
// 풀이 방법 - DP (며칠 뒤에 다시 풀어볼것...)
#include <iostream>
#include <algorithm>

using namespace std;

size_t n, dp[50001]; // 인덱스는 1부터 사용

void makeDp(size_t num)
{
    for (size_t i = 1; i * i <= num; i++)
    {
        if (dp[num] == 0)
        {
            dp[num] = dp[i * i] + dp[num - i * i];
        }
        else
        {
            dp[num] = min(dp[num], dp[i * i] + dp[num - i * i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    // dp배열 채우기
    for (size_t i = 1; i * i <= n; i++)
        dp[i*i] = 1;
    if (dp[n] != 0)
    {
        cout << dp[n];
    }
    else
    {
        for (size_t i = 1; i <= n; i++)
        {
            if (dp[i] != 0)
                continue;
            makeDp(i);
        }
        cout << dp[n];
    }
}