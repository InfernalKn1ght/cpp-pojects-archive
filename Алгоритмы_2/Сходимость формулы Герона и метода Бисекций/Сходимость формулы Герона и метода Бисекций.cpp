#include <iostream>
#include <windows.h>

#define ld long double
using namespace std;


ld f(ld a, ld b) {
	return (a + b) / 2;
}


int main()
{
	ld a;
	double e = 0.001;
	
	for (int i = 2; i < 10000; i++) {

		int counter = 0;
		a = i;

		ld x = (1 + a) / 2;
		while (abs(x * x - a) > e) {
			x = 0.5 * (x + a / x);
			counter++;
		}
		cout << "Number: " << a << "    " << "Geron: " << x << "    Iterations: " << counter << "    ";

		counter = 0;

		ld  mid, low = 0, high = a;
		while ((abs(pow(f(low, high), 2) - a)) > e) {
			mid = f(high, low);
			if (f(low, high) * f(low, high) > a) high = mid;
			else if (f(low, high) * f(low, high) < a) low = mid;
			counter++;
		}
		cout << "Binary search: " << f(low, high) << "    Iterations: " << counter << endl << endl <<endl;
	}
}
