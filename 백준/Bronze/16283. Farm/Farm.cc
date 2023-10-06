// 참고 : 
// 
#include <iostream>
using namespace std;

int I, J;
int main()
{
    int a, b, n, w;
    cin>>a>>b>>n>>w;
    int flag = 0; //0:notfound 1:1sol 2:multiplesol
    for (int i = 1; i < n; i++)
    {
        int j = n - i;
        if (i * a + j * b == w && i + j == n && i != n)
        {
            if (flag == 0)
            {
                flag = 1;
                I = i;
                J = j;
            }
            else if (flag == 1)
                flag = 2;
        }
        
    }
    if (flag == 1)
        cout << I << ' ' << J << endl;
    else
        cout << -1 <<endl;
    return 0;
}
