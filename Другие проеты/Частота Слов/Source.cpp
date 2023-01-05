#include <iostream>
#include <string>
#include <map>
using namespace std;
void print(map <string, double> m) {
	for (auto i : m) cout << i.first << " " << i.second << endl;
}
int main()
{
	map <string, double> words;
	string text, buf = "";
	int word_counter = 0;
	string buf_t = " ";
	//while (true) {
	//	if (buf_t == "") break;
//		else {
	getline(cin, buf_t);
	text += buf_t + " ";
	//		}
		//}
	text += " ";
	for (int i = 0; i < text.size(); i++) text[i] = tolower(text[i]);
	for (int i = 0; i < text.size(); i++) if (text[i] == 32) word_counter++;
	cout << "Amount of words int the text: " << word_counter << endl;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == 32) {
			auto it = words.find(buf);
			if (it != words.end()) it->second++;
			else words.emplace(buf, 1);
			buf = "";
		}
		else buf += text[i];
	}
	for (auto i = words.begin(); i != words.end(); i++) i->second /= word_counter;
	print(words);
}
