#include <iostream>
#include <array>

using namespace std;

unsigned long long N, dist[100000], cost;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	// input
	cin >> N;
	for (unsigned long long i = 0; i < N-1; i++)
		cin >> dist[i];

	unsigned long long min, result = 0;

	// estimate
	cin >> cost;
	result += cost * dist[0];
	min = cost;
	for (unsigned long long i = 1; i < N-1; i++)
	{
		cin >> cost;
		if (cost < min)
			min = cost;
		result += min * dist[i];
	}
	cin >> cost; //ignore last value
	cout << result;
}
