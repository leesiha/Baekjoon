#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> v;
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int total = accumulate(v.begin(), v.end(), 0);
	int count = v.size();
	cout << total / count << endl;
	cout << v[count / 2] << endl;
}