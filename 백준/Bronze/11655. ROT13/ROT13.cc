#include <iostream>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    for (unsigned i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (str[i] > 109)
                str[i] -= 13;
            else
                str[i] += 13;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (str[i] > 77)
                str[i] -= 13;
            else
                str[i] += 13;
        }
        printf("%c", str[i]);
    }
}