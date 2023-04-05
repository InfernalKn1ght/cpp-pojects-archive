#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string str;
	ifstream file("C:\\Users\\User\\Desktop\\24.txt");
	if (file.is_open()) {
		string buf;
		while (getline(file, buf)) {
			str += buf;
		}
	}
	else cout << "error";
	file.close();
	//cin >> str;
	cout << str;
	char buf = str[0];
	int c = 1, c1 = 0;
	for (int i = 1; i < str.size(); i++) {
		if (buf != str[i]) {
			c++;
		}
		else {
			if (c1 <= c) c1 = c;
			c = 1;
		}
		buf = str[i];
	}
	cout << endl << endl << c1 << " " << str.size();
}

