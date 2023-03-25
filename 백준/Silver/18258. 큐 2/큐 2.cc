#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    int N;
    string instruction;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> instruction;
        if (instruction == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (instruction == "pop")
        {
            if(q.empty())
                printf("-1\n");
            else
            {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (instruction == "size")
            printf("%lu\n",  q.size());
        else if (instruction == "empty")
        {
            if(q.empty())
                printf("1\n");
            else
                printf("0\n");
        }
        else if (instruction == "front")
        {
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }
        else if (instruction == "back")
        {
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
    }
}