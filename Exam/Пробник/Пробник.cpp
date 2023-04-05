#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void print(vector <int> v) {
	cout << endl << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl << endl;
}
int main()
{
	for (int i = 240001; i < 250000; i++) {
		int max = 0, min = 0;
		for (int j = i - 1; j > 0; j--) {
			if (i % j == 0) {
				max = j;
				break;
			}
		}
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				min = j;
				break;
			}
		}
		int M = max + min;
		if (M % 10 == 7) cout << i << " " << M << endl;
	}
}

