// https://haula.tistory.com/entry/%EC%88%98%ED%95%99-1934%EB%B2%88-%EC%B5%9C%EC%86%8C%EA%B3%B5%EB%B0%B0%EC%88%98-C-%ED%92%80%EC%9D%B4%EB%B2%95 참고
#include <iostream>

using namespace std;

int getGCD(int x, int y) // 반드시 x > y 조건을 맞춰줘야한다
{
    if (x % y == 0)
        return y;
    else
        return getGCD(y, x % y);
}

int main()
{
    int N;
    cin >> N;
    int x, y;
    for (unsigned i = 0; i < N; i++)
    {
        cin >> x >> y;
        int GCD = x > y ? getGCD(x, y) : getGCD(y, x);
        int LCM = (x * y / GCD) + (x * y % GCD);
        cout << LCM << '\n';
    }
}