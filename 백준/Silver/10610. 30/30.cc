// 참고 : https://ongveloper.tistory.com/114
// 끝 자릿수가 0이 될 수 있는가? (주어진 숫자에 0이 들어있는가?)
// 각 자릿수를 더했을 때 3의 배수가 되는가?

// 1. 들어온 string의 각 자릿수를 내림차순으로 정렬하고, 맨 마지막 자릿수가 0인지 검사
// 2. 각 자리수의 합을 long long 형 변수에 저장하고, 3으로 나누어떨어지는지 검사

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    if (s.back() != '0')
        cout << -1;
    else
    {
        unsigned int count = 0;
        for (size_t i = 0; i < s.length(); i++)
            count += s[i] - '0';
        if (count % 3)
            cout << -1;
        else
            cout << s;
    }
}