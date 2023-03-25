#include <iostream>

using namespace std;

int main()
{
    unsigned T;
    cin >> T;
    cin.ignore();
    for (unsigned k = 0; k < T; k++)
    {
        string str;
        getline(cin, str);
        for (unsigned i = 0, j = 0; i < str.size(); i++)
        {
            while (str[j + 1]) // 공백 만날때까지 인덱스 밀기
            {
                if (str[j + 1] == ' ') // 다음 값이 공백이라면 탈출
                    break;
                j++;
            }
            i = j + 1; // 공백 다음 값 인덱스 가리키기
            while (str[j] != ' ')
            {
                cout << str[j];
                if (j == 0)
                    break;
                j--;
            }
            cout << ' ';
            j = i;
        }
        cout << "\n";
    }
}