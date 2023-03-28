// 참고  : https://cryptosalamander.tistory.com/35
// 떨어진 점들의 집합 -> 원 이 만들어진다는 걸 알아차리지 못했다
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2, d1, d2;
        cin >> x1 >> y1 >> d1 >> x2 >> y2 >>  d2;
        int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int distance2 = (d1 + d2) * (d1 + d2);
        int distance3 = (d1 - d2) * (d1 - d2);

        // distance == (d1 + d2)^2 -> 두 원이 접한다 -> 답이 1개
        // distance < (d1 + d2)^2 -> 두 원이 겹친다 -> 답이 2개
        // distance > (d1 + d2)^2 -> 두 원이 접하지 않는다 -> 답이 0개
        // distance == 0 && d1 == d2 -> 두 원이 같다 -> 답이 무한개
        if(distance == 0)
        {
            if (d1 == d2) cout << -1 << endl;
            else cout << 0 << endl; // 거리 계산 오류들도 전부 답 0개로 처리
        }
        else
        {
            if (distance == distance2 || distance == distance3) cout << 1 << endl;
            else if ((distance < distance2) && (distance > distance3)) cout << 2 << endl; //(distance > distance3) 이걸 못잡아서 계속 틀렸다
            else cout << 0 << endl; // 거리 계산 오류들도 전부 답 0개로 처리
        }
    }
}