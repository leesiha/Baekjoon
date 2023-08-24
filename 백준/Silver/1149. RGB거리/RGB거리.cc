// 참고 : https://www.acmicpc.net/board/view/103064
// 풀이 방법 - dp
#include <iostream>
#include <algorithm>
using namespace std;

int costSave[3], now[3]; //0:red 1:green 2:blue
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> now[j];
        int prev_red = costSave[0];
        int prev_green = costSave[1];
        int prev_blue = costSave[2];
        costSave[0] = min(prev_green, prev_blue) + now[0];
        costSave[1] = min(prev_red, prev_blue) + now[1];
        costSave[2] = min(prev_red, prev_green) + now[2];
    }

    cout << min(costSave[0], min(costSave[1], costSave[2])) << endl;
}