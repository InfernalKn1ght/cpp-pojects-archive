#include <iostream>
#include <vector>
#include <windows.h>
#define ld long double
using namespace std;
ld f(ld a, ld b) {
	return (a + b) / 2;
}
int main()
{
	ld x, sum = 0;
	int n = 2;
	double e = 0.0001;
	cin >> x >> n >> e;
	ld low = 0, high = x, mid;
	while ((abs(pow(f(low, high), n) - x)) > e) {
		mid = f(low, high);
		if (pow(mid, n) < x) low = mid;
		else if (pow(mid, n) > x) high = mid;
		//cout << f(low, high) << "   ";
	}
	cout << f(low, high) << endl;
}
