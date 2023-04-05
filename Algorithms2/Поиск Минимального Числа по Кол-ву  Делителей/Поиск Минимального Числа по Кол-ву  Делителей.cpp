#include <iostream>
using namespace std;
int main()
{
	long long a, i,b;
	cin >> a;
	i = 2, b = 4;
	while (i <= a) {
		for (int j = 2; j < b; j++) if (b % j == 0) i++;
		if (i != a) {
			i = 2;
			b++;
		}
		else break;
	}
	cout << b;
}
