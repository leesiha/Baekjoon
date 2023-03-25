#include <iostream>

using namespace std;
int main()
{
    int A, B;
    cin >> A >> B; //[A, B] 범위의 숫자 합 구하기
    long long result = 0, count = 0;
    for (unsigned i = 1; i <= 1000; i++)
    {
        for (unsigned j = 1; j <= i; j++) // i가 반복되는 횟수
        {
            count++;
            if (count > B)
            {
                cout << result;
                return 0;
            }
            else if (count >= A && count <= B)
                result += i;
        }
    }
}