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
	int S, N;
	vector <int> v;
	string str;
	ifstream file("C:\\Users\\User\\Desktop\\26.txt");
	if (file.is_open()) {
		file >> S >> N;
		while (!file.eof()) {
			int buf;
			file >> buf;
			if (!file.eof()) v.push_back(buf);
		}
	}
	file.close();
	//v.pop_back();
	cout << S << " " << N;
	print(v);
	sort(v.begin(), v.end());
	print(v);
	int sum = 0;
	int i = 0;
	while (true) {
		if (sum + v[i] < S) sum += v[i];
		else break;
		i++;
	}
	int ans;
	for (int j = 0; j < v.size(); j++) {
		if (v[j] == (S - sum + v[i])) {
			sum = sum - v[i] + v[j];
			ans = v[j];
			break;
		}
		else if (v[j] > (S - sum + v[i])) {
			sum = sum - v[i] + v[j - 1];
			ans = v[j-1];
			break;
		}
	}
	cout << i << " " << ans;
}

