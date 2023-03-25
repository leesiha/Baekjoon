#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        v.push_back(i);
    int j = -1;
    cout << '<';
    while (v.size() != 1)
    {
        for (int i = 1; i <= K; i++)
        {
            j++;
            if (j >= (int)v.size())
                j = 0;
        }
        cout << v[j] << ", ";
        v.erase(v.begin() + j);
        j--;
    }
    cout << v.back() << '>' << endl;
}