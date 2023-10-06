// 참고 : 
// 
#include <iostream>
using namespace std;

size_t n, result = 1;

int main()
{
    cin >> n;
    for (size_t i = 0; i < n; i += 2)
    {
        result = result * 2 % 16769023;
    }
    cout << result;
    return 0;
}