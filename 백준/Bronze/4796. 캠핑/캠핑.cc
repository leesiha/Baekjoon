#include <iostream>
using namespace std;
int main()
{
    int L, P, V;
    int i = 1;
    while (i)
    {
        cin >> L >> P >> V;
        if (!(L && P && V))
            break;
        cout << "Case " << i << ": " << (V / P) * L + min(V % P, L) << "\n"; // V % P가 L보다 클 경우를 생각해주지 못했다. 참고 : https://eocoding.tistory.com/53
        i++;
    }
}