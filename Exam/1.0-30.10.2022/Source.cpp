#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main()
{
	string str = "";
	str += string(66, '7');
	str += string(33, '5');
	cout << str << endl << endl;
	while (true) {
		int i = str.find("777");
		if (i > -1) str.replace(i, 3, "5");
		else break;
		i = str.find("55");
		if (i > -1) str.replace(i, 2, "7");
		cout << str << endl << endl;
	}
	cout << str;
}
