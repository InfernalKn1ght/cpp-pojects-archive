#include <iostream>
#include <vector>
#include <windows.h>
#define ll long long
using namespace std;
int main()
{
	//6
	//решето Эратосфена
	int n, p = 2;
	cin >> n;
	vector <bool> a;
	for (int i = 0; i <= n; i++) a.push_back(true);
	while (p * p <= n) {
		for (int i = p * 2; i < a.size(); i += p) a[i] = false;
		for (int i = p + 1; i < a.size(); i++) {
			if (a[i] == true) {
				p = i;
				break;
			}
		}
	}
	for (int i = 2; i < a.size(); i++) if (a[i] == true) cout << i << " ";
}
