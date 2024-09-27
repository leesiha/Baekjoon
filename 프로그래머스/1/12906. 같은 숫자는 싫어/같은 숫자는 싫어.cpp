#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    answer.push_back(arr[0]);
    for (auto i:arr)
    {
        if (answer.back() != i)
            answer.push_back(i);
    }

    return answer;
}