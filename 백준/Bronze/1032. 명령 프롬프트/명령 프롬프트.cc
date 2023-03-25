#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string result = "";
    for (unsigned i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        if (result == "")
            result = tmp;
        else
        {
            int i = 0;
            while (i < tmp.size() || i < result.size())
            {
                if (result[i] != tmp[i])
                    result[i] = '?';
                i++;
            }
            result[i] = 0;
        }
    }
    cout << result;
}