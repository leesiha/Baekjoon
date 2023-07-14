#include <iostream>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cctype>

using namespace std;
string str;
bool isItMinus = false;

int main()
{
    int result = 0;
    cin >> str;
    for (size_t i = 0; i < str.length(); i++)
    {
        int num = atoi(&str[i]);

        if (isItMinus)
            num = -num;

        while (isdigit(str[i]) && i < str.length())
            i++;
        if (i < str.length() && str[i] == '-')
            isItMinus = true;
        // printf("num: %d, 현재 위치: %c\n", num, str[i]);
        result += num;
    }
    cout << result;
}