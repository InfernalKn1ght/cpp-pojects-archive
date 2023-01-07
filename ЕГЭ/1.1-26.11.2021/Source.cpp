#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    string s, foo;
    vector<unsigned> arr;
    unsigned max_length = 0;
    ifstream file("C:\\Users\\User\\Desktop\\егэ инф\\24\\24 (1).txt");
    file >> s;
    file.close();
    //cout << s << endl;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'D') {
            arr.push_back(foo.length());
            foo = "";
        }
        else
            foo += s[i];
    }
    for (int i = 0; i < arr.size() - 1; i++)
        if (arr[i] + arr[i + 1] + 1 > max_length)
            max_length = arr[i] + arr[i + 1] + 1;

    cout << max_length << endl;

}