// 참고 : https://whkakrkr.tistory.com/entry/BOJ-%EB%B0%B1%EC%A4%80-20170%EB%B2%88-Commemorative-Dice
// 확률
#include <iostream>
using namespace std;

int diviser[7] = {2, 3, 4, 6, 9, 12, 24};
int a[6], b[6];
int numerator = 0, denominator = 36;
int main()
{
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    for (int i = 0; i < 6; i++)
        cin >> b[i];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[i] > b[j])
            {
                numerator++;
            }
        }
    }
    // 약분하기
    for (int i = 6; i >= 0;)
    {
        if (numerator % diviser[i] == 0 && denominator % diviser[i] == 0)
        {
            numerator /= diviser[i];
            denominator /= diviser[i];
        }
        else
            i--;
    }
    
    cout << numerator << '/' << denominator << endl;
    return 0;
}
