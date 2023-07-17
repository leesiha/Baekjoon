// 참고 : https://twpower.github.io/137-heap-implementation-in-cpp
// 풀이 방법 - 최소힙 구현
#include <iostream>
#include <array>
#define HEAP_SIZE 1000000

using namespace std;

size_t heap[HEAP_SIZE]; // 편의를 위해 인덱스 1부터 사용
size_t heap_count;
void swap(size_t *a, size_t *b)
{
    size_t tmp = *a;
    *a = *b;
    *b = tmp;
}
void pop()
{
    if (heap_count == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << heap[1] << '\n';
        swap(heap[1], heap[heap_count]);
        heap_count--;

        size_t parent = 1, child = parent * 2;
        if (child + 1 <= heap_count)
            child = (heap[child] < heap[child + 1]) ? child : child + 1;

        while (child <= heap_count && (heap[parent] > heap[child]))
        {
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent * 2;
            if (child + 1 <= heap_count)
                child = (heap[child] < heap[child + 1]) ? child : child + 1;
        }
    }
}
void push(size_t num)
{
    heap[++heap_count] = num;

    size_t child = heap_count, parent = child / 2;
    while (child > 1 && (heap[parent] > heap[child]))
    {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = child / 2;
    }
}
void init()
{
    heap_count = 0;
}
size_t get_size()
{
    return heap_count;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t size, num;
    cin >> size;
    init();
    for (size_t i = 0; i < size; i++)
    {
        cin >> num;
        if (num == 0)
            pop();
        else
            push(num);
    }
}