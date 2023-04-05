#include <iostream>

#define ld long double
using namespace std;
int main()
{
	ld x, a = 1, sum = 0;
	double e = 0.0001;
	cin >> x >> e;
	while (true) {
		a = (a + x / a) / 2;
		if (abs(a * a - x) < e) break;
	}
	cout << a;
}
