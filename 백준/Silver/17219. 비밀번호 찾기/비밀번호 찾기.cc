#include <iostream>
#include <map>

using namespace std;

size_t n, m;
map <string, string> save;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    string URL, PW;
    for (size_t i = 0; i < n; i++)
    {
        cin >> URL >> PW;
        save[URL] = PW;
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> URL;
        cout << save[URL] << endl;
    }
}