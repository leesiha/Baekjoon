#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int getA(string numArray, int startLen)
{
	return stoi(numArray.substr(0, startLen));
}

int getB(string numArray, int A)
{
	int currentLen = to_string(A).length();
	int B = A;
	while (true)
	{
		string Bstring = to_string(B + 1);
		if (Bstring != numArray.substr(currentLen, Bstring.length()))
			break;
		currentLen += Bstring.length();
		B++;
	}
	if (A == B && numArray.length() != to_string(A).length())
		return -1;
	int BLen = to_string(B).length();
	if (to_string(B) == numArray.substr(numArray.length() - BLen, BLen))
		return B;
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string numArray;
	int A, B, currentLen;
	cin >> numArray;

	for (int i = 1; i <= 3; i++)
	{
		A = getA(numArray, i);
		B = getB(numArray, A);
		if (B != -1)
			break;
	}
	
	cout << A << " " << B;
}
