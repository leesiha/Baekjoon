#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int charToNum(char c)
{
    int num = c - '0';
    if (num >= 1 && num <= 9)
        return num;
    return 0;
}

int bfs(vector<string> &maps, int row, int col)
{
    int total = 0;
    int rowLength = maps.size();
    int colLength = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({row, col});
    total += charToNum(maps[row][col]);
    maps[row][col] = 'X';
    
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int curR = row + dy[i];
            int curC = col + dx[i];
            if (curC >= 0 && curR >= 0 && curR < rowLength && curC < colLength)
            {
                if (maps[curR][curC] == 'X')
                    continue;
                total += charToNum(maps[curR][curC]);
                maps[curR][curC] = 'X';
                q.push({curR, curC});
            }
        }
    }
    return total;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i=0; i<maps.size(); i++)
    {
        for (int j=0; j<maps[i].size(); j++)
        {
            if (maps[i][j] != 'X')
            {
                answer.push_back(bfs(maps, i, j));
            }
        }
    }
    if (answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}