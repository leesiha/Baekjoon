// 참고 : https://cryptosalamander.tistory.com/13
// brute force

#include <iostream>
using namespace std;
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string chessboard[50];

int WB_count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessboard[i+x][j+y] != WB[i][j])
                count++; 
        }
    }
    return count;
}

int BW_count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chessboard[i+x][j+y] != BW[i][j])
                count++; 
        }
    }
    return count;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> chessboard[i];
    
    int min = N * M;
    for (int i = 0; i+8 <= N; i++)
    {
        for (int j = 0; j+8 <= M; j++)
        {
            int wb = WB_count(i, j);
            int bw = BW_count(i, j);
            if (min > wb)
                min = wb;
            if (min > bw)
                min = bw;
        }
        
    }
    cout << min << endl;
}