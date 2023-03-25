// 참고 : https://hagisilecoding.tistory.com/41
// 해시맵을 사용하는 것이 관건이다.
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    map<string, int> pokemon;
    vector<string> name;
    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str; 
        name.push_back(str); // 도감번호 주어질때 포켓몬 이름 찾기
        pokemon.insert(make_pair(str, i)); // 포켓몬 이름이 주어질때 도감번호 빠르게 찾기
    }
    vector<string> result; 
    for (int i = 0; i < M; i++)
    {
        string ask;
        cin >> ask;
        if (ask[0] >= 'A' && ask[0] <= 'Z')
            result.push_back(to_string(pokemon[ask]));
        else
        {
            result.push_back(name[stoi(ask)-1]);
        }
    }
    for (size_t i = 0; i < result.size();i++){
        cout << result[i] << '\n'; // 출력
    }
    return 0;
}