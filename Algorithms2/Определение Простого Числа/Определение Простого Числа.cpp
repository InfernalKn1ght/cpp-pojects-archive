#include <iostream>
using namespace std;
int main()
{
	long long a;
	cin >> a;
	bool m = false;
	for (int i = 2; i * i < a; i++) {
		if (a % i == 0) {
			cout << "not simple" << endl << endl;
			m = true;
			break;
		}
	}
	if (m == false) cout << "simple" << endl << endl;
}
