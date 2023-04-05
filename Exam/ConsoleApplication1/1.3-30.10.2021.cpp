#include <iostream> 
using namespace std;
int main()
{
	for (int x1 = 0; x1 < 10000; x1++) {
		int x = x1, L, M, Q;
		int buf = x;
		Q = 6;
		L = 0;
		while (x >= Q) {
			L = L + 1;
			x = x - Q;
		}
		M = x;
		if (M < L) {
			M = L;
			L = x;
		}
		if (L == 3 and M == 5) cout << L << " " << M << " " << buf <<endl <<endl;
	}
	//cout << L << endl << M << endl;
}