// 참고 : 
// 풀이 방법 - dp
#include <iostream>
#include <algorithm>
using namespace std;

int triangle[501][501]; //인덱스 0 미사용
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >> triangle[i][j];
    }

    // 삼각형 밑변에서부터 최댓값 골라서 위로 더하기
    for (int i = N; i >= 1; i--)
    {
        for (int j = 1; j < i; j++)
            triangle[i-1][j] = triangle[i-1][j] + max(triangle[i][j], triangle[i][j+1]);
    }
    

    cout << triangle[1][1] << endl;
}