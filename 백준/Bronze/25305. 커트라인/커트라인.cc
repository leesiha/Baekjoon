#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, k, answer = 0;
vector<int> v;

void userInput()
{
	cin >> N >> k;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
}

void solution()
{
	sort(v.begin(), v.end(), greater<int>());
	answer = v[k - 1];
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
