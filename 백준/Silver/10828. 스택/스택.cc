#include <iostream>

using namespace std;
int stack[10000] = {
    -1,
};
int indx = 0;
void order(string command, int number)
{
    if (command == "push")
    {
        stack[indx] = number;
        indx++;
    }
    else if (command == "pop")
    {
        indx--;
        if (indx == -1)
            indx = 0;
        cout << stack[indx] << '\n';
        stack[indx] = -1;
    }
    else if (command == "size")
    {
        cout << indx << '\n';
    }
    else if (command == "empty")
    {
        if (stack[0] == -1)
            cout << "1\n";
        else
            cout << "0\n";
    }
    else if (command == "top")
    {
        if (indx < 1)
            cout << stack[0] << '\n';
        else
            cout << stack[indx - 1] << '\n';
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        unsigned int number = 0;
        string command;
        cin >> command;
        if (command == "push")
            cin >> number;

        order(command, number);
    }
}