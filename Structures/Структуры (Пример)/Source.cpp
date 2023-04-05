#include <iostream>
#include <ctime>
using namespace std;
int n;
struct sotrudnik
{
    string name, last_name;
    int age;
};
int main()
{
    srand(time(0));
    string m = "go";
    while (m == "go") {
    TryAgain:
        cout << "Do you want to continue?" << " " << "Type go or stop: ";
        cin >> m;
        if (m == "stop") break;
        if ((m != "stop") && (m != "go")) {
            cout << "Error!" << " " << "Try again:" << endl;
            goto TryAgain;
        }
        cout << "Amount of array cells: ";
        cin >> n;
        sotrudnik* mass = new sotrudnik[n];
        sotrudnik b;
        for (int i = 0; i < n; i++) {
            mass[i].name = char('a' + rand() % 28);
            mass[i].last_name = char('a' + rand() % 28);
            mass[i].age = rand() % 100;
        }
        for (int i = 0; i < n; i++) cout << "name: " << mass[i].name << " " << "last_name: " << mass[i].last_name << " " << "age: " << mass[i].age << endl;
        cout << "\n" << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mass[i].age < mass[j].age) {
                    b = mass[i];
                    mass[i] = mass[j];
                    mass[j] = b;
                }
            }
        }
        for (int i = 0; i < n; i++) cout << "name: " << mass[i].name << " " << "last_name: " << mass[i].last_name << " " << "age: " << mass[i].age << endl;
        delete[] mass;
    }
}
