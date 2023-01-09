#include <iostream>
using namespace std;
int main()
{
	long long a, answer = 1, i = 2, b;
	bool m = true;
	cin >> a;
	while (i * i <= a) {
		if (a % i == 0) {
			if (a / i == i) m = false;
			cout << a / i << " ";
			if (m) cout << i << " ";
			answer++;
		}
		i++;
	}
	answer *= 2;
	if (!m) answer = answer - 1;
	cout << endl << endl << answer;
}
