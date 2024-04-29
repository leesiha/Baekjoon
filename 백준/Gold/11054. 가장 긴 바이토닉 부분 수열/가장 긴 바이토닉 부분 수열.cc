#include <iostream>

using namespace std;
#define MAX 1000

int N;
int arr[MAX];
int dp[MAX];
int r_dp[MAX];

void Solution()
{
  // go forward
  // S(1) < S(2) < ... S(k-1) < S(k)
  for (int i = 0; i < N; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
    {
      if ((arr[j] < arr[i]) && dp[j] + 1 > dp[i])
        dp[i] = dp[j] + 1;
    }
  }

  // go backward
  // S(k) > S(k+1) > ... S(N-1) > S(N)
  for (int i = N - 1; i >= 0; i--)
  {
    r_dp[i] = 1;
    for (int j = N - 1; j >= i; j--)
    {
      if ((arr[j] < arr[i]) && r_dp[j] + 1 > r_dp[i])
        r_dp[i] = r_dp[j] + 1;
    }
  }

  // answer
  int answer = 0;
  for (int i = 0; i < N; i++)
  {
    if (answer < dp[i] + r_dp[i])
      answer = dp[i] + r_dp[i];
  }

  cout << answer-1 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }
  
  Solution();
}