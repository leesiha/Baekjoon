// 참고 : https://cryptosalamander.tistory.com/58
// 풀이 방법 - 백트래킹
#include <iostream>
#include <algorithm>
using namespace std;

int chess[15];
int N, cnt;

bool possible(int row)
{
    for (int i = 0; i < row; i++)
        if (chess[i] == chess[row] || abs(chess[i]-chess[row]) == row-i)
            return false;
    return true;
}

void n_queen(int row)
{
    if (row == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) // row 행의 모든 열 확인
    {
        chess[row] = i;
        if (possible(row)) // i번째 열에 queen을 놓을 수 있다면
        {
            n_queen(row+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    n_queen(0);

    cout << cnt << endl;
}