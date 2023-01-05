#include <iostream>
#include <map>
#include <ctime>
#include <string>
using namespace std;
void print(map <int, string> m) {
	for (auto i : m) cout << i.first << " " << i.second << endl;
}
int main()
{
	srand(time(0));
	pair <int, string> p;
	cin >> p.first >> p.second;
	cout << p.first << " " << p.second << endl;



	map <int, string> m1;
	int x;
	cin >> x;
	m1.insert(pair <int, string>(x, "158"));
	cin >> x;
	auto it = m1.emplace(x, "1824");
	if (it.second == false) cout << "item wasn't added" << endl;
	else cout << "item was added" << endl;


	try {
		m1.at(1000);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}


	for (int i = 0; i < rand() % 200 + 20; i++) m1.emplace(rand() % 1000 + 250, "item#" + to_string(i));
	print(m1);



	cout << endl << "enter map key: ";
	cin >> x;
	m1[x] = "NEW NAME";
	print(m1);



	cout << endl << "enter map key to erase item: ";
	cin >> x;
	m1.erase(x);
	print(m1);
}
