// 참고: https://m.blog.naver.com/book541/222637089384
// 참고: https://one-way-people.tistory.com/7

// 도가뉴 항등식
#include <iostream>
#include <map>
#define mod 1000000007LL

using namespace std;
map<size_t, size_t> m;

size_t fibonacci(size_t n)
{
	size_t front, back;
	if (n<=0) return 0;
	else if (n==1 || n==2) return 1;
	else if (m.count(n) > 0) return m[n];

	if (n % 2) //홀수
	{
		front = fibonacci((n-1)/2);
		back = fibonacci((n+1)/2);
		m[n] = front*front + back*back;
		m[n] %= mod;
		return m[n];
	}
	else // 짝수
	{
		front = fibonacci(n / 2);
		back = fibonacci((n-1)/2);
		m[n] = front * (front + 2LL*back);
		m[n] %= mod;
		return m[n];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	size_t n;
	cin >> n;
	cout << fibonacci(n) << "\n";
}