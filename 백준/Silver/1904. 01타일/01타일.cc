#include <iostream>
#include <array>
using namespace std;
size_t num;

int main()
{
    cin >> num;
    size_t *arr = new size_t[num + 1];
    arr[0] = 0; // 0 인덱스 미사용
    arr[1] = 1;
    arr[2] = 2;
    for (size_t i = 3; i <= num; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= 15746;
    }
    cout << arr[num];
    // 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지를 출력한다며...
    // 그러면 출력할 때만 15746으로 나눈다는 소리 아니냐고...
}