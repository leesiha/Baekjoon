#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N, K; //(1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
    cin >> N >> K;
    stack<int> stack;
    int num, count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        stack.push(num);
    }
    while (K)
    {
        num = stack.top();
        while (K - num >= 0)
        {
            K -= num;
            count++;
        }
        stack.pop();
    }
    cout << count;
}