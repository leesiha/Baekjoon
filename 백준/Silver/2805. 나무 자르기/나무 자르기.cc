// 참고 : https://tooo1.tistory.com/123
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
size_t n, m, sawblade_height, top, bottom, result;
vector <size_t> forest;

int main()
{
    // cin.tie(NULL);
	// ios::sync_with_stdio(false);
    cin >> n >> m;
    size_t tmp;
    for (size_t i = 0; i < n; i++) //나무 높이 파악
    {
        cin >> tmp;
        forest.push_back(tmp);
    }
    
    top = *max_element(forest.begin(), forest.end());
    while (bottom <= top) // 상근이는 집에 필요한 나무를 항상 가져갈 수 있으므로 확정 톱날 높이가 존재한다.
    {
        size_t compare_with_m = 0;
        sawblade_height = (top + bottom) / 2;

        for (size_t i = 0; i < n; i++)
            if(sawblade_height < forest[i]) compare_with_m += forest[i] - sawblade_height;
        
        if (compare_with_m < m) // 계산치가 목표치보다 작을 경우 -> 톱날 높이 더 낮추세요
            top = sawblade_height - 1;
        else // 계산치가 목표치보다 크거나, 답을 찾은 경우 -> 일단 톱날 높이 더 높이세요
        {
            result = sawblade_height; // 현재 답이라고 추정되는 높이를 result에 저장
            bottom = sawblade_height + 1;
        }
    }
    cout << result;
}