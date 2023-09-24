// 참고 : 
//
#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

vector <pair <int, int> > home;
vector <pair <int, int> > chicken;
vector <pair <int, int> > selected;
int N, M, chicken_dist = MAX;
int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int idx)
{
    if (selected.size() == M)
    {
        int tmp = 0;
        for (int i = 0; i < home.size(); i++)
        {
            int dist = MAX;
            for (int j = 0; j < selected.size(); j++)
            {
                dist = min(dist, distance(home[i].first, home[i].second, selected[j].first, selected[j].second));
            }
            tmp += dist;
        }
        chicken_dist = min(chicken_dist, tmp);
        return;
    }
    for (int i = idx; i < chicken.size(); i++)
    {
        selected.push_back(chicken[i]);
        dfs(i + 1);
        selected.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        for (int j = 0; j < N; j++)
        {
            cin >> tmp;
            if (tmp == 1)
                home.push_back(make_pair(i, j));
            else if (tmp == 2)
                chicken.push_back(make_pair(i, j));
        }
    }
    dfs(0);
    cout << chicken_dist << endl;
    return 0;
}