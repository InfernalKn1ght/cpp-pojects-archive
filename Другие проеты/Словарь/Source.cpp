#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;
void print(map <string, string> m) {
	for (auto i : m) cout << i.first << " - " << i.second << endl;
}

map <string, string> load_words() {
	ifstream file("words.txt");
	map <string, string> buf_m;
	string buf;
	vector <string> v;
	if (file.is_open()) {
		while (getline(file, buf)) {
			v.push_back(buf);
		}
	}
	file.close();
	ifstream file2("translations.txt");
	if (file2.is_open()) {
		int i = 0;
		while (getline(file2, buf)) {
			buf_m.emplace(v[i], buf);
			i++;
		}
	}
	return buf_m;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, string> words;
	string buf, buf2;


	words = load_words();
	print(words);


	cout << endl << endl << "Please, enter a word: ";
	getline(cin, buf);
	auto it = words.find(buf);
	if (it != words.end()) cout << "Word has been found: " << it->first << " - " << it->second << endl << endl;
	else {
		cout << "Please, enter traslation of word: ";
		getline(cin, buf2);
		words.emplace(buf, buf2);
		ofstream file("words.txt", ios::app);
		file << endl << buf;
		file.close();
		file.open("translations.txt", ios::app);
		file << endl << buf2;
		file.close();
	}
	print(words);
}
