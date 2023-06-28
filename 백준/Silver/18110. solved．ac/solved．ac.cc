#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
size_t num;
double n, result;
vector <size_t> v;

// 제외되는 사람의 수
// 30% 절사평균

int main()
{
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    
    for (size_t i = 0; i < n; i++)
    {
        size_t tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    num = round(n * 0.15);
    for (size_t i = num; i < n-num; i++)
        result += v[i];
    cout << round(result / (n - num * 2));
}