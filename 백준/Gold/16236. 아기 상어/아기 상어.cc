#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // sort 함수를 사용하기 위해 추가

using namespace std;
#define N_MAX 20

int N, shark_size = 2, shark_can_eat = 2;
int answer = 0; // 총 걸린 시간
int map[N_MAX + 1][N_MAX + 1];
int dx[] = {0, -1, 1, 0}; // 상좌우하
int dy[] = {-1, 0, 0, 1};

bool visited[N_MAX + 1][N_MAX + 1] = {
	false,
};

queue<pair<pair<int, int>, int>> q;
// i j (현재 위치), time (현재 소요된 시간)

void clear_visited()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visited[i][j] = false; // 방문 여부 초기화
	}
}

void userInput()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				q.push({{i, j}, 0}); // 상어 시작위치 잡기
				map[i][j] = 0; // 상어 위치 0으로 초기화
			}
		}
	}
}

void solution()
{
	while (!q.empty())
	{
		int q_size = q.size();						  // 같은 거리의 물고기들을 한 번에 처리하기 위해 큐의 크기 저장
		vector<pair<int, pair<int, int>>> candidates; // 먹을 수 있는 물고기 후보들 저장
		// clear_visited();

		for (int k = 0; k < q_size; k++)
		{
			int x = q.front().first.second;
			int y = q.front().first.first;
			int cnt = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int cur_x = x + dx[i];
				int cur_y = y + dy[i];

				if (cur_x >= 0 && cur_x < N && cur_y >= 0 && cur_y < N 
					&& !visited[cur_y][cur_x])
				{
					if (map[cur_y][cur_x] > shark_size) // 먹을 수 없음. 이동 불가능
						continue; 
					else if (map[cur_y][cur_x] == 0 || map[cur_y][cur_x] == shark_size)
					{ // 이동만 가능
						visited[cur_y][cur_x] = true;
						q.push({{cur_y, cur_x}, cnt + 1});
					}
					else
					{ // 먹을 수 있음. fish_size < shark_size
						candidates.push_back({cnt + 1, {cur_y, cur_x}});
					}
				}
			}
		}

		if (!candidates.empty()) 						// 먹을 수 있는 물고기가 있다면
		{
			// 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
			sort(candidates.begin(), candidates.end());
			// 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
			if (candidates.size() > 1)
			{
				for (int i = 1; i < candidates.size(); i++)
				{
					if (candidates[0].first == candidates[i].first)
					{
						if (candidates[0].second.first > candidates[i].second.first) // 가장 위에 있는 물고기
							candidates[0] = candidates[i];
						else if (candidates[0].second.first == candidates[i].second.first) // 가장 위에 있는 물고기가 여러마리라면
						{
							if (candidates[0].second.second > candidates[i].second.second) // 가장 왼쪽에 있는 물고기
								candidates[0] = candidates[i];
						}
					}
				}
			}

			// 내가 먹을 물고기의 위치
			int x = candidates[0].second.second;
			int y = candidates[0].second.first;
			int cnt = candidates[0].first; // 내가 그 물고기를 먹기까지 걸리는 시간

			map[y][x] = 0; // 물고기 먹기
			answer += cnt;	 // 전체 걸린 시간에 추가
			shark_can_eat--; // 상어의 남은 먹을 수 있는 물고기 수 감소
			if (shark_can_eat == 0)
			{ // 상어가 먹을 수 있는 물고기 수를 다 먹었다면 크기 증가
				shark_size++;
				shark_can_eat = shark_size;
			}
			while (!q.empty())
				q.pop();		 // 큐 비우기
			q.push({{y, x}, 0}); // 새로운 시작 지점으로 큐에 삽입
			clear_visited();	 // 방문 여부 초기화
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	userInput();
	solution();
	cout << answer << endl;
}
