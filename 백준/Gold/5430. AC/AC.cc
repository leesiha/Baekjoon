// 참고 :
// 풀이 방법 - 구현
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

string order, arr;
int arr_len;
deque<int> dq;
bool error_occurred, doR;

void orderR()
{
    reverse(dq.begin(), dq.end());
}

void orderD(bool doR)
{
    if (dq.empty())
    {
        error_occurred = true;
        return;
    }
    if (doR)
        dq.pop_back();
    else
        dq.pop_front();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        error_occurred = doR = false;
        dq.clear();
        cin >> order >> arr_len >> arr;

        // string arr 파싱
        int num = 0;
        for (size_t i = 1; i < arr.length(); i++)
        {
            if (arr[i] == ',' || arr[i] == ']')
            {
                // cout << "put " << num << endl;
                if (num)
                    dq.push_back(num);
                num = 0;
            }
            else
            {
                num *= 10;
                num += arr[i] - '0';
            }
        }

        // R(뒤집기) 혹은 D(버리기) 수행
        for (size_t i = 0; i < order.length(); i++)
        {
            // cout << "order is " << order[i] << endl;
            if (order[i] == 'D')
            {
                orderD(doR);
                if (error_occurred)
                    break;
            }
            else if (order[i] == 'R')
                doR = !doR;
        }
        if (doR)
            orderR();
        
        // 출력
        if (error_occurred)
            cout << "error" << endl;
        else
        {
            cout << '[';
            if (!dq.empty())
            {
                for (size_t i = 0; i < dq.size() - 1; i++)
                {
                    cout << dq[i] << ',';
                }
                cout << dq.back();
            }
            cout << ']' << endl;
        }
    }
}