#include <iostream>
using namespace std;
size_t sum, tmp;

int main()
{
    for (size_t i = 0; i < 5; i++)
    {
        cin >> tmp;
        if (tmp < 40)
            sum += 40;
        else
            sum += tmp;
    }
    cout << sum/5;
}