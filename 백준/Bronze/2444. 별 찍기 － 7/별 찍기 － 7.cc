#include <iostream>
#include <vector>

using namespace std;

int N;
char *arr;

void userInput()
{
	cin >> N;
	int total = N * 2 - 1;
	arr = new char[total];
	for (int i = 0; i < total; i++)
		arr[i] = ' ';
}

void solution()
{
	int center = N - 1;
	for (int i = 0; i < N; i++)
	{
		arr[center - i] = '*';
		arr[center + i] = '*';
		arr[center + i + 1] = '\0';
		cout << arr << endl;
	}
	for (int i = N - 1; i > 0; i--)
	{
		arr[center - i] = ' ';
		arr[center + i] = '\0';
		cout << arr << endl;
	}
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
