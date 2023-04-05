#include <iostream>
#include <windows.h>
#define ll long long
using namespace std;
int main()
{
	//7 (НОД)
	//обычный
	ll a, b, c, answer = 1;
	cin >> a >> b;
	if (a < b) c = a;
	else c = b;
	for (ll i = 2; i <= c; i++) if ((a % i == 0) and (b % i == 0)) answer = i;
	cout << answer << endl << endl;
}