#include <iostream>
using namespace std;
int main()
{
	long long a, i = 2;
	cin >> a;
	i = 2;
	while (a != 1) {
		if (i * i > a) i = a;
		if (a % i == 0) {
			cout << i << " ";
			a = a / i;
			i = 2;
		}
		else i++;
	}
	cout << endl << endl;
}
