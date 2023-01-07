#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main()
{
	map <int, int> M;
	for (int i = 0; i <= pow(10, 6); i++) M.emplace(i, 2147483647);
	int N;
	ifstream file("C:\\Users\\User\\Documents\\C++\\Файлы\\ЕГЭ\\Поляков\\27\\27-96b.txt");
	file >> N;
	int c5 = 0, c7 = 0, sum = 0, max_sum =0;
	while (!file.eof()) {
		int buf;
		file >> buf;
		if (!file.eof()) {
			sum += buf;
			if ((buf % 5 == 0)) c5++;
			if ((buf % 7 == 0)) c7++;
			if (c5 == c7) max_sum = max(max_sum, sum);
			int a = sum - M[abs(c5 - c7)];
			max_sum = max(max_sum, a);
			M[abs(c5 - c7)] = min(M[abs(c5 - c7)], sum);
		}
	}
	cout << max_sum;
}

