#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int SG[500001] = {0,};
    int N, M;
    cin >> N;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> SG[i];
    }
    sort(SG, SG + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        if (binary_search(SG, SG+N, num))
            cout << "1 ";
        else
            cout << "0 ";
    }
}