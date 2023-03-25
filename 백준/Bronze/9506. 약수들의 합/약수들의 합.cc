#include <iostream>
#include <vector>
using namespace std;
// 약수 구하기 알고리즘 : https://dnf-lover.tistory.com/entry/C-%EC%95%BD%EC%88%98%EB%A5%BC-%EA%B5%AC%ED%95%98%EB%8A%94-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%95%BD%EC%88%98%EB%A5%BC-%EA%B5%AC%ED%95%98%EB%8A%94-%EB%8B%A4%EC%96%91%ED%95%9C-%EB%B0%A9%EB%B2%95%EA%B3%BC-%EC%86%8C%EC%9D%B8%EC%88%98%EB%B6%84%ED%95%B4
vector<int> v;
bool factor(int a)
{
    int sum = 0;

    if (a <= 0)
        return false;

    for (int i = 1; i <= a / 2; i++)
        if (a % i == 0) // 약수
        {
            sum += i;
            v.push_back(i);
        }

    if (sum == a)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    while (n != -1)
    {
        if (factor(n))
        {
            cout << n << " = ";
            for (vector<int>::iterator iter = v.begin(); iter + 1 < v.end(); iter++)
            {
                cout << *iter << " + ";
            }
            cout << v.back() << endl;
        }
        else
        {
            cout << n << " is NOT perfect." << endl;
        }
        v.clear();
        cin >> n;
    }
}