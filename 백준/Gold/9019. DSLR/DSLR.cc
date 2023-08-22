// 참고 : https://bconfiden2.tistory.com/133
// 참고 : https://covely.tistory.com/66
// 풀이 방법 - bfs
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
int T, A, B;
string DSLR = "DSLR";
bool visit[10000];
vector <string> v;

int ret(int temp, char func) // DSLR 각 연산
{
    if (func == DSLR[0])
        temp = (temp * 2) % 10000; // D
    else if (func == DSLR[1])
        temp -= 1; // S
    else if (func == DSLR[2])
        temp = (temp % 1000) * 10 + (temp / 1000); // L
    else
        temp = (temp / 10) + (temp % 10) * 1000; // R

    if (temp < 0)
        temp = 9999;
    return temp;
}

void bfs()
{
    queue<pair<int, string>> q; // 변형된 숫자, 명령어(누적)
    q.push(make_pair(A, ""));
    visit[A] = true;

    while (!q.empty())
    {
        int now = q.front().first;
        string order = q.front().second;
        q.pop();
        if (now == B)
        {
            v.push_back(order);
            memset(visit, false, 10000);
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int tmp = ret(now, DSLR[i]);
            if (!visit[tmp])
            {
                visit[tmp] = true;
                q.push(make_pair(tmp, order + DSLR[i]));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        // clock_t start = clock();
        bfs();
        // clock_t finish = clock();
        // double duration = (double)(finish - start) / CLOCKS_PER_SEC;
        // printf("%f초", duration);
    }

    for (int i = 0; i < T; i++)
    {
        cout << v[i] << endl;
    }
}
