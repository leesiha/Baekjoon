#include <iostream>
#include <numeric>
using namespace std;
int coordinate_system[100][100];
int main()
{
    int x1, y1, x2, y2;
    int result = 0;
    for (int k = 0; k < 4; k++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y2; i > y1; i--)
        {
            for (int j = x1; j < x2; j++)
            {
                if (!coordinate_system[i][j])
                {
                    result++;
                    coordinate_system[i][j] = 1;
                }
            }
        }
    }
    cout << result << endl;
}