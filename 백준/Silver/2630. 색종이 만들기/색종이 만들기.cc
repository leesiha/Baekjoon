// 참고 : https://donggoolosori.github.io/2020/09/23/boj-2630/
// 풀이 방법 - 재귀
#include <iostream>

using namespace std;

size_t N; // N은 2, 4, 8, 16, 32, 64, 128 중 하나이다.
int white, blue; // 하얀색으로 칠해진 칸은 0, 파란색으로 칠해진 칸은 1
int map[128][128];

void solve(int row, int column, int len)
{
    bool is_it_square = true;
    int criteria = map[row][column];
    for (int i = row; i < row + len; i++)
    {
        for (int j = column; j < column + len; j++)
        {
            if (map[i][j] != criteria)
            {
                is_it_square = false;
                break;
            }
        }
        if(!is_it_square)
            break;
    }
    if (!is_it_square)
    {
        len = len / 2;
        solve(row, column + len, len);       // 1사분면
        solve(row, column, len);             // 2사분면
        solve(row + len, column, len);       // 3사분면
        solve(row + len, column + len, len); // 4사분면
    }
    else
    {
        if (criteria == 0)
            white++;
        else
            blue++;
    }
}

int main()
{
    cin >> N;

    // 맵 그리기
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            cin >> map[i][j];

    solve(0, 0, N);
    cout << white << endl;
    cout << blue << endl;
}