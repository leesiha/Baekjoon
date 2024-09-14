#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, bool> save;
    
    save[words[0]] = true; 
    for (int i=1; i < words.size(); i++)
    {
        string prevWord = words[i-1];
        string word = words[i];
        
        if (save[word] || prevWord.back() != word.front())
        {
            int person = (i+1) % n;
            if (!person) person = n;
            int round = ceil((i+1) / (double)n);
            return {person, round};
        }
        save[word] = true;
    }
    return {0, 0};
}