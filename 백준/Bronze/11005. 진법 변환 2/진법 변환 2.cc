#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
char digits[40];
void get_num(int num, int base)
{
    if (num < base)
        v.push_back(digits[num]);
    else
    {
        get_num(num / base, base);
        get_num(num % base, base);
    }
}
int main()
{
    int N, B;
    cin >> N >> B;

    // 36진법까지 미리 저장
    int j = 0;
    for (char i = '0'; i <= '9'; i++)
        digits[j++] = i;
    for (char i = 'A'; i <= 'Z'; i++)
        digits[j++] = i;
    get_num(N, B);
    for (vector<char>::iterator iter = v.begin(); iter < v.end(); iter++)
    {
        cout << *iter;
    }
}