// 참고 : https://velog.io/@dbsrud11/%EB%B0%B1%EC%A4%80-1697-%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%88-C
// 풀이 방법 - bfs (진짜 dp인줄)
#include <iostream>
#include <queue>
#define MAX 100001 //인덱스 0 미사용
using namespace std;
queue <pair<size_t, size_t> > q;
size_t N, K;
bool visited[MAX] = {false,};

size_t dfs(size_t n)
{
    //시작 위치 표시
    q.push(make_pair(n, 0));
    visited[n] = true;
    while (!q.empty())
    {
        size_t position = q.front().first;
        size_t count = q.front().second;
        visited[position] = true;
        q.pop();

        if (position == K)
            return count;
        // 앞으로 한 칸
        if (position + 1 < MAX && visited[position + 1] == false)
            q.push(make_pair(position + 1, count + 1));
        // 뒤로 한 칸
        if (position - 1 < MAX && visited[position - 1] == false)
            q.push(make_pair(position - 1, count + 1));
        // 순간이동
        if (position * 2 < MAX && visited[position * 2] == false)
            q.push(make_pair(position * 2, count + 1));
    }
    return 0;
}
int main()
{
    cin >> N >> K;
    cout << dfs(N);
}