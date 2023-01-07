#include <iostream>
using namespace std;
int f(int n) {
	if (n == 1) return 1;
	else if (n % 2 == 0) return n + f(n - 1);
	else if (n % 2 != 0 and n > 1) return 2 * f(n - 2);
}
int main()
{
	cout << f(26);
}
