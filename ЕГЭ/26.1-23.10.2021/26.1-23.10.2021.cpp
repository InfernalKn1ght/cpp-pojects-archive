#include <iostream>
#include <fstream>
#include <string>
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
	int N, K;
	vector <int> v;
	ifstream file("C:\\Users\\User\\Desktop\\егэ\\26\\26-k1.txt");
	if (file.is_open()) {
		file >> N >> K;
		while (!file.eof()) {
			int buf;
			file >> buf;
			if (!file.eof()) v.push_back(buf);
		}
	}
	file.close();
	sort(v.begin(), v.end());
	//print(v);
	int answer1 = v[v.size() - 1 - K], answer2=0;
	for (int i = v.size()-K; i < v.size(); i++) answer2 += v[i] * 0.2;
	cout << answer1 << " " << answer2;
}

