// 참고 : https://devlog-wjdrbs96.tistory.com/160
// DP
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a, b;
    cin >> a >> b;
    // 동적 할당
    int** arr = new int*[a.size() + 1];
    for (size_t i = 0; i <= a.size(); i++)
        arr[i] = new int[b.size() + 1];
    
    // 0 인덱스 미사용
    for (size_t i = 0; i <= a.size(); i++)
        arr[i][0] = 0;
    for (size_t j = 0; j <= b.size(); j++)
        arr[0][j] = 0;
    
    // DP 시작
    for (size_t i = 1; i <= a.size(); i++)
    {
        for (size_t j = 1; j <= b.size(); j++)
        {
            if (a[i-1] == b[j-1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
        }
    }
    cout << arr[a.size()][b.size()] << endl; //결과 출력
    // 전체 배열 출력
    // for (size_t i = 0; i <= a.size(); i++)
    // {
    //     for (size_t j = 0; j <= b.size(); j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
}
