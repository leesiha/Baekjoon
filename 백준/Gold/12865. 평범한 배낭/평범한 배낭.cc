// 참고 : https://cocoon1787.tistory.com/206
// 풀이 방법 - dp(0-1 Knapsack)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
// index 0 미사용
int DP[101][100001]; // [배낭에 넣을 물건 번호][현재 배낭의 무게]
int W[101]; // 물건 무게
int V[101]; // 물건 가치

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];
    for (int i = 1; i <= N; i++) // 각 물건 하나씩 탐색
    {
        for (int j = 0; j <= K; j++)
        {
            if (j >= W[i]) //가방 안에 담을 수 있다면? 가치 대소비교 시작
            {
                // DP[i-1][j] 지금 물건보다 더 가치있는 경우가 있음
                // DP[i - 1][j - W[i]] + V[i] 지금 물건과 조합해서 가치를 더 높일 수 있음
                DP[i][j] = max(DP[i-1][j], DP[i - 1][j - W[i]] + V[i]);
            }
            else //가방 안에 담을 수 없다면
                DP[i][j] = DP[i-1][j]; // 이전 기록(최선)을 그대로 복붙            
        }
    }
    
    cout << DP[N][K];
}