// 참고 : https://gdlovehush.tistory.com/545
// 풀이 방법 - priority_queue
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int num;

    while (N--)
    {
        cin >> num;
        if (num != 0)
            pq.push({abs(num), num});
        else
        {
            if (pq.empty())
                cout << 0 << endl;
            else
            {
                cout << pq.top().second << endl;
                pq.pop();
            }
        }
    }
}
