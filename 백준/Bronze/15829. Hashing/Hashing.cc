#include <iostream>
#include <cmath>
using namespace std;
size_t L, sum;
string s;
int num;

int main()
{
    cin >> L >> s;
    for (size_t i = 0; i < L; i++)
    {
        sum += (char(s[i]) - 96)*pow(31,i);
    }
    cout << sum % 1234567891;
}