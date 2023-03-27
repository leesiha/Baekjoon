// 출처 : https://velog.io/@gonudayo/%EB%B0%B1%EC%A4%80-2579-%EA%B3%84%EB%8B%A8%EC%98%A4%EB%A5%B4%EA%B8%B0-2156-%ED%8F%AC%EB%8F%84%EC%A3%BC-%EC%8B%9C%EC%8B%9D
// DP로 푸는 게 답이었다....ㅠㅠ
#include <iostream>

using namespace std;
#define MAX 301

size_t arr[MAX];
size_t DP[MAX];

void Solution(int num)
{
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];
    DP[3] = max(arr[1], arr[2]) +  arr[3];
    
    for (int i = 4; i <= num; i++)
        DP[i] = max(DP[i-3] + arr[i-1], DP[i-2]) + arr[i];
    cout << DP[num] << endl;
}

int main()
{
    int stairs;
    cin >> stairs;

    for (int i = 1; i <= stairs; i++)
        cin >> arr[i];
    Solution(stairs);
}