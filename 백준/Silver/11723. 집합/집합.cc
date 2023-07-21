// 참고 : https://mangu.tistory.com/34
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <size_t> S;
void add(size_t x);
void remove(size_t x);
bool check(size_t x);
void toggle(size_t x);
void all();
void empty();

/*
add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.
*/

void empty()
{
    for (size_t i = 1; i <= 20; i++)
        remove(i);
}

void all()
{
    for (size_t i = 1; i <= 20; i++)
        add(i);
}


bool check(size_t x)
{
    if (find(S.begin(), S.end(), x) == S.end())
        return false;
    return true;
}

void toggle(size_t x)
{
    if (!check(x))
        S.push_back(x);
    else
        remove(x);
}

void add(size_t x)
{
    if (!check(x))
        S.push_back(x);
}

void remove(size_t x)
{
    if (check(x))
        S.erase(remove(S.begin(), S.end(), x), S.end());
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    size_t count;
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        string s;
        cin >> s;
        if (s == "all")
            all();
        else if (s == "empty")
            empty();
        else
        {
            int x;
            cin >> x;
            if (s == "add")
                add(x);
            else if (s == "remove")
                remove(x);
            else if (s == "check")
            {
                if(!check(x))
                    cout << 0 << '\n';
                else
                    cout << 1 << '\n';
            }
            else if (s == "toggle")
                toggle(x);
        }
    }
    
}