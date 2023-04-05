#include <iostream>
#include <vector>
using namespace std;
int n, num1, num2;
vector < vector <string> > towers1(n, vector<string>());
vector < vector <string> > towers(n, vector<string>());
vector < vector <string> > towers2(n, vector<string>());
void print_vector()
{
    for (int i = 0; i < towers.size(); i++) {
        cout << "      ";
        for (int j = 0; j < towers[i].size(); j++)
            cout << towers[i][j];
        cout << "      ";
        for (int j = 0; j < towers1[i].size(); j++)
            cout << towers1[i][j];
        cout << "      ";
        for (int j = 0; j < towers2[i].size(); j++)
            cout << towers2[i][j];
        cout << endl;
    }
}
void print_one_vector(vector <vector<string>> v)
{

    //for (int i = v.size()-1; i >= 0; i--) {
    for (int j = 0; j < v.size(); j++)
        cout << v[i][j] << endl;

}
void print_vector1()
{
    cout << endl << endl;
    print_one_vector(towers);
    cout << endl << endl;
    print_one_vector(towers1);
    cout << endl << endl;
    print_one_vector(towers2);
    cout << endl << endl;
}


vector <vector<string>> fill_vector()
{
    vector < vector <string> > c;
    vector <string> c1;
    string c2;
    int g, p;
    for (int i = n; i >= 1; i--) {
        c2 = "";
        g = 2 * i - 1;
        p = (21 - g) / 2;
        for (int j = 0; j < p; j++)
            c2 += " ";
        for (int j = 0; j < g; j++)
            c2 += "*";
        for (int j = 0; j < p; j++)
            c2 += " ";
        c1.push_back(c2);
    }
    c.push_back(c1);
    /*for (int i = n; i >= 1; i--) {
        c.push_back(vector<string>(21));
        for (int j = 0; j < c[i].size(); j++) c[i][j] = "*";
        //for (int i = 0; i < c.size(); i++)
            //for (int j = 0; j < c[i].size(); j++) c[i][j] = "*";
    }*/
    return c;
}
int main()
{
    int a = 1;
    cin >> n;
    towers = fill_vector();
    print_vector1();
    string q = "s";
    while (q == "s")
    {
        cin >> num1;
        cin >> num2;
        if ((num1 == 1) && (num2 == 2)) {
            towers1.push_back(towers[towers.size() - 1]);
            towers.pop_back();
        }
        if ((num1 == 1) && (num2 == 3)) {
            towers2.push_back(towers[towers.size() - 1]);
            towers.pop_back();
        }
        if ((num1 == 2) && (num2 == 1)) {
            towers.push_back(towers1[towers1.size() - 1]);
            towers1.pop_back();
        }
        if ((num1 == 2) && (num2 == 3)) {
            towers2.push_back(towers1[towers1.size() - 1]);
            towers1.pop_back();
        }
        if ((num1 == 3) && (num2 == 1)) {
            towers.push_back(towers2[towers2.size() - 1]);
            towers2.pop_back();
        }
        if ((num1 == 3) && (num2 == 2)) {
            towers1.push_back(towers2[towers2.size() - 1]);
            towers2.pop_back();
        }
        print_vector1();
        cin >> q;
    }
}
