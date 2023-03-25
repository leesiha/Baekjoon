#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    vector<string> people, v;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        people.push_back(name);
    }
    sort(people.begin(), people.end());
    for (int i = 0; i < M; i++)
    {
        string name;
        cin >> name;
        if(binary_search(people.begin(), people.end(), name))
            v.push_back(name);
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (vector<string>::iterator iter = v.begin(); iter < v.end(); iter++)
        cout << *iter << endl;
}