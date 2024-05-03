#include <iostream>

using namespace std;

int arr[26]; // 26개의 알파벳을 저장할 배열
int main()
{
    string s;
    cin >> s;
    for (size_t i = 0; i < s.length(); i++)
        arr[s[i]-'a']++; // 해당 알파벳의 개수를 증가시킨다.
    for (size_t i = 0; i < 26; i++)
        cout << arr[i] << " "; // 알파벳의 개수를 출력한다.
}