#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define N_MAX 1000
#define INF 987654321

int N, M, departure, arrival;
// (1 ≤ M ≤ 100,000)
// (0 ≤ cost ≤ 100,000)
int dist[N_MAX + 1];
vector<pair<int, int> > graph[N_MAX + 1]; // arrival, cost

void userInput()
{
	cin >> N >> M;

	int cost;
	for (int i = 0; i < M; i++)
	{
		cin >> departure >> arrival >> cost;
		graph[departure].push_back({arrival, cost});
	}
	cin >> departure >> arrival;
	dist[departure] = 0;
}

void solution()
{
	int cost, position;
	int nextCost, next;

	priority_queue<pair<int, int>> pq; // current_cost, current_position
	// priority_queue는 수가 큰게 앞으로 옴.
	pq.push({0, departure});

	// dijkstra
	while (!pq.empty())
	{
		cost = -pq.top().first;
		position = pq.top().second; // 우리는 작은 수부터 먼저 접근하고 싶기 때문에 -를 달았음.
		pq.pop();

		if (dist[position] < cost)
			continue; // 이미 최단거리였다면 더 계산할 필요 없음
		for (size_t i = 0; i < graph[position].size(); i++)
		{
			next = graph[position][i].first;
			nextCost = cost + graph[position][i].second;

			if (nextCost < dist[next])
			{
				dist[next] = nextCost;
				pq.push({-nextCost, next});
			}
		}
	}

	cout << dist[arrival];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < N_MAX + 1; i++)
		dist[i] = INF; // dist 초기화
	userInput();
	solution();
}