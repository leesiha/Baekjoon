// 참고: 1167번과 비슷
// dfs
#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;

int n, maxDist, maxNode;
bool visited[MAX+1];
vector<pair<int, int> > graph[MAX+1]; //<node, dist>

void dfs(int node, int dist)
{
	if (dist > maxDist)
	{
		maxDist = dist;
		maxNode = node;
	}

	int nextNode, nextDist;
	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		nextNode = graph[node][i].first;
		nextDist = graph[node][i].second;
		if (!visited[nextNode])
		{
			visited[nextNode] = true;
			dfs(nextNode, dist + nextDist);
			visited[nextNode] = false;
		}
	}
}
int main()
{
	cin >> n;
	// 간선 정보 입력받기
	int start, end, cost;
	for (int i = 0; i < n-1; i++)
	{
		cin >> start >> end >> cost;
		graph[start].push_back({end, cost});
		graph[end].push_back({start, cost}); //양방향 간선임
	}
	visited[1] = true; //임의의 노드로부터 가장 먼 노드 구하기
	dfs(1, 0);
	visited[1] = false;
	visited[maxNode] = true; //가장 먼 노드로부터 반대쪽 노드까지의 길이 구하기(지름)
	dfs(maxNode, 0);
	cout << maxDist;
}