// 참고 : https://gaeunhan.tistory.com/16
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
size_t n, cnt = 1;
vector <char> v;
stack <size_t> s;

int main()
{
    cin >> n;
    size_t x;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        while (cnt <= x)
        {
            s.push(cnt);
            cnt++;
            v.push_back('+');
        }

        if (s.top() == x)
        {
            // printf("top is %lu\n", s.top());
            s.pop();
            v.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}