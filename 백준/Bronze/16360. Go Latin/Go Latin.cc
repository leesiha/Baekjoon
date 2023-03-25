#include <iostream>
#include <vector>

using namespace std;
vector<string> result;
string english;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> english;
        char lastWord = english[english.length() - 1];
        if (lastWord == 'a')
        {
            english += 's';
        }
        else if (lastWord == 'i' || lastWord == 'y')
        {
            english[english.length() - 1] = 'i';
            english += "os";
        }
        else if (lastWord == 'l')
        {
            english += "es";
        }
        else if (lastWord == 'n')
        {
            english[english.length() - 1] = 'a';
            english += "nes";
        }
        else if ((lastWord == 'e' && english[english.length() - 2] == 'n'))
        {
            english[english.length() - 2] = 'a';
            english[english.length() - 1] = 'n';
            english += "es";
        }
        else if (lastWord == 'o')
        {
            english += 's';
        }
        else if (lastWord == 'r')
        {
            english += "es";
        }
        else if (lastWord == 't')
        {
            english += "as";
        }
        else if (lastWord == 'u')
        {
            english += 's';
        }
        else if (lastWord == 'v')
        {
            english += "es";
        }
        else if (lastWord == 'w')
        {
            english += "as";
        }
        else
        {
            english += "us";
        }
        result.push_back(english);
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << endl;
    }
}