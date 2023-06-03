#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

size_t T, N, M, result; // N : 문서 개수, M : 순서를 알고싶은 문서의 인덱스

int main()
{
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        queue<pair<size_t, size_t> > q;
        vector<size_t> v;
        cin >> N >> M;
        for (size_t i = 0; i < N; i++)
        {
            size_t tmp;
            cin >> tmp;
            q.push(make_pair(i, tmp));
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(), greater<size_t>());
        while (!q.empty())
        {
            if (q.front().second < v[0])
            {
                pair<size_t, size_t> tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            else
            {
                if (q.front().first == M)
                {
                    result++;
                    break;
                }
                q.pop();
                v.erase(v.begin());
                result++;
            }  
        }
        cout << result << endl;
        result = 0;
    }
    return 0;
}
