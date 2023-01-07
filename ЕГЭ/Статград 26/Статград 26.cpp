#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n = 10000, N;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) arr[i] = new int[n]; 
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) arr[i][j] = 0;
	ifstream file("C:\\Users\\User\\Documents\\C++\\Файлы\\ЕГЭ\\Статград\\26.txt");
	file >> N;
	while (!file.eof()) {
		int y, x;
		file >> y >> x;
		if (!file.eof()) {
			arr[y-1][x-1] = 1;
		}
	}
	int max_len = 0, max_line = 0;
	for (int i = 0; i < n; i++) {
		int c = 1;
		for (int j = 1; j < n; j++) {
			if (arr[i][j - 1] + arr[i][j] == 2) c++;
			else {
				if (c > max_len) {
					max_len = c;
					max_line = i + 1;
					c = 1;
				}
			}
		}
	}
	cout << max_len << " " << max_line;
}
