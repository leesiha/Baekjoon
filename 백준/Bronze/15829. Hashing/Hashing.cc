#include <iostream>
#include <cmath>
#define M 1234567891
using namespace std;
size_t L, sum;
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
        sum = (sum + (char(s[i]) - 96) * pow_(31, i)) % M;
    cout << sum;
}