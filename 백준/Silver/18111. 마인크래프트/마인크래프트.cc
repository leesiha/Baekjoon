// 참고 : https://luv-n-interest.tistory.com/1045
// 풀이 방법 - brute force
#include <iostream>
#include <array>

using namespace std;
int minTime = -1, height = -1;

void compareMin(int ct, int ch)
{
    if (minTime == -1)
    {
        minTime = ct;
        height = ch;
    }
    else
    {
        if (ct <= minTime && ch > height)
        {
            minTime = ct;
            height = ch;
        }
    }
}

int main()
{
    int N, M, B; // (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)
    cin >> N >> M >> B;

    // 맵 저장
    unsigned int **arr = new unsigned int*[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = new unsigned int[M];
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    // 땅의 높이는 0~256이므로, 0부터 해서 인벤토리 B의 조건을 확인하며 가능한지 확인
    // 가능하다면, 걸리는 시간 계산 후 min 시간과 비교. 같거나 작다면 result로 출력할 minTime과 height 값 갱신
    
    for (int ch = 0; ch <= 256; ch++) // compare height
    {
        int ct = 0; // compare time
        int cB = B; // check B
        // 맵 내 땅 하나씩 확인
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int spot = arr[i][j]; // 특정 spot의 높이
                spot = spot - ch;     // 현재 spot의 높이 - 기준 높이
                if (spot > 0)
                {
                    ct += 2 * spot; // 땅 깎기 실행
                    cB += spot;
                }
                else if (spot < 0)
                {
                    spot = -spot;
                    ct += spot; // 땅 채우기 실행
                    cB -= spot;
                }
            }
        }
        if (cB >= 0)
            compareMin(ct, ch);
    }
    cout << minTime << ' ' << height;
}