#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int main()
{
    int height = 0, extra = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> height;
        extra += height;
        v.push_back(height);
    }
    sort(v.begin(), v.end());
    extra -= 100;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (v[i] + v[j] > extra)
                break;
            else if ((v[i] + v[j]) == extra)
            {
                v.erase(v.begin() + i);
                v.erase(v.begin() + j - 1);
                for (unsigned k = 0; k < v.size(); k++)
                    cout << v[k] << '\n';
                return 0;
            }
        }
    }
    cout << "no result";
}