#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int r, c, d; // 0:N 1:E 2:S 3:W

void startMoving(vector< vector<int> >& room);
int logicOne(vector< vector<int> >& room);
int logicTwo(const vector< vector<int> >& room);
int logicThree(const vector< vector<int> >& room);

int main()
{
    //첫째 줄에 방의 크기 N과 M이 입력된다. 
    int N, M;
    cin >> N >> M;
    vector< vector<int> > room(N, vector<int>(M));

    //둘째 줄에 처음에 로봇 청소기가 있는 칸의 좌표 (r, c)와 처음에 로봇 청소기가 바라보는 방향 d가 입력된다.
    cin >> r >> c >> d;

    //셋째 줄부터 N개의 줄에 각 장소의 상태를 나타내는 N * M개의 값이 한 줄에 M개씩 입력된다.
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        { 
            cin >> room[i][j];
        }
    }

    //로봇 청소기가 작동을 시작한 후 작동을 멈출 때까지 청소하는 칸의 개수를 출력한다.
    startMoving(room);

    cout << answer << "\n";
}

void startMoving(vector< vector<int> >& room)
{
    int choice = 1;

    while (choice)
    {
        switch (choice) {
            case 1:
                choice = logicOne(room);
                break;
            case 2:
                choice = logicTwo(room);
                break;
            case 3:
                choice = logicThree(room);
                break;
        }
    }

}

int logicOne(vector< vector<int> >& room)
{
    if (room[r][c] == 0)
    {
        room[r][c] = 2; //clean
        answer++;
    }
    return 2;
}

int logicTwo(const vector< vector<int> >& room)
{
    int dx[4] = {0, -1, 0, 1}; // 한 칸 후진을 고려 (S-W-N-E)
    int dy[4] = {1, 0, -1, 0};
    int mx, my;
    for (int i=0; i<4; i++)
    {
        mx = c + dx[i];
        my = r + dy[i];
        if (room[my][mx] == 0)
            return 3;
    }
    mx = c + dx[d];
    my = r + dy[d];
    if (room[my][mx] == 1)
        return 0;
    r = my;
    c = mx;
    return 1;
}

int logicThree(const vector< vector<int> >& room)
{
    //반시계 방향으로 90도 회전
    d--;
    if (d < 0) d = 3;

    //바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우
    int dx[4] = {0, 1, 0, -1}; // N-E-S-W
    int dy[4] = {-1, 0, 1, 0};
    int mx, my;
    mx = c + dx[d];
    my = r + dy[d];
    if (room[my][mx] == 0)
    {
        r = my;
        c = mx;
    }
    return 1;
}