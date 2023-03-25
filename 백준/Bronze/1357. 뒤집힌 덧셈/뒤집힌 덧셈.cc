#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int result = stoi(s1) + stoi(s2);
    string str = to_string(result);
    reverse(str.begin(), str.end());
    cout << stoi(str);
}