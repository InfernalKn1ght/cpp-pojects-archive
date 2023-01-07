#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void print(multimap <int, string> m) {
	cout << endl << endl;
	for (auto i : m) {
		cout << i.first << " " << i.second << "    ";
	}
	cout << endl << endl;
}
int main()
{
	int N, M;
	multimap <int, string> m1, m2, m3;
	vector <int> v;
	ifstream file("C:\\Users\\User\\Documents\\C++\\Файлы\\ЕГЭ\\Поляков\\26\\26-62.txt");
	if (file.is_open()) {
		file >> N >> M;
		while (!file.eof()) {
			int num;
			string str;
			file >> num >> str;
			if (!file.eof()) {
				m1.emplace(num, str);
			}
		}
	}
	file.close();
	print(m1);
	int counter = 0;
	for (auto i : m1) {
		if (counter + i.first < M) {
			m2.emplace(i.first, i.second);
			counter += i.first;
		}
		else m3.emplace(i.first, i.second);
	}
	print(m2);
	print(m3);
	for (auto i : m2) {
		v.push_back(i.first);
	}
	counter = v.size()-1;
	int q_counter = 0;
	for (auto i : m2) {
		if (i.second == "Q") q_counter++;
	}
	for (auto i = m2.rbegin(); i != m2.rend(); i++) {
		int sum = 0;
		for (auto k : v) sum += k;
		if (sum < M) {
			if (i->second == "Z") {
				for (auto j : m3) {
					if (j.second == "Q") {
						if (sum - v[counter] + j.first <= M) {
							v[counter] = j.first;
							q_counter++;
							m3.erase(j.first);
							break;
						}
					}
				}
			}
			counter--;
		}
		else break;
	}
	int rem =0;
	for (int i = 0; i < v.size(); i++) {
		rem += v[i];
	}
	rem = M - rem;
	cout << q_counter << " " << rem;
}

