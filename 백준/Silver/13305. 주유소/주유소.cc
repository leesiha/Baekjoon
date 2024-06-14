#include <iostream>
#include <array>

using namespace std;

int N, dist[100000], cost[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// input
	cin >> N;
	for (int i = 0; i < N-1; i++)
		cin >> dist[i];
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	// estimate
	int min = cost[0];
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if (cost[i] < min)
			min = cost[i];
		result += min * dist[i];
	}
	cout << result;
}
