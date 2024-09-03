#include <iostream>

using namespace std;

#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define TOP 5

int *stack, _size = 0;

int size()
{
    return _size;
}

bool empty()
{
    if (size() == 0)
        return true;
    return false;
}

void push()
{
    int num;
    cin >> num;
    stack[size()] = num;
    _size++;
}

int pop()
{
    if (empty())
        return -1;
    _size--;
    return stack[size()];
}

int top()
{
    if (empty())
        return -1;
    return stack[size()-1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack = new int[N];

    int order;
    for (int i=0; i<N; i++)
    {
        cin >> order;
        if (order == PUSH) push();
        else if (order == POP)
            cout << pop() << '\n';
        else if (order == SIZE)
            cout << size() << '\n';
        else if (order == EMPTY)
            empty() == true ? cout << 1 << '\n' : cout << 0 << '\n';
        else if (order == TOP)
            cout << top() << '\n';
    }
}