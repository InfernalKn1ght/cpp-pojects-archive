#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <char> v;

void print() {
	for (int i = 0; i < v.size(); i++) cout << v[i];
	cout << endl << endl;
}

bool search(string str) {
	for (int i = 0; i < v.size(); i++) {
		string buf = "";
		if (i + str.size() < v.size()) {
			for (int j = i; j < i + str.size(); j++) {
				buf += v[i];
			}
		}
		if (buf == str) return true;
	}
	return false;
}

int search_index(string str) {
	for (int i = 0; i < v.size(); i++) {
		string buf = "";
		if (i + str.size() < v.size()) {
			for (int j = i; j < i + str.size(); j++) {
				buf += v[i];
			}
		}
		if (buf == str) return i;
	}
	return v.size();
}

void replace(string str, string str1) {
	int n = search_index(str);
	if (n + str.size() < v.size()) {
		for (int i = n; i < n + str.size(); i++) v.erase(v.begin() + n);
		for (int i = n; i < n + str1.size(); i++) v.insert(v.begin() + n, str1[i - n]);
	}
}

int main()
{
	for (int i = 0; i < 66; i++) v.push_back('7');
	for (int i = 0; i < 33; i++) v.push_back('5');
	print();


	string str = "";
	//for (int i = 0; i < 66; i++) str += "7";
	//for (int i = 0; i < 33; i++) str+="5";
	//str += string(66, '7');
	//str += string(33, '5');
	/*while (str.find("777")) {
		str.replace(str.find("777"), 1, "5");
		str.replace(str.find("55"), 1, "7");
	}
	cout <<endl << str;*/



	//test = "abc def abc def";
	//test.replace("abc", "hij").replace("def", "klm");
	int c = 0;
	//while (search("777")) {
	replace("777", "5");
	replace("55", "7");
	c++;
	//}
	print();
}
