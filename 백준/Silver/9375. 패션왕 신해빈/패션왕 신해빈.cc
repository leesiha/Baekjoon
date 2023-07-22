#include <iostream>
#include <map>

using namespace std;

size_t test_case, n, result = 1;

int main()
{
    cin >> test_case;
    for (size_t i = 0; i < test_case; i++)
    {
        map<string, int> m;
        cin >> n;
        string cloth_name, cloth_kind;

        for (size_t i = 0; i < n; i++)
        {
            cin >> cloth_name >> cloth_kind;
            m[cloth_kind]++;
        }
        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            result *= (iter->second + 1);
        }
        cout << result - 1 << endl;
        result = 1;
    }
}