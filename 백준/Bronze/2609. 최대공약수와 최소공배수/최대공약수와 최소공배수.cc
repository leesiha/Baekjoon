// https://sectumsempra.tistory.com/77 참고함
#include <iostream>

using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    // 최대공약수 구하기
    int X, Y, GCD;
    if (A > B)
    {
        X = A;
        Y = B;
    }
    else
    {
        X = B;
        Y = A;
    }
    GCD = X % Y;
    while (GCD)
    {
        int tmp;
        tmp = Y % GCD;
        Y = GCD;
        GCD = tmp;
    }
    GCD = Y;

    // 최소공배수 구하기
    int LCM;
    LCM = (A * B / GCD) + (A * B % GCD);
    cout << GCD << "\n"
         << LCM;
}