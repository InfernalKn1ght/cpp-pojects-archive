#include <iostream>

#define ld long double
using namespace std;
int main()
{
	ld a;
	double e = 0.0001;
	cin >> a;
	ld x = 1;
	while (abs(pow(x, 3) - a) > e) {
		x = 1.0*1/3 * ((2 * x) + (a / (x * x)));
		//cout << x << " ";
	}
	cout << x;
}
