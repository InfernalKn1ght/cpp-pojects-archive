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
	vector <int> v;
	ifstream file("C:\\Users\\User\\Desktop\\егэ\\18.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			int buf;
			file >> buf;
			if (!file.eof()) v.push_back(buf);
		}
	}
	file.close();
	print(v);
	int c = 0;
	for (int i = 0; i < v.size(); i++) {
		//if (i <= (v.size() - 9)) {
			for (int j = i + 9; j < v.size(); j++) {
				if ((v[i] + v[j]) % 2 != 0) c++;
			}
		//}
	}
	cout << endl << c;
}

