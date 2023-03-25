#include <iostream>
using namespace std;
int main()
{
    int mushroom, total = 0;
    int i, trash;
    for (i = 0; i < 10; i++)
    {
        cin >> mushroom;
        if (total < 100)
        {
            total += mushroom;
            if (total >= 100)
            {
                i++;
                break;
            }
        }
    }
    for (; i < 10; i++)
        cin >> trash;

    // 마지막 mushroom을 먹을지 말지 결정
    total = 100 - (total - mushroom) >= total - 100 ? total : total - mushroom;
    cout << total;
}