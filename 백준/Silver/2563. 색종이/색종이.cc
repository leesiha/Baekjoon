#include <iostream>

using namespace std;
bool paper[100][100]; // 0 ~ 99

// 첫 번째 자연수는 색종이의 왼쪽 변과 도화지의 왼쪽 변 사이의 거리이고,
// 두 번째 자연수는 색종이의 아래쪽 변과 도화지의 아래쪽 변 사이의 거리
// 즉,
// 첫 번째 자연수는 열 인덱스
// 두 번째 자연수는 99 - 행 인덱스
void paint(size_t a, size_t b)
{
    for (size_t i = 0; i < 10; i++) // 행
        for (size_t j = 0; j < 10; j++) //열
            paper[a + i][99-b + j] = true;
}

int main()
{
    size_t n, a, b, result = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a >> b;
        paint(a, b);
    }

    for (size_t i = 0; i < 100; i++) // 행
        for (size_t j = 0; j < 100; j++)  // 열
            if (paper[i][j]) result++;
    cout << result;
}