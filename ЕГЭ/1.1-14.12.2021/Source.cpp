#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int x, a;
	const int l = 100000000;
	for (int i = 1; i < 10000; i++) {
		a = i;
		int marker = 0;
		for (int j = 1; j <= l; j++) {
			x = j;
			bool ans = (not((x & 89) != 0)) or ((not((x & 57) == 0)) or ((x & a) != 0));
			if (ans) marker++;
			else break;
		}
		if (marker == l) cout << a << " " << marker << endl;
	}
}