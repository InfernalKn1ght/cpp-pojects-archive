#include <iostream>
using namespace std;
int factorial(int x) {
	if (x > 0) x = x * factorial(x - 1);
	else return 1;
}
int main()
{
	int c1 = 0, c2 = 0;
	while (true) {
		int a;
		cin >> a;
		if (a != -1) {
			if (a % 2 == 0) c1++;
			else c2++;
		}
		else {
			int answer = (factorial(c1) / (factorial(c1 - 2) * factorial(2))) + (factorial(c2) / (factorial(c2 - 2) * factorial(2)));
			cout << answer;
			break;
		}
	}
}
