#include <iostream>
#include <vector>
#include <windows.h>
#define ll long long
using namespace std;
int main()
{
	ll a, i = 2;
	cin >> a;
	vector  <ll> b, b1;
	while (a != 1) {
		if (i * i > a) i = a;
		if (a % i == 0) {
			b.push_back(i);
			a = a / i, i = 2;
		}
		else i++;
	}
	for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
	cout << endl;
	ll buf = b[0], c = 1, answer = 1;
	for (int i = 0; i < b.size(); i++) {
		buf = b[i];
		if (buf != 0) {
			for (int j = i; j < b.size(); j++) {
				if (buf == b[j]) {
					c++;
					b[j] = 0;
				}
			}
			//cout << answer << endl;
			answer *= c, c = 1;
		}
	}
	cout << endl << answer;
}
