#include <iostream>
#include <vector>
#include <map>
using namespace std;
void print(vector <pair<int, int>> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i].first << " " << v[i].second << "    ";
}
vector <pair <int, int>> create_moves(pair <int, int> values) {
	vector <pair <int, int>> v;
	v.push_back(make_pair(values.first + 1, values.second));
	v.push_back(make_pair(values.first, values.second + 1));
	v.push_back(make_pair(values.first * 2, values.second));
	v.push_back(make_pair(values.first, values.second * 2));
	return v;
}
vector <pair<int, int>>game(pair <int, int> moves) {
	vector <pair<int, int>> v;
	vector <pair<int, int>> moves1 = {moves};
	for (int i = 0; i < moves1.size(); i++) {
		vector <pair <int, int>> buf = create_moves(moves1[i]);
		for (int j = 0; j < buf.size(); j++) {
			v.push_back(buf[j]);
		}
	}
	return v;
}
int conditions(vector<pair <int, int>> moves, int value) {
	int sum = 0;
	for (int i = 0; i < moves.size(); i++) {
		if ((moves[i].first + moves[i].second) >= value) sum++;
	}
	if (sum == moves.size()) return 2;
	if ((sum < moves.size()) and (sum > 0)) return 1;
	if (sum == 0) return 0;
}
int main()
{
	for (int j = 1; j <= 69; j++) {
		pair <int, int> start = make_pair(7, j);
		vector <pair<int, int>> P1 = game(start);
		if (conditions(P1, 77) == 0) {
			bool f = 0;
			for (int i = 0; i < P1.size(); i++) {
				vector <pair<int, int>> B1 = game(P1[i]);
				if (conditions(B1, 77) == 0) {
					int f1 = 0;
					for (int i1 = 0; i1 < B1.size(); i1++) {
						vector <pair<int, int>> P2 = game(B1[i1]);
						if (conditions(P2, 77) > 0) f1++;
					}
					if (f1 == 4) {
						f = 1;
						break;
					}
				}
			}
			if (f == 1) cout << 7 << " " << j << endl;
		}
	}
}