#include <string>
#include <vector>
#include <map>

using namespace std;
#define DIRECTION 8
int dx[DIRECTION] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[DIRECTION] = {-1, 0, 1, -1, 1, -1, 0, 1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    answer = n * n;
    // 지뢰 및 위험지대 칸 세서 빼기
    map<pair<int, int>, bool> danger;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (board[i][j] == 1)
            {
                danger[{i,j}] = true;
                for (int pos=0; pos < DIRECTION; pos++)
                {
                    int cur_i = i + dy[pos];
                    int cur_j = j + dx[pos];
                    if (cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= n) continue;
                    else danger[{cur_i,cur_j}] = true;
                }
            }
        }
    }
    return answer - danger.size();
}