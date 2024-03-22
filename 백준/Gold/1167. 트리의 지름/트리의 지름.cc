// 참고: https://restudycafe.tistory.com/346
// dfs
#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

size_t V, maxDist, maxNode;
bool visited[MAX+1];
vector<pair<int, int> > graph[MAX+1]; //<node, dist>

void dfs(int node, int dist)
{
	if (maxDist < dist)
	{
		maxDist = dist;
		maxNode = node;
	}

	int nextNode, cost;
	for (int i = 0; i < graph[node].size(); i++)
	{
		nextNode = graph[node][i].first;
		cost = graph[node][i].second;
		if (!visited[nextNode])
		{
			visited[nextNode] = true;
			dfs(nextNode, dist+cost);
			visited[nextNode] = false;
		}
	}
}

int main()
{
	cin >> V;
	// 간선 정보 입력받기
	int start, end, cost;
	for (size_t i = 0; i < V; i++)
	{
		cin >> start;
		while (true)
		{
			cin >> end;
			if (end == -1)
				break;
			else
			{
				cin >> cost;
				graph[start].push_back({end, cost});
			}
		}
	}
	visited[1] = true;
	dfs(1, 0);
	visited[1] = false;
	visited[maxNode] = true;
	maxDist = 0;
	dfs(maxNode, 0);
	cout << maxDist;
}