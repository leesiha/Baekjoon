#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack <int> st;
queue <int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int order;
    for (int i=0; i<N; i++)
    {
        cin >> order;
        q.push(order);
    }

    int wait_num = 1;
    while (wait_num != N)
    {
        // check
        // if (!q.empty()) cout << "\nq top : " << q.front() << endl;
        // if (!st.empty()) cout << "\nst top : " << st.top() << endl;

        if (!st.empty() && (st.top() == wait_num))
        {
            st.pop();
            wait_num++;
            continue;
        }
        else if(!q.empty() && (q.front() == wait_num))
        {
            q.pop();
            wait_num++;
            continue;
        }
        else
        {
            if (q.empty())
                break;
            int tmp = q.front();
            st.push(tmp);
            q.pop();
        }
    }
    if (wait_num == N)
        cout << "Nice" << endl;
    else cout << "Sad" << endl;
}