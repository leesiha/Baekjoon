#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map <string, string, greater <string>> log;
	int totalLog;
	cin >> totalLog;

	string name, currentState;
	for (int i = 0; i < totalLog; i++)
	{
		cin >> name >> currentState;
		log[name] = currentState;
	}
	// sort(log.begin(), log.end(), greater<string>());

	for (map<string, string>::iterator it = log.begin(); it != log.end(); it++)
		if (it->second == "enter") cout << it->first << "\n";
}