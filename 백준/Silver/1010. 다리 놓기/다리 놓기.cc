#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N >> M; // MCN (0 < N ≤ M < 30)
        unsigned long long result = 1;
        if (N != M)
        {
            N = min(N, M - N);
            for (int i = 0; i < N; i++)
                result *= M--;
            while (N)
                result /= N--;
        }
        cout << result << endl;
    }
}