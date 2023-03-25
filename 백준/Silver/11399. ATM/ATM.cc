#include <iostream>
#include <algorithm>
using namespace std;

int people[1000];

int main(void)
{
    int N, waiting, sum;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> people[i];
    }
    sort(people, people + N);
    waiting = sum = people[0];

    for (int i = 1; i < N; i++)
    {
        waiting = waiting + people[i];
        sum += waiting;
    }
    cout << sum;
}