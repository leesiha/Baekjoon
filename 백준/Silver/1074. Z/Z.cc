// 참고 : https://donggoolosori.github.io/2020/09/22/boj-1074-Z/
// 풀이 방법 - 분할정복 (재귀... 어렵다..^^)
#include <iostream>

using namespace std;

size_t N, r, c, ans;
void Z(size_t row_now, size_t col_now, size_t max_length)
{
    if (row_now == r && col_now == c)
    {
        cout << ans << endl;
        return ;
    }
    // 현재 위치가 (r,c)가 아니라면, 현재 배열의 범위 내에 속하는지 확인이 필요.
    if (row_now <= r && row_now+max_length-1 >= r && col_now <= c && col_now+max_length-1 >= c)
    {
        // 현재 크기를 4분할
        size_t len = max_length / 2; // 길이 반으로 줄이기
        Z(row_now, col_now, len); // 좌측 상단
        Z(row_now, col_now+len, len); // 우측 상단
        Z(row_now+len, col_now, len); // 좌측 하단
        Z(row_now+len, col_now+len, len); // 우측 하단
    }
    else
    {
        // 속하지 않는다면, 무조건 현재 탐색하고 있는 위치보다 더 상위 인덱스일것임. -> 우리가 탐색을 좌측 상단부터 하니까!
        ans += max_length * max_length;
    }
}
int main()
{
    cin >> N >> r >> c;
    // 2^N * 2^N 배열 크기 구하기
    Z(0, 0, (1 << N)); // pow가 필요 없구나 ㄷㄷ
}