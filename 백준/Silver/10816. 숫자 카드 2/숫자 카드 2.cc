#include <iostream>

using namespace std;
int range[20000001];
size_t N, M;
int tmp;

int main()
{
    //망할 시간초과...
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> tmp;
        range[tmp + 10000000]++;
    }
    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> tmp;
        cout << range[tmp + 10000000] << ' ';
    }
}