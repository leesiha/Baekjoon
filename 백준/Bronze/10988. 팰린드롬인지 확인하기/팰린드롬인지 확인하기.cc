#include <iostream>
#include <vector>

using namespace std;

string str;

void userInput()
{
	cin >> str;
}

void solution()
{
	int strlen = str.length();
	int front = 0, back = strlen - 1;
	while (front < back)
	{
		if (str[front] != str[back])
		{
			cout << 0 << endl;
			return;
		}
		front++;
		back--;
	}
	cout << 1 << endl;
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
