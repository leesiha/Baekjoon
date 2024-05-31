#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void userInput()
{
	cin >> N >> M;
	v.resize(N);
}

void solution()
{
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a-1; j < b; j++)
			v[j] = c;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	userInput();
	solution();
	
	for (int i = 0; i < N; i++)
		cout << v[i] << " ";
}
