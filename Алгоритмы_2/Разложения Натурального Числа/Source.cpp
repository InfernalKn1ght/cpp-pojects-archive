#include <iostream>
#include <vector>
#include <set>
using namespace std;
set <vector <int>> answer;
void print_s(set <vector <int>> s) {
	cout << endl << endl;
	for (auto i : s) {
		for (int j = 0; j < i.size(); j++) {
			cout << i[j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
//int sol(vector <int> v, int n) {
//	int a = n, i = 2;
//	for (int i = 2; i <= n; i++) {
//		for (int j = 2; j < i; j++) {
//			if (i%j)
//		}
//	}
//}
void f(vector <int> v) {
	answer.insert(v);
	if (v.size() > 1) {
		for (int i = 1; i < v.size(); i++) {
			if ((v[i] != v[i - 1]) or (i < 2)) {
				int buf = v[0] * v[i];
				vector <int> buf_v = v;
				buf_v.erase(buf_v.begin()), buf_v.erase(buf_v.begin() + i - 1), buf_v.push_back(buf);
				f(buf_v);
			}
		}
	}
}
int main()
{
	int a, i = 2, n = 0;
	vector <int> v;
	cin >> a;
	i = 2;
	while (a != 1) {
		if (i * i > a) i = a;
		if (a % i == 0) {
			v.push_back(i);
			n++;
			a = a / i;
			i = 2;
		}
		else i++;
	}
	f(v);
	print_s(answer);

}
