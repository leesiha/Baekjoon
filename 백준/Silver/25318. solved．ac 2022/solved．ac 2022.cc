#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;
using namespace std::chrono;

vector<tuple<string, string, int>> v;
int N;

system_clock::time_point parseDate(const string &date, const string &time)
{
	istringstream ss1(date);
	istringstream ss2(time);
	int year, month, day, hour, min, sec;
	char delim;
	ss1 >> year >> delim >> month >> delim >> day;
	ss2 >> hour >> delim >> min >> delim >> sec;
	tm t = {};
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_hour = hour;
	t.tm_min = min;
	t.tm_sec = sec;
	return system_clock::from_time_t(mktime(&t));
}

double getDayDistance(const tuple<string, string, int> &n, const tuple<string, string, int> &i)
{
	auto [Ndate, Ntime, ignore1] = n;
	auto [date, time, ignore2] = i;
	auto timePoint1 = parseDate(Ndate, Ntime);
	auto timePoint2 = parseDate(date, time);
	auto duration = duration_cast<seconds>(timePoint1 - timePoint2);
	return duration.count() / (60.0 * 60.0 * 24.0); // seconds to days
}

double totalDistance(const tuple<string, string, int> &date)
{
	return getDayDistance(v[N - 1], date);
}

double P(int i)
{
	return max(pow(0.5, totalDistance(v[i]) / 365.0), pow(0.9, N - (i + 1)));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	if (N == 0)
	{
		cout << 0;
	}
	else
	{
		string date, time;
		int difficulty;
		for (int i = 0; i < N; i++)
		{
			cin >> date >> time >> difficulty;
			v.push_back({date, time, difficulty});
		}

		double numerator = 0.0, denominator = 0.0;
		for (int i = 0; i < N; i++)
		{
			numerator += P(i) * get<2>(v[i]);
		}
		for (int i = 0; i < N; i++)
		{
			denominator += P(i);
		}
		cout << static_cast<int>(round(numerator / denominator));
	}
}
