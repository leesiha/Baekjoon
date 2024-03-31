#include <iostream>
#include <vector>

using namespace std;
vector<long long> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, A, B, C, result=0;

    cin >> N;
    for (long long i = 0; i < N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
    cin >> B >> C;

    for (long long i = 0; i < N; i++)
    {
        v[i] -= B;
        result++;
        if (v[i] > 0)
        {
            long long tmp = v[i] / C;
            if (v[i] % C)
                result += tmp + 1;
            else
                result += tmp;
        }
    }
    cout << result << '\n';
}