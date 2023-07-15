// 참고 : https://yongmemo.tistory.com/21
// 풀이 방법 - 이진탐색
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    size_t K, N, now = 0;
    cin >> K >> N;
    vector <unsigned int> v;
    for (size_t i = 0; i < K; i++)
    {
        unsigned int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    // binary
    unsigned int left = 1, right, mid, answer = 0;
    // 가장 큰 값 right로 지정
    right = *max_element(v.begin(), v.end());

    while (left <= right)
    {
        mid = (left + right) / 2;
        now = 0;
        for (size_t i = 0; i < v.size(); i++)
        {
            now += v[i] / mid;
        }
        if (now < N)
        {
            right = mid - 1;
        }
        else if (now >= N)
        {
            left = mid + 1;
            answer = max(mid, answer);
        }
        else
            break;
    }
    cout << answer;
}