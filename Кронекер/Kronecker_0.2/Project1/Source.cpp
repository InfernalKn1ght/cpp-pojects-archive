#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

#define ll long long

using namespace std;

ll f(int x) {
	return 6 * pow(x, 7) + pow(x, 6) - 26 * pow(x, 5) - 5 * pow(x, 4) + 7 * pow(x, 3) - 12 * pow(x, 2) - 14 * x - 6;
}

int main() {
	for (int i = -12; i < 16; ++i) {
		int c = 0;
		for (int j = 2; j * j < abs(f(i)); ++j) {
			if (f(i) % j == 0) c+=2;
		}
		cout << i << " " << f(i) << " " << c << endl;
	} 
}