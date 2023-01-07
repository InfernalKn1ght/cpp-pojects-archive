#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
vector <pair <int, int>> create_moves(pair <int, int> values) {
	vector <pair <int, int>> v;
	v.push_back(make_pair(values.first + 1, values.second));
	v.push_back(make_pair(values.first, values.second + 1));
	v.push_back(make_pair(values.first * 2, values.second));
	v.push_back(make_pair(values.first, values.second * 2));
	return v;
}
vector<vector <pair <int, int>>> V;
void game(pair <int, int> moves, int move_counter) {
	if (move_counter < 5) {
		vector <pair <int, int>> v = create_moves(moves);
		V.push_back(v);
		for (int i = 0; i < 4; i++) game(v[i], move_counter + 1);
	}
}
int main()
{
	game(make_pair(12, 20), 1);
	int c = 1;
	int c1 = 0;
	for (int i = 0; i < V.size(); i++) {
		for (int j = 0; j < V[i].size(); j++) {
			cout << V[i][j].first + V[i][j].second << " ";
			if ((i + 1) * (j + 1) == pow(4, c) + c1) {
				cout << endl <<endl;
				c1 = (i + 1) * (j + 1);
				c++;
			}
		}
	}
}

