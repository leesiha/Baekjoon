// 참고 : https://donggoolosori.github.io/2020/09/26/boj-18870/, https://chanhuiseok.github.io/posts/algo-55/
// 풀이 방법 - vector unique, erase
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    size_t N;
    cin >> N;
    vector<long long> v(N);

    for (size_t i = 0; i < N; i++)
        cin >> v[i];

    vector<long long> v_copy(v);
    sort(v_copy.begin(), v_copy.end());
    v_copy.erase(unique(v_copy.begin(), v_copy.end()), v_copy.end());

    for (size_t i = 0; i < N; i++)
    {
        cout << lower_bound(v_copy.begin(), v_copy.end(), v[i]) - v_copy.begin() << ' ';
    }
    
}