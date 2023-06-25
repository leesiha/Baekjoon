#include <iostream>
#include <cmath>
using namespace std;
unsigned long L, r = 1, sum;
string s;

size_t pow_(size_t a, size_t b)
{
    size_t result = 1;
    for (size_t i = 0; i < b; i++)
        result *= a;
    return result;
}

int main()
{
    cin >> L >> s;
    for (size_t i = 0; i < L; i++)
    {
        for (size_t j = 0; j <= i; j++)
            r *= 31;
        sum += (char(s[i]) - 96) * pow_(31, i);
    }
    cout << sum % 1234567891;
}