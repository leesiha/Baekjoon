#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, answer = 0;
vector<string> saved;

void userInput()
{
	cin >> N >> M;
	saved.resize(N);
	for (int i = 0; i < N; i++)
		cin >> saved[i];
}

void solution()
{
	sort(saved.begin(), saved.end());
	string str;
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		binary_search(saved.begin(), saved.end(), str) ? answer++ : 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	userInput();
	solution();
	cout << answer << endl;
}
