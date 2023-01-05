#include <iostream>
#include <cmath>
using namespace std;
int f(int x) {
	int y = 6 * pow(x, 7) + pow(x, 6) - 26 * pow(x, 5) - 5 * pow(x, 4) + 7 * pow(x, 3) - 12 * pow(x, 2) - 14 * x - 6;
	return y;
}
int main() {
	int y1, y2, y3, y4;
	cin >> y1 >> y2 >> y3 >> y4;
	int a = -y1 + 3 * y2 - 3 * y3 + y4;
	cout << a;
}