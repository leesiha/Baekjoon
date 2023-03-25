#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int j = 0; j < T; j++)
    {
        string str;
        cin >> str;
        stack<char> stack;
        int i;
        for (i = 0; i < str.length(); i++)
        {
            if (str[i] == '(')
                stack.push('(');
            else if (str[i] == ')')
            {
                if (stack.empty())
                    break;
                else
                    stack.pop();
            }
        }
        if (i == str.length() && stack.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}