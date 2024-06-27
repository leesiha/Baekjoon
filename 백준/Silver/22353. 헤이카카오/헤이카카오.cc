#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double a, d, k;
	cin >> a >> d >> k;
	
	d /= 100;
	k /= 100;
	double expectedValue = 0;
	double previous = 1;
	int i = 1;

	while (1)
	{
		expectedValue += i * a * previous * d;
		i++;

		if (d == 1)
			break;

		previous = previous * (1 - d);
		d += d * k;
		
		if (d >= 1)
			d = 1;
	}
	
	cin.precision(7);
	cout << fixed << expectedValue;
}
