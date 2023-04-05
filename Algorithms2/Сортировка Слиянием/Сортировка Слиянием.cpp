#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void print(vector <int> v) {
    cout << endl << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl << endl;
}
vector <int> separation(vector <int> v, bool m) {
    vector <int> buf;
    int start = 0, end = v.size() / 2;
    if (m == 1) start = v.size() / 2, end = v.size();
    for (int i = start; i < end; i++) buf.push_back(v[i]);
    return buf;
}
vector <int> fusion(vector <int> a, vector <int> b) {
    vector <int> buf;
    while (!a.empty() and !b.empty()) {
        if (a[0] <= b[0]) {
            buf.push_back(a[0]);
            a.erase(a.begin());
        }
        else {
            buf.push_back(b[0]);
            b.erase(b.begin());
        }
    }
    if (!a.empty()) for (int i = 0; i < a.size(); i++) buf.push_back(a[i]);
    else if (!b.empty()) for (int i = 0; i < b.size(); i++) buf.push_back(b[i]);
    return buf;
}
vector <int> function(vector <int> v) {
    if (v.size() > 2) return fusion(function(separation(v, 0)), function(separation(v, 1)));
    return fusion(separation(v, 0), separation(v, 1));
}
int main()
{
    srand(time(0));
    int n;
    vector <int> arr;


    cin >> n;
    for (int i = 0; i < n; i++) arr.push_back(rand()%1000);
    print(arr);


    print(function(arr));
}