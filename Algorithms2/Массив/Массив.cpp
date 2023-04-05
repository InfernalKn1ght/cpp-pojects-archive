#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    vector <vector <int>> mass;
    int rows1, cols1, counter = 0;
    cin >> rows1 >> cols1;
    for (int i = 0; i < rows1; i++) {
        vector <int> buf_v;
        for (int j = 0; j < cols1; j++) {
            int buf;
            cin >> buf;
            counter += buf;
            if (i > 0)  buf_v.push_back(counter + mass[i - 1][j]);
            else buf_v.push_back(counter);
        }
        mass.push_back(buf_v);
        counter = 0;
    }
    cout << endl << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}