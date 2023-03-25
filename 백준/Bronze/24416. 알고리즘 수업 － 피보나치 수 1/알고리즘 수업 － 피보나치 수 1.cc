#include <iostream>
using namespace std;
int code1 = 0, code2 = 0;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        code1++;
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

int fibonacci(int n)
{
    int f[50];
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        code2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main()
{
    int n;
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << code1 << ' ' << code2 << endl;
}