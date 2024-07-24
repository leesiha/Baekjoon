#include <iostream>
#include <vector>

using namespace std;

int dice[6] = {0, 0, 0, 0, 0, 0};

// Initial dice state
int *bottom = &dice[0]; // 1
int *north = &dice[1];  // 2
int *east = &dice[2];   // 3
int *west = &dice[3];   // 4
int *south = &dice[4];  // 5
int *top = &dice[5];    // 6

auto rollEast = []()
{
    int temp = *top;
    *top = *west;
    *west = *bottom;
    *bottom = *east;
    *east = temp;
    // North and South do not change
};

auto rollWest = []()
{
    int temp = *top;
    *top = *east;
    *east = *bottom;
    *bottom = *west;
    *west = temp;
    // North and South do not change
};

auto rollNorth = []()
{
    int temp = *top;
    *top = *south;
    *south = *bottom;
    *bottom = *north;
    *north = temp;
    // East and West do not change
};

auto rollSouth = []()
{
    int temp = *top;
    *top = *north;
    *north = *bottom;
    *bottom = *south;
    *south = temp;
    // East and West do not change
};

int main()
{
    int N, M, x, y, K;
    // 여러 번 틀린 이유 : https://www.acmicpc.net/board/view/23937

    cin >> N >> M >> x >> y >> K; // 행, 열, 행, 열, 명령의 개수
    vector<vector<int>> map(N, vector<int>(M));

    for (auto &row : map)
    {
        for (auto &cell : row)
        {
            cin >> cell;
        }
    }

    while (K--)
    {
        int move;
        cin >> move;

        int newX = x, newY = y;

        switch (move)
        {
        case 1: // East
            newY++;
            if (newY >= 0 && newY < M)
            {
                rollEast();
                if (map[newX][newY] == 0) // 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
                    map[newX][newY] = *bottom;
                else { // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
                    *bottom = map[newX][newY];
                    map[newX][newY] = 0;
                }
                y = newY;
            break;
            }
            continue;
        case 2: // West
            newY--;
            if (newY >= 0 && newY < M)
            {
                rollWest();
                if (map[newX][newY] == 0)
                    map[newX][newY] = *bottom;
                else {
                    *bottom = map[newX][newY];
                    map[newX][newY] = 0;
                }
                y = newY;
            break;
            }
            continue;
        case 3: // North
            newX--;
            if (newX >= 0 && newX < N)
            {
                rollNorth();
                if (map[newX][newY] == 0)
                    map[newX][newY] = *bottom;
                else {
                    *bottom = map[newX][newY];
                    map[newX][newY] = 0;
                }
                x = newX;
            break;
            }
            continue;
        case 4: // South
            newX++;
            if (newX >= 0 && newX < N)
            {
                rollSouth();
                if (map[newX][newY] == 0)
                    map[newX][newY] = *bottom;
                else {
                    *bottom = map[newX][newY];
                    map[newX][newY] = 0;
                }
                x = newX;
            break;
            }
            continue;
        default:
            break;
        }
        cout << *top << '\n';
    }
}
