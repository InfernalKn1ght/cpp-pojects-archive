#include <iostream>

using namespace std;
int f(int*& a, int i) {
	a[i] = 100;
	return a[i];
}
void f3(int**& a, int i, int j) {
	a[i][j] = 100;
}
int f1(int& a, int i) {
	a = 100;
	return a;
}
int main() {
	int* a = new int[10];
	int** b = new int* [10];
	for (int i = 0; i < 10; ++i) {
		a[i] = i * i;
		b[i] = new int[10];
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			b[i][j] = i * j;
		}
	}
	cout << a[9];
	cout << " " << f(a, 9) << " " << a[9] << "\n\n";

	f3(b, 4, 4);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}