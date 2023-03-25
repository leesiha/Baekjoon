#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    stack<int> stack;
    cin >> str;
    int i;
    for (i = str.length() - 1; i >= 0; i = i - 3)
    {
        int num;
        num = (str[i] - '0') * 1;
        if (i - 1 >= 0)
            num += (str[i - 1] - '0') * 2;
        if (i - 2 >= 0)
            num += (str[i - 2] - '0') * 4;
        stack.push(num);
    }

    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
}