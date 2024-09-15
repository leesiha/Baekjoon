#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = -1, luy = -1, rdx = -1, rdy = -1;
    bool init = true;
    // lux : 최상단(min) row
    // rdx : 최하단(max) row
    // luy : 최좌측(min) col
    // rdy : 최우측(max) col
    
    for (int i=0; i<wallpaper.size(); i++)
    {
        for (int j=0; j<wallpaper[i].length(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (init) 
                {
                    lux = rdx = i;
                    luy = rdy = j;
                    init = false;
                }
                else
                {
                    rdx = i;
                    luy = min(luy, j);
                    rdy = max(rdy, j);
                }
            }
        }
    }
    answer = {lux, luy, rdx+1, rdy+1};
    return answer;
}