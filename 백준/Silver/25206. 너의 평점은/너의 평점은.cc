#include <iostream>
#include <map>

using namespace std;

pair<string, float> Grades[] = {
	make_pair("A+", 4.5),
	make_pair("A0", 4.0),
	make_pair("B+", 3.5),
	make_pair("B0", 3.0),
	make_pair("C+", 2.5),
	make_pair("C0", 2.0),
	make_pair("D+", 1.5),
	make_pair("D0", 1.0),
	make_pair("F", 0.0)
};

map<string, float> scores(Grades, Grades + sizeof(Grades) / sizeof(Grades[0]));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string subject;
	float credit;
	string grade;

	//have to estimate
	float numerator = 0;
	int denominator = 0; // (학점 × 과목평점), 학점의 총합

	for (int i = 0; i < 20; i++)
	{
		cin >> subject >> credit >> grade;
		if (grade == "P")
			continue;
		denominator += credit;
		numerator += credit * scores[grade];
	}

	cout << numerator / denominator << endl;
}