// 참고: 
// stack
#include <iostream>
#include <stack>

using namespace std;

string str;
stack <char> stk;

//우선순위 따지기
bool isBig(char op)
{
	if (stk.empty())
		return true;
	else
	{
		char compare = stk.top();
		if (compare == '(')
			return true;
		else if (compare == '+' || compare == '-')
			if (op == '*' || op == '/')
				return true;
	}
	return false;
}

int main()
{
	cin >> str;
	char c;
	for (size_t i = 0; i < str.size(); i++)
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			cout << c;
		else
		{
			if (c == ')')
			{
				while (stk.top() != '(')
				{
					cout << stk.top();
					stk.pop();
				}
				stk.pop();
			}
			else if (c == '(')
			{
				stk.push('(');
			}
			else
			{
				if (isBig(c))
					stk.push(c);
				else
				{
					while (!isBig(c))
					{
						cout << stk.top();
						stk.pop();
					}
					stk.push(c);
				}
			}
		}
	}
	while (!stk.empty())
	{
		if (stk.top() != '(')
			cout << stk.top();
		stk.pop();
	}
}