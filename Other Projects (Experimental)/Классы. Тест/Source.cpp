#include <iostream>
#include <vector>

using namespace std;
/*class students
{
public:
	void out_average()
	{
		double u = 0;
		for (int i = 0; i < 5; i++)
		{
			u += scores[i];
		}
		average = u / 5;
	}
	double get_average()
	{
		return average;
	}
	void set_average(double x)
	{
		average = x;
	}
	void set_name(string x)
	{
		name = x;
	}
	void set_last_name(string x)
	{
		last_name = x;
	}
	void set_scores(int x[])
	{
		for (int i = 0; i < 5; i++)
			scores[i] = x[i];
	}
	students()
	{
		for (int i = 0; i < 5; i++) scores[i] = 4;
	}
	void show_scores()
	{
		for (int i = 0; i < 5; i++)
			cout << scores[i];
	}
	~students()
	{
		cout << "memory cleaned";
	}
private:
	double average;
	string name, last_name;
	int scores[5];
};
class super_students:public students
{
public:
	int super;
};*/
int main()
{
	//string s;
	//int k[5];
	//double a=0, b;
	//string name;
	//students student;
	//students student = new students(3);
	/*student->super = 7;
	cout << "Enter name: ";
	cin >> s;
	student->set_name(s);
	cout << "Enter last name: ";
	cin >> s;
	student->set_last_name(s);
	cout << "Enter scores: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> k[i];
	}
	student->set_scores(k);
	student->out_average();
	cout << "Average: " << student->get_average();*/
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < 10; i++) a.push_back(i * 5);
	for (int i = 0; i < 10; i++) b.push_back(i * 5);
	for (int i = 0; i < a.size(); i++) cout << a[i] << " " << endl;
	if (a == b) cout << "ravni";
	vector < vector <int> > ivector = { {1, 4, 7, 56}, {2, 5, 8}, {3, 6, 9, 7,55,55,5,5} };
	for (int i = 0; i < ivector.size(); i++) for (int j = 0; j < ivector[i].size(); j++) cout << ivector[i][j] << " ";

}
