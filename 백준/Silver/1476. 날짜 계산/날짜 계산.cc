// 출처 : https://yabmoons.tistory.com/82
// 근데 왜 if ((result % 15) == E && (result % 28) == S && (result % 19) == M)는 안되는건지 모르겠다
#include <iostream>
using namespace std;
int main()
{
    int E, S, M;
    cin >> E >> S >> M;
    int result = 1;
    while (1)
    {
        if (!((result - E) % 15 || (result - S) % 28 || (result - M) % 19))
        {
            cout << result << endl;
            return 0;
        }
        result++;
    }
}