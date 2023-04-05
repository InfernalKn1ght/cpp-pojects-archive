#include <iostream>
#include <windows.h>
#define ll long long
using namespace std;
int main()
{
	ll a, b, c, answer = 1;

	//алгоритм эвклида
	cin >> a >> b;
	ll i1 = a, i2 = b, i3 = 1;
	while (i3 != 0) {
		i3 = i1 % i2;
		if (i3 != 0) i1 = i2, i2 = i3;
	}
	cout << i2 << endl << endl;


	//8 (НОК)
	cin >> a >> b;
	i1 = a, i2 = b, i3 = 1;
	while (i3 != 0) {
		i3 = i1 % i2;
		if (i3 != 0) i1 = i2, i2 = i3;
	}
	answer = (a / i2) * (b / i2) * i2;
	cout << answer;
}
