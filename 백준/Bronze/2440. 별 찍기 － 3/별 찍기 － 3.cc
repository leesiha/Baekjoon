#include <iostream>
using namespace std;
size_t num;

int main()
{
    cin >> num;
    while (num)
    {
        for (size_t i = 0; i < num; i++)
            cout << '*';
        cout << '\n';
        num--;
    }
}