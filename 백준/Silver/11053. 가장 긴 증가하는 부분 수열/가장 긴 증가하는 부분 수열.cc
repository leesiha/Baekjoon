// 참고 - https://hwan-shell.tistory.com/299
#include <iostream>

using namespace std;
size_t N, max_num, arr[1000], dp[1000], answer;

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];
    for (size_t i = 0; i < N; i++) // 체크 시작 지점
    {
        dp[i] = 1;
        max_num = 0;
        for (size_t j = 0; j <= i; j++) // 0 - 시작지점까지 검사
        {
            if (arr[j] < arr[i])
            {
                if (max_num < dp[j])
                    max_num = dp[j];
            }
        }
        dp[i] += max_num;
        answer = max(answer, dp[i]); // 뒤로 갈수록 길어진다는 보장이 없으므로
    }
    cout << answer;
}