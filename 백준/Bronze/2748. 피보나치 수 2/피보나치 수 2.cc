#include <iostream>

using namespace std;

int main()
{
    // n은 90보다 작거나 같은 자연수이므로, 미리 피보나치 배열을 만들어두고 인덱스 접근만 하자.
    long long fibo[100] = {
        0,
        1,
    };
    for (unsigned i = 2; i <= 90; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    int n;
    cin >> n;
    cout << fibo[n];
}