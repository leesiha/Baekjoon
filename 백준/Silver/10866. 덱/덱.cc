#include <iostream>
using namespace std;

#define SIZE 10000

class Deque
{
    int *arr;
    int capacity;
    int start;
    int end;
    int count;

public:
    Deque(int size = SIZE);
    ~Deque();

    void push_front(int x);
    void push_back(int x);
    int pop_front();
    int pop_back();
    int size();
    bool empty();
    void front();
    void back();
};

Deque::Deque(int size)
{
    arr = new int[size];
    capacity = size;
    start = 0;
    end = -1;
    count = 0;
}
Deque::~Deque()
{
    delete[] arr;
}

void Deque::push_front(int x)
{
    // 원래는 overflow 방지해줘야 한다. 근데 문제에서는 명령어가 10000줄까지만 나온다고 해서 따로 처리 안해줬다.
    start = (start - 1 + SIZE) % capacity;
    arr[start] = x;
    if (end == -1)
        end = start;
    count++;
}

void Deque::push_back(int x)
{
    // 원래는 overflow 방지해줘야 한다. 근데 문제에서는 명령어가 10000줄까지만 나온다고 해서 따로 처리 안해줬다.
    end = (end + 1) % capacity;
    arr[end] = x;
    count++;
}

int Deque::pop_front()
{
    int num;
    // 언더플로 확인
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

int Deque::pop_back()
{
    int num;
    // 언더플로 확인
    if (empty())
        cout << -1 << endl;
    else
    {
        num = arr[end];
        cout << num << endl;
        end = (end - 1 + SIZE) % capacity;
        count--;
        return num;
    }
    return -1;
}

int Deque::size()
{
    cout << count << endl;
    return count;
}
bool Deque::empty()
{
    if (count)
        return false;
    else
        return true;
}
void Deque::front()
{
    if (empty())
        cout << -1 << endl;
    else
        cout << arr[start] << endl;
    return;
}
void Deque::back()
{
    if (empty())
        cout << -1 << endl;
    else
        cout << arr[end] << endl;
    return;
}

int main()
{
    Deque q(10000);
    int N;
    string instruction;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> instruction;
        if (instruction == "push_front")
        {
            int num;
            cin >> num;
            q.push_front(num);
        }
        else if (instruction == "push_back")
        {
            int num;
            cin >> num;
            q.push_back(num);
        }
        else if (instruction == "pop_front")
            q.pop_front();
        else if (instruction == "pop_back")
            q.pop_back();
        else if (instruction == "size")
            q.size();
        else if (instruction == "empty")
            if (q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        else if (instruction == "front")
            q.front();
        else if (instruction == "back")
            q.back();
    }
}