#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long distance(int x, int d)
{
    return floor(sqrt(pow(d, 2) - pow(x, 2)));
}

long long solution(int k, int d) {
    long long answer = 0;
    for (int a=0; a<=d; a+=k)
    {
        answer += (distance(a, d) / k) + 1;
    }
    return answer;
}