#include <iostream>

using namespace std;
size_t a, b, c;

int main()
{
    while (true)
    {
        cin >> a >> b >> c;
        if (!(a || b || c))
            break;
        if ((a > b && a > c) && a*a == (b*b + c*c))
            cout << "right" << endl;
        else if ((b > a && b > c) && b*b == (a*a + c*c))
            cout << "right" << endl;
        else if ((c > a && c > b) && c*c == (b*b + a*a))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
}