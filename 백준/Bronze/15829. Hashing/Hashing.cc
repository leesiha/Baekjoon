#include <iostream>
#include <cmath>
#define M 1234567891
using namespace std;
size_t L, sum, r=1;
string s;

int main()
{
    cin >> L >> s;
    for (size_t i = 0; i < L; i++){
        sum = (sum + (char(s[i]) - 96) * r) % M;
        r = (r * 31) % M;
    }
    cout << sum;
}