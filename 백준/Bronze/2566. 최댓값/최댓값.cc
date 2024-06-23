#include <iostream>

using namespace std;
int arr[9][9], maxNum = -1, maxRow, maxCol;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > maxNum)
			{
				maxNum = arr[i][j];
				maxRow = i + 1;
				maxCol = j + 1;
			}
		}
	}
	cout << maxNum << endl;
	cout << maxRow << ' ' << maxCol << endl;
}