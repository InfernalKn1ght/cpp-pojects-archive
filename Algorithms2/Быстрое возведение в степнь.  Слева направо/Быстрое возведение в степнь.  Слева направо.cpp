#include <iostream>
#include <vector>
#include <windows.h>
#define ll long long
using namespace std;
vector <ll> binary;
int c = 0;

void print_v(vector <ll> v) {
	cout << endl << endl;
	for (int i = v.size()-1; i >= 0; i--) cout << v[i];
	cout << endl << endl;
}
void f(ll k) {
	do {
		binary.push_back(k % 2);
		k = k / 2;
	} while (k > 0);
}
ll f1(ll x, ll k) {
	ll ans = 1;
	for (ll i = 1; i <= k; i++) {
		ans *= x;
		c++;
	}
	return ans;
}
long powerFast(long num, long deg) {
	long result = 1;
	while (deg) {
		if (deg % 2 == 0) {
			deg /= 2;
			num *= num;
			c++;
		}
		else {
			deg--;
			result *= num;
			c++;
		}
	}

	return result;
}
ll f2(ll x, ll k) {
	ll answer=1;
	f(k);
	for (int i = binary.size() - 1; i >= 0; i--) {
		if (binary[i] == 1) {
			answer *= x;
			c++;
		}
		if (i != 0) {
			answer *= answer;
			c++;
		}
	}
	return answer;
}
int main()
{
	int start = GetTickCount();
	for (int indx = 2; indx < 1000000; indx++) {
		f2(2, 32);
		binary.clear();
	}
	int end = GetTickCount();
	cout << "algorythm1 " << "time: " << (end - start) << " " << "c: " << c << endl;
	c = 0;
	start = GetTickCount();
	for (int indx = 2; indx < 1000000; indx++) {
		f1(2, 32);
	}
	end = GetTickCount();
	cout << "algorythm2 " << "time: " << (end - start) <<" "<< "c: " <<c<< endl;
	c = 0;
	start = GetTickCount();
	for (int indx = 2; indx < 1000000; indx++) {
		powerFast(2, 32);
	}
	end = GetTickCount();
	cout << "algorythm3 " << "time: " << (end - start) << " " << "c: " << c << endl;
}
