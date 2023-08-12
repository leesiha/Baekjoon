// 참고 : 
// 풀이 방법 - 
#include <iostream>
#include <string>
using namespace std;

bool can_use[10];
int N, M, cnt;

// 1. + 나 - 만 해서 이동
// 2. 번호 찍어서 이동
// 3. 1 + 2
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int num;
    for (int i = 0; i < 10; i++) //초기화
        can_use[i] = true;

    for (int i = 0; i < M; i++)
    {
        cin >> num;
        can_use[num] = false;
    }
    
    
    // 1.
    cnt = abs(N - 100);

    // 2.
    for (int i = 0; i < 5000000; i++)
    {
        string str = to_string(i);
        for (int j = 0; j < str.length(); j++)
        {
            if (can_use[str[j]-'0'] == false)
            {
                // cout << str[j]-'0' <<" is " << can_use[str[j] - '0'] << endl;
                break;
            }
            if (j == str.length() - 1)
                cnt = min(cnt, j + 1 + abs(N - i));
        }
    }

    cout << cnt;
}
