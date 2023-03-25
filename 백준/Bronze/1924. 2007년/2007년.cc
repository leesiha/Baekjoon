#include <iostream>

using namespace std;
int add_days(int month)
{
    switch (month)
    {
    case 1:
        return 31;
    case 2:
        return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return 0;
    }
}
string result[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main()
{
    int x, y, days = 0;
    cin >> x >> y;
    for (int i = 1; i < x; i++)
    {
        days += add_days(i);
    }
    days += y;
    cout << result[days % 7];
}