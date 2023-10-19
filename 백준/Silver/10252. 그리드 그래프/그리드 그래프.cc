// 참고 : https://ip99202.github.io/posts/%EB%B0%B1%EC%A4%80-10252-%EA%B7%B8%EB%A6%AC%EB%94%94-%EA%B7%B8%EB%9E%98%ED%94%84/
// 규칙 찾기
#include <iostream>
#include <stack>
using namespace std;

// 3 ≤ m, n ≤ 100

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, m, n;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        cin>>m>>n;
        int row = 0, col = 0;
        cout << 1 << endl;
        while (true)
        {
            cout << '(' << row << ',' << col << ")\n";
            if (row % 2) //홀수
                col--;
            else
                col++;
            if (col < 1 || col >= n)
            {
                row++;
                if (row % 2) // 홀수
                    col--;
                else
                    col++;
            }
            if (row == m)
                break;
        }
        while (--row)
            cout << '(' << row << ',' << 0 << ")\n";
    }
    return 0;
}
