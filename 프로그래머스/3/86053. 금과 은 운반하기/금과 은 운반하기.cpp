#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct City {
    int gold, silver, capacity, travel_time;
};

//  금, 은 자원 옮기기를 해당 시간 이내에 할 수 있는지 확인
bool canDeliverInTime(long long time, int a, int b, const vector<City>& cities) {
    long long total_gold = 0, total_silver = 0, total_both = 0;
    
    for (const auto& city : cities) {
        long long round_trip_time = city.travel_time * 2;
        long long max_trips = time / round_trip_time;
        
        if (time % round_trip_time >= city.travel_time) {
            max_trips += 1;
        }
        
        long long max_gold = min((long long)city.gold, max_trips * city.capacity);
        long long max_silver = min((long long)city.silver, max_trips * city.capacity);
        long long max_both = min((long long)(city.gold + city.silver), max_trips * city.capacity);
        
        total_gold += max_gold;
        total_silver += max_silver;
        total_both += max_both;
        
        if (total_gold >= a && total_silver >= b && total_both >= a+b) return true;
    }
    return total_gold >= a && total_silver >= b && total_both >= a + b;
}


long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = LLONG_MAX;
    long long right = 1e16, left = 0, mid;
    
//     각 도시 정보를 구조체로 묶어 정렬
    vector<City> cities;
    for (size_t i=0; i<g.size(); i++) {
        cities.push_back({g[i], s[i], w[i], t[i]});
    }
//     이동시간 대비 운반용량 효율이 높은 도시 순으로 정렬
    sort(cities.begin(), cities.end(), [](const City& a, const City& b) {
//         a의 운반시간 / a의 적재용량 < b의 운반시간 / b의 적재용량
//         왕복 시간이 짧으면서 운반 용량이 큰 도시의 트럭이 우선적으로 자원을 운반
        return (a.travel_time * b.capacity) < (b.travel_time * a.capacity);
    });
    
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (canDeliverInTime(mid, a, b, cities)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return answer;
}
