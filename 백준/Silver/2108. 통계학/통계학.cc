#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define SIZE 8001
using namespace std;

size_t N;
int num; //입력되는 정수의 절댓값은 4,000을 넘지 않는다.

// 숫자 저장공간
double sum;
vector <int> v;
int arr[SIZE];

int find_mode(int arr[])
{
    int max = 0;
    vector <int> result;

    for (size_t i = 0; i < SIZE; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result.clear();
            result.push_back(i-4000);
        }
        else if (arr[i] == max)
        {
            result.push_back(i-4000);
        }
    }
    sort(result.begin(), result.end());
    if (result.size() > 1)
        return result[1];
    else
        return result[0];
}
int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
        arr[num + 4000]++;
        sum += num;
    }
    sort(v.begin(), v.end());

    // 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
    if ((sum / N) < 0 && (sum / N) > -1)
        printf("0\n");
    else
        printf("%.0f\n", sum / N);
    // 둘째 줄에는 중앙값을 출력한다.
    printf("%d\n", v[N/2]);
    // 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
    printf("%d\n", find_mode(arr));
    // 넷째 줄에는 범위를 출력한다.
    printf("%d\n", abs(v.back() - v.front()));
}