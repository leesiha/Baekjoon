#include <iostream>
#include <cmath>

using namespace std;

int getLength(int prevX, int prevY, int X, int Y) // get the length of straight-line
{
	if (prevX == 12345 && prevY == 12345)
		return 0;
	return max(abs(prevX - X), abs(prevY - Y));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, n, s, p;
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		int answer = 0;
		cin >> n >> s >> p;
		int px = 12345, py = 12345, x, y;
		for (int i = 0; i < n+1; i++)
		{
			cin >> x >> y;
			answer += getLength(px, py, x, y);
			px = x;
			py = y;
		}
		//print
		cout << "Data Set " << i << ":\n";
		cout << ceil((answer * s) / (double)p) << "\n\n";
	}
}
