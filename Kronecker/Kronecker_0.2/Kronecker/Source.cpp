#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

#define ll long long

using namespace std;

ll f(int x) {
	return 6 * pow(x, 7) + pow(x, 6) - 26 * pow(x, 5) - 5 * pow(x, 4) + 7 * pow(x, 3) - 12 * pow(x, 2) - 14 * x - 6;
}

vector <int> fill(string path, int n) {
	vector <int> v;
	ifstream file(path);
	for (int i = 0; i < n; ++i) {
		int buf = 0;
		file >> buf;
		v.push_back(buf);
	}
	file.close();
	return v;
}

void print(vector <int> v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl << endl;
}

int main() {
	vector <int> v1, v2, v3, v4;

	v1 = fill("C:\\Users\\User\\source\\repos\\Kronecker\\Kronecker\\1.txt", 4);
	v2 = fill("C:\\Users\\User\\source\\repos\\Kronecker\\Kronecker\\2.txt", 8);
	v3 = fill("C:\\Users\\User\\source\\repos\\Kronecker\\Kronecker\\3.txt", 6);
	v4 = fill("C:\\Users\\User\\source\\repos\\Kronecker\\Kronecker\\4.txt", 8);

	print(v1);
	print(v2);
	print(v3);
	print(v4);

	ofstream file("C:\\Users\\User\\Desktop\\1.txt");
	int c = 0;
	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v4.size(); ++j) {
			cout << v1[i] << " " << v4[j] << ":  " << -2 * v1[i] - v4[j] << " " << (-2 * v1[i] - v4[j]) % 3 << endl;
			if ((-2 * v1[i] - v4[j]) % 3 == 0) {
				c++;
				file << v1[i] << " " << v4[j] << "\n";
			}
		}
	}
	file.close();
	cout << endl << c<< endl <<endl;

	ofstream file2("C:\\Users\\User\\Desktop\\2.txt");
	c = 0;
	for (int i = 0; i < v2.size(); ++i) {
		for (int j = 0; j < v4.size(); ++j) {
			cout << v2[i] << " " << v4[j] << ":  " << -3 * v2[i] - v4[j] << " " << (-3 * v2[i] - v4[j]) % 2 << endl;
			if ((-3 * v2[i] - v4[j]) % 2 == 0) {
				c++;
				file2 << v2[i] << " " << v4[j] << "\n";
			}
		}
	}
	file2.close();
	cout << endl << c << endl <<endl;


	ofstream file3("C:\\Users\\User\\Desktop\\3.txt");
	c = 0;
	for (int i = 0; i < v2.size(); ++i) {
		for (int j = 0; j < v3.size(); ++j) {
			cout << v2[i] << " " << v3[j] << ":  " << v2[i] - v3[j] << " " << (v2[i] - v3[j]) % 2 << endl;
			if ((v2[i] - v3[j]) % 2 == 0) {
				c++;
				file3 << v2[i] << " " << v3[j] << "\n";
			}
		}
	}
	file3.close();
	
	ofstream file4("C:\\Users\\User\\Desktop\\4.txt");
	c = 0;
	for (int i = 0; i < v2.size(); ++i) {
		for (int j = 0; j < v4.size(); ++j) {
			cout << v2[i] << " " << v4[j] << ":  " << -3 * v2[i] + v4[j] << " " << (-3 * v2[i] + v4[j]) % 2 << endl;
			if ((-3 * v2[i] + v4[j]) % 2 == 0) {
				c++;
				file4 << v2[i] << " " << v4[j] << "\n";
			}
		}
	}
	file4.close();
	
	cout << endl << endl << endl << endl;
	c = 0;
	ifstream f("C:\\Users\\User\\Desktop\\f.txt");
	for (int i = 0; i < 6; ++i) {
		int y1, y2, y3, y4;
		y3 = v3[i];
		for (int j = 0; j < 64; ++j) {
			f >> y1 >> y2 >> y4;
			int ans = -y1 + 3 * y2 - 3 * y3 + y4;

			double a = (-y1 + 3 * y2 - 3 * y3 + y4) / 6;
			double b = (y1 - 2 * y2 + y3) / 2;
			double c = (-2 * y1 - 3 * y2 + 6 * y3 - y4) / 6;
			double d = y2;
			if (ans != 0) {
				if (ans % 6 == 0) {
					if (6 % (ans / 6) == 0) {
						c++;
						cout << y1 << " " << y2 << " " << y3 << " " << y4 << ":   " << ans  << "      " << a << " " << b << " " << c << " " << d <<endl << endl;
					}
				}
			}
		}
	}
	f.close();
}