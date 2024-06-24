#include <iostream>

using namespace std;
int T, C;
int quarter, dime, nickel, penney;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> C;

		quarter += C / 25;
		C -= 25 * quarter;

		dime += C / 10;
		C -= 10 * dime;

		nickel += C / 5;
		C -= 5 * nickel;

		penney += C;

		cout << quarter << " " << dime << " " << nickel << " " << penney << "\n";
		quarter = dime = nickel = penney = 0;
	}
	
}