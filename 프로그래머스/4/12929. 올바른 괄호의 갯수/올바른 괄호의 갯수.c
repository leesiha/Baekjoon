#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int DFS(int open, int close, int n)
{
    if (open == n) return 1;
    else if (open < close) return 0;
    int num = 0;
    num += DFS(open+1, close, n);
    num += DFS(open, close+1, n);
    return num;
}
// int count(int n)
// {
//     if (n == 1) return 1;
//     return count(n-1) * 2; //감싸기, 옆에 붙이기
// }
int solution(int n) {
    int answer = DFS(0,0,n);
    return answer;
}