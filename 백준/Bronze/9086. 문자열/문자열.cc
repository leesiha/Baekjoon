#include <iostream>
#include <vector>

using namespace std;

int T;
string str;

void userInput()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		cout << str[0] << str[str.size() - 1] << endl;
	}
}

void solution()
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	userInput();
	// solution();
	
	// cout << answer << endl;
}
