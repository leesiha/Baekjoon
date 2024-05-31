#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void userInput()
{
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++)
		v[i] = i + 1;
}

void solution()
{
	for (int i = 0; i < M; i++)
	{
		int a, b, tmp;
		cin >> a >> b;
		tmp = v[a-1];
		v[a-1] = v[b-1];
		v[b-1] = tmp;
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
