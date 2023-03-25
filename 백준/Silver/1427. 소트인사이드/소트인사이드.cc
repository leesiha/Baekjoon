#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(char a, char b) { return a > b; };
int main()
{
    char N[11];
    cin >> N;
    sort(N, N + strlen(N), compare);
    cout << N;
}