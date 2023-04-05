#include <iostream>
#include <map>
#include <vector>
//#include <cmath>
#include <algorithm>
#include <set>

#define ll long long
using namespace std;
map <ll, int> b;
vector <ll> answer;
vector <ll> simple;
set <ll> answer_s;
void print(map <ll, int> m) {
	for (auto i : m) cout << i.first << " " << i.second << endl;
}
void print_v(vector <ll> v) {
	cout << endl << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl << endl;
}
void print_s(set <ll> s) {
	cout << endl << endl;
	for (auto i : s) cout << i << " ";
	cout << endl << endl;
}
bool search(ll x) {
	bool m = false;
	for (ll i = 0; i < answer.size(); i++) {
		if (answer[i] == x) {
			m = true;
			break;
		}
	}
	return m;
}
/*int f(ll power, ll num) {
	ll sum = 0;
	if (num < simple.size()) {
		for (ll i = 0; i <= b[simple[num]]; i++) {
			ll buf = 1;
			if (i != 0) buf = pow(simple[num], i);
			sum = power * buf;
			sum = sum * f(sum, num + 1);
			if (!search(sum)) answer.push_back(sum);
			cout << "sum: " << sum << " " << "power: " << power << " " << "map: " << simple[num] << " " << "buf: " << buf << endl;
			//sum = sum * f(sum, num + 1);
		}
	}
	else return 1;
}*/
void f(ll power, ll num) {
	if (num < simple.size()) {
		for (ll i = 0; i <= b[simple[num]]; i++) {
			ll sum = power * pow(simple[num], i);
			f(sum, num + 1);
			answer_s.insert(sum);
		}
	}
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

	f(1, 0);

	sort(answer.begin(), answer.end());

	//print_v(answer);
	print_s(answer_s);
	cout << "amount of elements: " << answer_s.size();
}
/*#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
typedef long long ll;

using namespace std;

map <ll,ll> bo;
vector <ll> vo;
ll a=1;
ll delit=0;

ll mypow(ll a, ll b)
{
	ll x=1;
	for (int i=0;i<b;i++)
		x=x*a;
	return x;
}
ll recur(ll r,ll a)
{
	bool isend=false;
	auto it=bo.begin();
	for (int i=0;i<a;i++)
	{
		it++;
	if (it==bo.end())
	{
		 isend=true;
	}
	}
	if (!isend)
	{
	int key=it->first;
	int val=it->second;
	ll sum;
	for (int i=0;i<=val;i++)
	{
		sum=r*mypow(key,i);
		sum=sum*recur(sum,a+1);
	if (a==bo.size()-1)
	{
		vo.push_back(sum);
		//cout<<"i="<<i<<"r="<<r<<"a="<<a<<"sum="<<sum<<endl;
	delit++;
	}
	}
	return sum;
	} else return 1;
}


int main()
{
	ll a=12345678900;
   // ll a=100000000000;
	ll b=2;
	while (a>1)
	{
	if (a%b==0)
		{
			auto x=bo.emplace(b,1);
			if (!x.second) bo[b]++;
			a=a/b;
			b=2;
		} else b++;
	}
//cout<<"vsego el="<<bo.size()<<endl;

recur(1,0);
cout<<"vsego del="<<delit;
//recur(3,2);
//cout<<"rec5="<<recur();
//
 for (auto& x: bo)
	cout << " [" << x.first << ':' << x.second << ']';

	cout<<endl;
	sort(vo.begin(),vo.end());
	for (ll x: vo)
	{
		cout <<x<<",";
	}
//
	return 0;
} */
