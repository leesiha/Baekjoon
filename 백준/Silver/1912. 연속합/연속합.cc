// 참고 : https://www.techiedelight.com/ko/find-min-or-max-value-in-a-vector-in-cpp/
// 참고 : https://mtoc.tistory.com/41
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
size_t n, sum;
int num;
vector <int> v;

int main()
{
    cin >> n;
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
    for (size_t i = 1; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        v[i] = max(v[i-1]+v[i], v[i]);
    }

    cout << *max_element(v.begin(), v.end());
}