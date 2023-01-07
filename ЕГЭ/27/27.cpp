#include <iostream>
#include <fstream>
#define ll long long
int max_num(ll a, ll b) {
	return a > b ? a : b;
}
int min_num(ll a, ll b) {
	return a < b ? a : b;
}
using namespace std;
int main()
{
	ll n, max_sum = 0, min_sum = 0, ev_ev = 1000000, nev_ev = 1000000, nev_nev = 1000000, answer;
	ifstream file("C:\\Users\\User\\Desktop\\егэ инф\\27\\inf_26_04_21_27a.txt");
	if (file.is_open()) {
		file >> n;
		while (!file.eof()) {
			ll a1, a2;
			file >> a1 >> a2;
			if (!file.eof()) {
				//cout << a1 << " " << a2 << endl << endl;
				if (a2 % 2 != 0) {
					max_sum += max_num(a1, a2);
					min_sum += min_num(a1, a2);
				}
				if ((a2 % 2 != 0) and (max_num(a1, a2) % 2 == 0)) {
					if (ev_ev > (a1 + a2)) ev_ev = a1 + a2;
				}
				if ((a2 % 2 != 0) and (a1 % 2 != 0)) {
					if (nev_ev > (a1 + a2)) nev_ev = a1 + a2;
				}
			}
		}
	}
	file.close();
	cout << nev_ev << "  " << max_sum << " " << min_sum << endl << endl;
	if ((max_sum % 2 == 0) and (min_sum % 2 == 0)) answer = max_sum + min_sum - ev_ev;
	if ((max_sum % 2 != 0) and (min_sum % 2 == 0)) answer = max_sum + min_sum - nev_ev;
	if ((max_sum % 2 != 0) and (min_sum % 2 != 0)) answer = max_sum + min_sum - nev_ev - ev_ev;
	if ((max_sum % 2 == 0) and (min_sum % 2 != 0)) answer = max_sum + min_sum;
	cout << answer;
}