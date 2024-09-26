#include <string>
#include <vector>
#include <iostream>
#define MAX 100

using namespace std;

int dp[MAX];

bool containsThree(int num)
{
    if (num < 10)
    {
        return num == 3;
    }
    return (num % 10 == 3) || containsThree(num / 10);
}

void make()
{
    dp[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        int num = dp[i - 1] + 1;
        while (containsThree(num) || (num % 3 == 0))
            num++;
        dp[i] = num;
    }
}

int solution(int n)
{
    make();
    int answer = dp[n - 1];
    return answer;
}

int main()
{
    cout << solution(9) << endl;
    return 0;
}