#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector <int> v) {
	cout << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}
void test() {
	int N, M, K, max = 0, counter = 0; 
	cin >> N >> M >> K;
	int old_num1, old_num2;
	for (int i = 0; i < K; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		if (num2 != 1) {
			if (abs(old_num1 - num1) > 1) counter += (N - 3) * (abs(old_num1 - num1) - 1), max = old_num1 + 1;
			if ((num1 == old_num1) and (num2 - old_num2 > 4)) {
				counter += (num2 - old_num2) - 4;
			}
			if (num1 != old_num1) {
				if (N - old_num2 >= 4) counter += ((N - old_num2) + 1) - 4;
				if (num2 - 1 >= 4) counter += ((num2 - 1) + 1) - 4;
			}
		}
		old_num1 = num1;
		old_num2 = num2;
	}
	cout << counter << " " << max;
}
int main()
{
	//test();
	//int N, M, K, max = 100000, counter = 0;
	//vector <int> v;
	//ifstream file("C:\\Users\\User\\Documents\\C++\\Файлы\\ЕГЭ\\Поляков\\26\\P_4901.txt");
	//if (file.is_open()) {
	//	file >> N >> M >> K;
	//	int old_num1 = 1, old_num2 = 1;
	//	while (!file.eof()) {
	//		int num1, num2;
	//		file >> num1 >> num2;
	//		if (!file.eof()) {
	//			//if (num2 != 1) {
	//				if (abs(old_num1 - num1) > 1) {
	//					counter += (N - 3) * (abs(old_num1 - num1) - 1);
	//					if (max > old_num1 + 1) max = old_num1 + 1;
	//				}
	//				if ((num1 == old_num1) and (num2 - old_num2 > 4)) {
	//					counter += (num2 - old_num2) - 4;
	//				}
	//				if (num1 != old_num1) {
	//					if (N - old_num2 >= 4) counter += ((N - old_num2) + 1) - 4;
	//					if (num2 - 1 >= 4) counter += ((num2 - 1) + 1) - 4;
	//				}
	//			//}
	//			old_num1 = num1;
	//			old_num2 = num2;
	//		}
	//	}
	//}
	//else cout << "Failed";
	//file.close();
	//cout <<endl << counter << " " << max;
	int N, M, K, max = 100000, counter = 0;
	vector <vector <int>> V;
	ifstream file("C:\\Users\\User\\Documents\\C++\\Файлы\\ЕГЭ\\Поляков\\26\\P_4901.txt");
	file >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		file >> x >> y;
		vector <int> v;
		v.push_back(x);
		v.push_back(y);
		V.push_back(v);
	}
	sort(V.begin(), V.end());
	int old_num1 = 1, old_num2 = 1;
	for (int i = 0; i < V.size(); i++) {
		int num1 = V[i][0], num2 = V[i][1];
		//if (num2 != 1) {
			if (abs(old_num1 - num1) > 1) {
				counter += (N - 3) * (abs(old_num1 - num1) - 1);
				if (max > old_num1 + 1) max = old_num1 + 1;
			}
			if ((num1 == old_num1) and (num2 - old_num2 > 4)) {
				counter += (num2 - old_num2) - 4;
			}
			if (num1 != old_num1) {
				if (N - old_num2 >= 4) counter += ((N - old_num2) + 1) - 4;
				if (num2 - 1 >= 4) counter += ((num2 - 1) + 1) - 4;
			}
		//}
		old_num1 = num1;
		old_num2 = num2;
	}
	cout << counter << " " << max;
}
