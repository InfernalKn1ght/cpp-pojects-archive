#include <iostream>
#include <map>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;
void f(vector <pair<int, int>> v, int n) {
	for (int i = 0; i < n; ++i) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	cout << endl << endl;
}
int main() {
	vector <pair<int, int>> v1, v2;
	ifstream file("C:\\Users\\arzha\\source\\repos\\Kronecker\\Test1\\pair2_3.txt");
	for (int i = 0; i < 6; ++i) {
		pair <int, int> buf;
		file >> buf.first >> buf.second;
		v1.push_back(buf);
	}
	file.close();
	ifstream file1("C:\\Users\\arzha\\source\\repos\\Kronecker\\Test1\\pair1_4.txt");
	for (int i = 0; i < 16; ++i) {
		pair <int, int> buf;
		file1 >> buf.first >> buf.second;
		v2.push_back(buf);
	}
	file1.close();

	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 16; ++j) {
			int y1 = v2[j].first;
			int y2 = v1[i].first;
			int y3 = v1[i].second;
			int y4 = v2[j].second;
			int a = 4 * y2 - y1 + 4 * y3 - y4;
			a = a / 6;
			int b = 2 * y2 - y1 - 2 * y3 + y4;
			int c = y1 - y2 - y3 + y4;
			c = c / 6;
			int d = y1 + 8 * y3 - 8 * y2 - y4;
			d = d / 12;
			b = b / 12;
			bool f1 = 0, f2 = 0;
			if (b != 0) if (6 % b == 0) f2 = 1;
			if (a != 0) if (6 % a == 0) f1 = 1;
			if (f1 * f2 == 1) cout << y1 << " " << y2 << " " << y3 << " " << y4 << "  " << b << " " << c << " " << d << " " << a << endl;
		}
	}
	/*f(v1, 6);
	f(v2, 16);*/
}