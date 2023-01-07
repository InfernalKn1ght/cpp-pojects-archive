#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector <int> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}
int main()
{
	vector <int> v;
	vector <vector <int>> ans;
	for (int j = 174457; j <= 174505; j++) {
		int a, answer = 1, i = 2;
		bool m = true;
		a = j;
		while (i * i <= a) {
			if (a % i == 0) {
				if (a / i == i) m = false;
				answer++;
			}
			i++;
		}
		answer *= 2;
		if (!m) answer = answer - 1;
		answer -= 2;
		if (answer == 2) v.push_back(j);
	}
	sort(v.begin(), v.end());
	print(v);
	cout << endl << endl;
	for (int j = 0; j < v.size(); j++) {
		int a, i = 2;
		bool m = true;
		a = v[j];
		vector <int> buf;
		while (true) {
			if (a % i == 0) {
				if (a / i == i) m = false;
				buf.push_back(a / i);
				if (m) buf.push_back(i);
				break;
			}
			i++;
		}
		sort(buf.begin(), buf.end());
		ans.push_back(buf);
		cout << endl;
	}
	//sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		print(ans[i]);
	}
}

