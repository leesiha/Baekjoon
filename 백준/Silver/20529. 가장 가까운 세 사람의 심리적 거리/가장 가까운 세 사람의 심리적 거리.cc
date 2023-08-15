// 참고 : https://github.com/fpdjsns/Algorithm/blob/master/BOJ/20529.%20%EA%B0%80%EC%9E%A5%20%EA%B0%80%EA%B9%8C%EC%9A%B4%20%EC%84%B8%20%EC%82%AC%EB%9E%8C%EC%9D%98%20%EC%8B%AC%EB%A6%AC%EC%A0%81%20%EA%B1%B0%EB%A6%AC.cpp
// 풀이 방법 - 완전탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dist(string str1, string str2, string str3)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        cnt += (str1[i] != str2[i]) + (str2[i] != str3[i]) + (str1[i] != str3[i]);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;

        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (n > 16 * 2)
        {
            cout << 0 << endl;
        }
        else
        {
            int answer = 1e9;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        answer = min(answer, dist(v[i], v[j], v[k]));
                    }
                }
            }
            cout << answer << endl;
        }
    }
}
