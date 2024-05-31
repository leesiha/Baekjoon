#include <iostream>

using namespace std;

unsigned long long A, B, C, answer = 0;

void userInput()
{
	cin >> A >> B >> C;
}

void solution()
{
	answer = A + B + C;
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
