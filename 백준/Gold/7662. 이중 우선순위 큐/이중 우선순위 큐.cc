// 참고 : https://donggoolosori.github.io/2020/09/24/boj-7662/
// 풀이 방법 - multiset
#include <iostream>
#include <set>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, k;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> k;
        char c;
        int num;
        multiset<int> ms;
        multiset<int>::iterator min, max, tmp;
        for (int i = 0; i < k; i++)
        {
            cin >> c >> num;
            if (c == 'I')
            {
                ms.insert(num);
            }
            else
            {
                if (!ms.empty())
                {
                    if (num == 1)
                    {
                        tmp = ms.end();
                        ms.erase(--tmp);
                    }
                    else
                    {
                        min = ms.find(*ms.begin());
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if (ms.empty())
            cout << "EMPTY" << endl;
        else
        {
            min = ms.end();
            max = ms.begin();
            cout << *--min << ' ' << *max << endl;
        }
    }
}
