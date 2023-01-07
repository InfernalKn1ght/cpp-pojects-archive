#include <iostream>
#include <map>
#include <fstream>

using namespace std;
int main()
{
	int n;
	map <int, int> m;
	ifstream file("C:\\Users\\User\\Desktop\\28131_B.txt");
	file >> n;
	while (!file.eof()) {
		if (!file.eof()) {
			int buf;
			file >> buf;
			//cout << buf << endl;
			bool flag = false;
			for (auto i : m) {
				if ((i.first > buf) and ((i.first + buf) % 120 == 0) and (i.second == 0)) {
					m[i.first] = buf;
					flag = true;
					break;
				}
			}
			if ((!flag) and (buf > 60)) m.emplace(buf, 0);
		}
	}
	file.close();
	cout << endl << endl;
	int max = 0, i1, i2;
	for (auto i : m) {
		if (max < (i.first + i.second)) {
			max = i.first + i.second;
			i1 = i.first;
			i2 = i.second;
		}
	}
	cout << i1 << "  " << i2 << "   " << max;
}