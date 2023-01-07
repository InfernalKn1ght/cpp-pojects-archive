#include <iostream>
#include <windows.h>
using namespace std;
void print_field(char* field, int n) {
	for (int i = 0; i < n * n; i++) {
		if ((i % n == 0) and (i != 0)) cout << endl;
		cout << field[i] << " ";
	}
}

int main()
{
	int n;
	cin >> n;
	char* field = new char[n * n];
	for (int i = 0; i < n * n; i++) field[i] = 15;
	print_field(field, n);
	cout << endl;
	for (int i = 0; i < 225; i++) {
		field[i] = 32;
		print_field(field, n);
		cout << endl << endl;
		Sleep(200);
	}
}
