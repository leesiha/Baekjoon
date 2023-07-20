// 참고 : 
// 풀이 방법 - 재귀
#include <iostream>

using namespace std;

size_t A, B;
bool can_make_B = false;

void start(size_t num, size_t count)
{
    if (num < B)
    {
        start(num * 2, count + 1);
        start(num * 10 + 1, count + 1);
    }
    if (num > B)
        return;
    if (num == B)
    {
        can_make_B = true;
        cout << count + 1;
    }
}

int main()
{
    cin >> A >> B;

    start(A, 0);
    if (can_make_B == false)
        cout << -1;
}