#include <iostream>
#include <stack>

using namespace std;


bool is_it_balanced(string str)
{
    stack<char> s;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push('(');
        else if (str[i] == '[')
            s.push('[');
        else if (str[i] == ')')
        {
            if (!s.empty() && (s.top() == '('))
                s.pop();
            else
                return false;
        }
        else if (str[i] == ']')
        {
            if (!s.empty() && (s.top() == '['))
                s.pop();
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    return false;
}

int main()
{
    string str = "";
    while (1)
    {
        getline(cin, str);
        if (str == ".")
            break;
        if(is_it_balanced(str))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}