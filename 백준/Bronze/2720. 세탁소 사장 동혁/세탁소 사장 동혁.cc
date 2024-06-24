#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, C;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> C;

		int quarter = C / 25;
		C %= 25;

		int dime = C / 10;
		C %= 10;

		int nickel = C / 5;
		C %= 5;

		int penney = C;

		cout << quarter << " " << dime << " " << nickel << " " << penney << "\n";
	}
}