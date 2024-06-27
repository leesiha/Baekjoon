#include <iostream>
#include <map>

using namespace std;

map<char, char> m{
	{'.', '.'},
	{'O', 'O'},
	{'-', '|'},
	{'|', '-'},
	{'/', '\\'},
	{'\\', '/'},
	{'^', '<'},
	{'<', 'v'},
	{'v', '>'},
	{'>', '^'},
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int row, column;
	cin >> row >> column;
	char output[column][row];
	char c;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> c;
			output[column - j - 1][i] = m[c];
		}
	}

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << output[i][j];
		}
		cout << '\n';
	}
}
