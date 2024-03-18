// 참고 : https://baebalja.tistory.com/350
// Floyd-Worshall 알고리즘을 사용하면 시간복잡도가 O(N^3)이므로 N이 1000이하일 때 사용 가능하다.

#include <iostream>
#include <algorithm>

#define MAX 100
using namespace std;

int n, m;
int info[MAX+1][MAX+1];

void floydWorshall()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                info[i][j] = min(info[i][j], info[i][k]+info[k][j]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int row, col, cost;

    fill(info[0], info[MAX+1], 987654321); // fill 사용 주의!!

    for (int i = 1; i <= n; i++) {
		info[i][i] = 0; 
	}

    for (int i = 0; i < m; i++)
    {
        cin >> row >> col >> cost;
        info[row][col] = min(info[row][col], cost); //시작 도시와 도착 도시를 연결하는 "노선은 하나가 아닐 수 있다"
    }
    floydWorshall();

    // 답 출력
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (info[i][j] == 987654321)
                cout << "0 ";
            else
                cout << info[i][j] << ' ';
        }
        cout << "\n";
    }
}
