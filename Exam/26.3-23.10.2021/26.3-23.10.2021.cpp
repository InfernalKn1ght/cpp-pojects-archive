#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector <int> v) {
	cout << endl << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl << endl;
}
int main()
{
	int N, K, M;
	vector <int> v;
	ifstream file("C:\\Users\\User\\Desktop\\егэ\\26\\26-k3.txt");
	if (file.is_open()) {
		file >> N >> K >> M;
		while (!file.eof()) {
			int buf;
			file >> buf;
			if (!file.eof()) v.push_back(buf);
		}
	}
	file.close();
	//cin >> N >> K >> M;
	//for (int i = 0; i < N; i++) {
	//	int buf;
	//	cin >> buf;
	//	v.push_back(buf);
	//}
	sort(v.begin(), v.end());
	//print(v);
	int answer1 = v[v.size() - M - K], answer2 = v[v.size() - K];
	cout << answer1 << " " << answer2;
}

