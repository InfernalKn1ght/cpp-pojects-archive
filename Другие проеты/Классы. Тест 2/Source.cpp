#include <iostream>
#include <ctime>
using namespace std;
class mass
{
public:
	int a;
	void initialzation()
	{
		cout << "Enter size of mass:";
		cin >> a;
		m[a];
	}
	void fill_mass()
	{
		for (int i = 0; i < a; i++)
			m[i] = i * 7;
	}
	void show_data()
	{
		for (int i = 0; i < a; i++)
			cout << m[i] << " ";
	}
private:
	double m[];
};
int main()
{
	srand(time(0));
	/*int a1 = 10;
	int* a;
	double* p[100];
	double m[200];

	for (int i = 0; i < 10; i++)
		p[i] = &m[i];

	for (int i = 0; i < 10; i++) {
		m[i] = i;
		cout << m[i] << endl;
	}
	cout << "\n" << "\n";
	for (int i = 0; i < 10; i++) {
		*p[i] = i * 2;
		cout << m[i] << endl;
	}*/

	mass mass;
	mass.initialzation();
	mass.fill_mass();
	mass.show_data();
}
