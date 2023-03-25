#include <iostream>
#include <stack>

using namespace std;
int main()
{
    stack<int> stack;
    int K, num, result = 0;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        if (num)
            stack.push(num);
        else
            stack.pop();
    }
    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    cout << result;
}