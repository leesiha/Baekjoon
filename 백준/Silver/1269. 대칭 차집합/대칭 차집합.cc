#include <iostream>
#include <map>

using namespace std;

map <unsigned int, bool> m;

int main()
{
    int aSize, bSize;
    unsigned int tmp;

    cin >> aSize >> bSize;
    for (int i=0; i<aSize; i++)
    {
        cin >> tmp;
        m[tmp] = true;
    }
    for (int i=0; i<bSize; i++)
    {
        cin >> tmp;
        if (m[tmp])
            m.erase(tmp);
        else m[tmp] = true;
    }
    cout << m.size();
}