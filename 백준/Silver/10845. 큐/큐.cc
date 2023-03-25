#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define SIZE 10000

class Queue
{
    int *arr;
    int capacity;
    int start;
    int end;
    int count;

public:
    Queue(int size = SIZE);
    ~Queue();

    void push(int x);
    int pop();
    int size();
    bool empty();
    void front();
    void back();
};

Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    start = 0;
    end = -1;
    count = 0;
}
Queue::~Queue()
{
    delete[] arr;
}

void Queue::push(int x)
{
    //원래는 overflow 방지해줘야 한다. 근데 문제에서는 명령어가 10000줄까지만 나온다고 해서 따로 처리 안해줬다.
    end = (end + 1) % capacity;
    arr[end] = x;
    count++;
}
int Queue::pop()
{
    int num;
    //언더플로 확인
    if (empty())
        cout << -1 << endl;
    else
    {
        num = arr[start];
        cout << num << endl;
        start = (start + 1) % capacity;
        count--;
        return num;
    }
    return -1;
}
int Queue::size()
{
    cout << count << endl;
    return count;
}
bool Queue::empty()
{
    if (count)
        return false;
    else
        return true;
}
void Queue::front()
{
    if (empty())
        cout << -1 << endl;
    else
        cout << arr[start] << endl;
    return;
}
void Queue::back()
{
    if (empty())
        cout << -1 << endl;
    else
        cout << arr[end] << endl;
    return;
}
int main()
{
    Queue q(10000);
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
            q.pop();
        else if (instruction == "size")
            q.size();
        else if (instruction == "empty")
            if(q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        else if (instruction == "front")
            q.front();
        else if (instruction == "back")
            q.back();
    }
}