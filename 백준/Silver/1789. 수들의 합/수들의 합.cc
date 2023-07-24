#include <iostream>

using namespace std;

size_t num;

int main()
{
    cin >> num;
    size_t sum = 0, count = 0;
        while (sum <= num)
        {
            count++;
            sum += count;
        }
        cout << count - 1;
}