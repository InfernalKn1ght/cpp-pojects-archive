#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int main()
{
	int n;
	vector <int> v;
	ifstream file("C:\\Users\\User\\Desktop\\27-A_demo.txt");
	file >> n;
	while (!file.eof()) {
		int buf;
		file >> buf;
		if (!file.eof()) {
			v.push_back(buf);
		}
	}
	cout << n;
	file.close();
	cout << 1;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}