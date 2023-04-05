#include <iostream>
#include <windows.h>

#define ld long double
using namespace std;
int main()
{
	ld a;
	double e; //= 0.0001;
	cin >> a >> e;
	ld x = (1 + a) / 2;
	while (abs(x * x - a) > e) {
		x = 0.5 * (x + a / x);
		//if (abs(x * x - a) < e) break;
	}
	cout << x;
}
