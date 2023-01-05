#include <iostream>
#include <ctime>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
void print(set<int> x) {
	for (auto i : x) cout << i << " ";
	cout << endl;
}
int main()
{
	srand(time(0));
	int x;
	set<int> a_set, b_set;


	for (int i = 1; i <= rand() % 50 + 20; i++) a_set.insert(rand() % 200);
	for (int i = 1; i <= rand() % 50 + 20; i++) b_set.insert(rand() % 200);
	cout << "a_set: ";
	print(a_set);
	cout << endl << "b_set: ";
	print(b_set);


	cout << endl << "delete item from a_set: ";
	cin >> x;
	auto result = a_set.erase(x);
	if (result) cout << "item was deleted" << endl;
	else cout << "item wasn't found" << endl;
	cout << "a_set: ";
	print(a_set);


	cout << endl << "add item to a_set: ";
	cin >> x;
	a_set.insert(x);
	cout << "a_set: ";
	print(a_set);


	/*cout << endl;
	for (auto i : a_set) {
		if (b_set.find(i) != b_set.end()) cout << i << " ";
	}*/

	set <int> mySet = a_set;
	//mySet.insert(8);
	set <int> mySet2 = b_set;
	set <int> mySet3;
	set_intersection(mySet.begin(), mySet.end(), mySet2.begin(), mySet2.end(), inserter(mySet3, mySet3.begin()));
	print(mySet3);


	vector<int> v1{ 1,2,3,4,5,6,7,8 };
	vector<int> v2{ 5,  7,  9,10 };
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<int> v_intersection;

	set_intersection(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		back_inserter(v_intersection));
	for (int n : v_intersection)
		cout << n << ' ';
	cout << endl;
	int s[10] = { 12,4,56,78,86,78,678,1,124,7 };
	sort(s, s + 10);
	for (int i = 0; i < 10; i++) cout << s[i] << " ";
}
