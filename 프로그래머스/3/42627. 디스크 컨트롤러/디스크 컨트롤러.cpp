// 참고 : https://school.programmers.co.kr/questions/75351
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;


// 하드디스크가 작업을 수행하고 있지 않을 때에는 먼저 요청이 들어온 작업부터 처리
// 작업 중일때는 남은 작업 (최소 작업시간 순으로) 정렬
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int currentTime = 0;
    int completedJobs = 0;
    int totalWaitingTime = 0;
    
    // 요청 시간 순서와 작업 소요 시간을 기준으로 정렬
    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }); 
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int jobIndex = 0;
    while (completedJobs < jobs.size())
    {
        while (jobIndex < jobs.size() && jobs[jobIndex][0] <= currentTime)
        {
            pq.push({jobs[jobIndex][1], jobs[jobIndex][0]});
            jobIndex++;
        }
        
        if (pq.empty())
        {
            currentTime = jobs[jobIndex][0];
            continue;
        }
        vector<int> currentJob = pq.top();
        pq.pop();
        
        if (currentTime < currentJob[1]) currentTime = currentJob[1];
        totalWaitingTime += (currentTime - currentJob[1]) + currentJob[0];
        currentTime += currentJob[0];
        
        completedJobs++;
    }
    answer = totalWaitingTime / completedJobs;
    return answer;
}