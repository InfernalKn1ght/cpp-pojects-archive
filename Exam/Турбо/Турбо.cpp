#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
int main()
{
	int N;
	map <int, int> m = { {0,0},{1,0},{2,0} };
	ifstream file("C:\\Users\\User\\Documents\\C++\\Файлы\\ЕГЭ\\Решу ЕГЭ\\27\\27-B_demo(03.03.2022).txt");
	file >> N;
	while (!file.eof()) {
		int num1, num2;
		file >> num1 >> num2;
		if (!file.eof()) {
			map <int, int> m_buf = m;
			for (auto i : m_buf) m[(i.second + num1) % 3] = max(i.second + num1, m[(i.second + num1) % 3]);
			for (auto i : m_buf) m[(i.second + num2) % 3] = max(i.second + num2, m[(i.second + num2) % 3]);
		}
	}
	file.close();
	for (auto i : m) cout << i.first << " " << i.second << endl;
}

