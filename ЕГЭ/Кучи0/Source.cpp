#include <iostream>
#include <vector>
using namespace std;
bool win(vector <int> v, int s) {
	int sum = v[0] + v[1];
	if (sum >= s) return 1;
	else return 0;
}
vector < vector < int>> moves(vector <int> v) {
	vector < vector < int>> c;
	vector <int> buf = { v[0], v[1] + 1 };
	c.push_back(buf);
	buf = { v[0] + 1, v[1] };
	c.push_back(buf);
	buf = { v[0], v[1] * 2 };
	c.push_back(buf);
	buf = { v[0] * 2, v[1] };
	c.push_back(buf);
	return c;
}
//int move3(vector <int> v, int s) {
//	for (int i = 0; i < 4; i++) {
//		if (win(moves(v)[i], s) == 1) return ;
//	}
//	for (int i = 0; i < 4; i++) {
//		if (game1(moves(v)[i], s, gamer + 1) == "P1 WIN") return "B1 WIN";
//	}
//}
int game1(vector <int> v, int s, int gamer) {
	if (gamer < 3) {
		vector < vector < int>> c = moves(v);
		for (int i = 0; i < 4; i++) {
			if (win(c[i], s) == 1) return 101;
		}
		for (int i = 0; i < 4; i++) {
			if (game1(c[i], s, gamer + 1) == 101) return 201;
		}
	}
	else {
		if (win(v, s) == 1) {
			return 102;
		}
	}
}
int main()
{
	for (int i = 7; i < 70; i++) {
		for (int j = 1; j < 70; j++) {
			vector <int> v = { i, j };
			cout << i << " " << j << "    " << game1(v, 70, 1) << endl;
		}
	}
}
