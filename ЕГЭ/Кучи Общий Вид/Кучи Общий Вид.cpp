#include <iostream>
#include <vector>
#include <map>
using namespace std;
void print1(vector <bool> v) {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";	// вывод ответов на экран
}
vector <pair <int, int>> create_moves(pair <int, int> values) {
	vector <pair <int, int>> v;	
	v.push_back(make_pair(values.first, values.second)); // создание всех возможных ходов из одного значения в векторе; если количество возможных ходов равно а, то аналогичных строк а
	return v;
}
vector <pair<int, int>>game(vector <pair<int, int>> moves) { 
	vector <pair<int, int>> v;
	for (int i = 0; i < moves.size(); i++) {
		vector <pair <int, int>> buf = create_moves(moves[i]);
		for (int j = 0; j < buf.size(); j++) {
			v.push_back(buf[j]); // заполнение вектора со всеми возможными результатми ходов игрока
		}
	}
	return v;
}
vector <bool> conditions(vector<pair <int, int>> moves, int value) {
	vector <bool> v;
	for (int i = 0; i < moves.size(); i++) {
		if (moves[i].first + moves[i].second >= value) v.push_back(1); // заполнение вектора проигрышей/выигрышей; условие победы зависит от задачи
		else v.push_back(0);
	}
	return v;
}
vector <bool> l(vector <bool> wins) {
	bool l = 0;
	vector <bool> v;
	for (int i = 0; i < wins.size(); i++) {
		l = l || wins[i]; // анализ проигрышей/выигрышей логическое сложение
		if ((i + 1) % 3 == 0) v.push_back(l), l = 0; // остаток от деления на a, если а количество возможных ходов из одной точки
	}
	return v;
}
vector <bool> l1(vector <bool> wins) {
	bool l = 1;
	vector <bool> v;
	for (int i = 0; i < wins.size(); i++) {
		l = l && wins[i]; // анализ проигрышей/выигрышей логическое умножение
		if ((i + 1) % 3 == 0) v.push_back(l), l = 1; // остаток от деления на a, если а количество возможных ходов из одной точки
	}
	return v;
}
int main()
{
	int S1 = 0; // значение первой кучи; если куча одна, то равно 0
	int value = 68; // позиция выигрыша
	for (int i = 1; i <= 67; i++) {
		vector <pair<int, int>> start = { make_pair(S1, i) }; // вектор с первым значением
		vector <pair<int, int>> P1; // векторы результатов ходов игроков
		vector <pair<int, int>> B1;
		vector <pair<int, int>> P2;
		vector <pair<int, int>> B2;
		P1 = game(start);
		B1 = game(P1);
		int k = 0;
		while (k < B1.size()) { // удаление лишних элементов вектора; для 20 - P1; для 21 - B1
			vector <pair<int, int>> buf = { B1[k] };
			if (l(conditions(game(buf), value))[0] == 1) {
				B1.erase(B1.begin() + k);
			}
			else k++;
		}
		B2 = game(game(B1));
		cout << i << ": ";
		print1(l1(l(conditions(B2, value)))); // вывод ответов на экрын; для 20 - P2; для 21 - B2
		cout << endl << endl << endl;
	}
}