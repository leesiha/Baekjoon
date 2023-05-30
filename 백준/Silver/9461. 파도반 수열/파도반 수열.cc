#include <iostream>

using namespace std;

size_t getPadovan(size_t N)
{
    size_t arr[101] = {1, 1, 1, 2, 2};

    for (size_t i = 5; i < N; i++)
    {
        arr[i] = arr[i-1] + arr[i-5];
    }
    return arr[N-1];
}

int main()
{
    size_t T, N;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> N;
        cout << getPadovan(N) << endl;
    }
    
}