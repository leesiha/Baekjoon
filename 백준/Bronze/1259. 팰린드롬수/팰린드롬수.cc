#include <iostream>

using namespace std;

int main()
{
    string str = "-1";
    bool check = true;
    while (1)
    {
        cin >> str;
        if (str == "0")
            return 0;

        check = true;
        for (int i = 0, j = str.size() - 1; i <= j; i++, j--)
        {
            if (str[i] != str[j])
            {
                cout << "no\n";
                check = false;
                break;
            }
        }
        if (check)
            cout << "yes\n";
    }
}