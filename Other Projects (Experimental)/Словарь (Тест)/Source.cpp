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
class dictionary {
private:
	map <string, string> words;
public:
	void print() {
		cout << endl << endl;
		for (auto i : words) cout << i.first << " - " << i.second << endl;
		cout << endl << endl;
	}
	bool add(string word, string translation) {
		auto it = words.find(word);
		if (it != words.end()) return false;
		else {
			cout << "Please, enter traslation of word: ";
			getline(cin, translation);
			words.emplace(word, translation);
			ofstream file("words.txt", ios::app);
			file << endl << word;
			file.close();
			file.open("translations.txt", ios::app);
			file << endl << translation;
			file.close();
			return true;
		}
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	dictionary myD;
	string word, tr;
	cin >> word >> tr;
	bool mark = myD.add(word, tr);
	myD.print();
}
