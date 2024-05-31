#include <iostream>

using namespace std;

int N;

void userInput()
{
	cin >> N;
}

void solution()
{
	N % 4 == 0 ? N /= 4 : N = N / 4 + 1;
	for (int i = 1; i <= N; i++)
	{
		cout << "long ";
	}
	cout << "int" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	userInput();
	solution();
	// cout << answer << endl;
}
