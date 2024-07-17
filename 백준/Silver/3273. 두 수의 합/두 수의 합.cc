#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입력받기
    int n, x, answer = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> x;

    // 해결
    sort(v.begin(), v.end());
    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = v[left] + v[right];
        if (sum == x)
        {
            answer++;
            left++;
            right--;
        }
        else if (sum < x)
            left++;
        else
            right--;
    }

    cout << answer;
}
