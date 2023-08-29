// 참고 : 
// 풀이 방법 - bfs
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
queue <pair <int, int> > q;
bool visited[100001];
int map[100001];
int N, K, result = 100000;

void bfs()
{
    while (!q.empty())
    {
        int position = q.front().first;
        int time = q.front().second;        
        q.pop();
        if (time > result) continue;
        
        if (position == K)
        {
            result = min(time, result);
            // cout << time << endl;
            // return;
        }
        
        // 순간이동
        int tmp = position;
        while (tmp*2 > 0 && tmp*2 <= 100000)
        {
            // visited[position*2] = true;
            q.push(make_pair(tmp*2, time));
            tmp *= 2;
        }
        // 앞으로 한 칸
        if (position+1 >= 0 && position+1 <= 100000 && !visited[position+1])
        {
            visited[position+1] = true;
            q.push(make_pair(position+1, time+1));
        }
        // 뒤로 한 칸
        if (position-1 >= 0 && position-1 <= 100000 && !visited[position-1])
        {
            visited[position-1] = true;
            q.push(make_pair(position-1, time+1)); 
        }
    } 
}

int main()
{
    cin >> N >> K;
    q.push(make_pair(N, 0)); 
    visited[N] = true;
    bfs();
    cout << result << endl;
}