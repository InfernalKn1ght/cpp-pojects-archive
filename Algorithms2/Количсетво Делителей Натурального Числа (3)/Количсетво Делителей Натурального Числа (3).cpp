#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#define ll long long
using namespace std;
map <ll, int> b;
vector <int> answer;
vector <ll> simple;
void print(map <ll, int> m) {
	for (auto i : m) cout << i.first << " " << i.second << endl;
}
void print_v(vector <ll> v) {
	cout << endl << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl << endl;
}
int f(int power, int num) {
	int sum = 0;
	for (int i = 0; i <= 10/*b.find(simple[num])->second*/; i++) {
		int buf = 0;
		//if (i != 0) buf = pow(b[num], i);
		sum = power * buf;
		sum = sum * f(sum, num + 1);
		answer.push_back(sum);
		cout << sum;
	}
	return sum;
}

int main()
{
	ll a, i = 2, buf;
	cin >> a;
	while (a != 1) {
		if (i * i > a) i = a;
		if (a % i == 0) {
			auto it = b.find(i);
			if (it != b.end()) it->second++;
			else b.emplace(i, 1);
			a = a / i, i = 2;
		}
		else i++;
	}
	print(b);


	auto it = b.begin();
	buf = it->second + 1;
	for (auto i = b.begin(); i != b.end(); i++) if (i != b.begin()) buf *= i->second + 1;
	cout << endl << buf << endl;

	for (auto i = b.begin(); i != b.end(); i++) simple.push_back(i->first);

	//cout << b[2];

	cout << f(1, 0);

	print_v(simple);
}
