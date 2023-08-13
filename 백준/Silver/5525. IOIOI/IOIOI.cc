// 참고 : https://donggoolosori.github.io/2020/09/27/boj-5525/
// 풀이 방법 -
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, result = 0, cnt = 0;
    string str;
    cin >> n >> m >> str;
    for (int i = 0; i < m; i++)
    {
        if (str[i] == 'I')
        {
            int j = i;
            while (j + 2 < m && str[j + 1] == 'O' && str[j + 2] == 'I' && cnt < n)
            {
                cnt++;
                j += 2;
            }
            if (cnt == n)
                result++;
            cnt = 0;
        }   
    }
    cout << result << endl;
}
