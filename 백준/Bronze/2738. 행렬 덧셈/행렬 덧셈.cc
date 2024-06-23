#include <iostream>

using namespace std;
int arr[100][100], N, M, tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int c=0; c<2; c++)
	{
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				cin >> tmp;
				arr[i][j] += tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}