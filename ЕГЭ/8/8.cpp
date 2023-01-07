#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string str = string(106, '4');
	cout << str << endl;
	while ((str.find("444") != string::npos) or (str.find("555") != string::npos)) {
		int i = str.find("555");
		if (i != -1) str.replace(i, 3, "4");
		else {
			i = str.find("444");
			str.replace(i, 3, "5");
		}
		cout << str << endl;
	}
	cout << str;
}
