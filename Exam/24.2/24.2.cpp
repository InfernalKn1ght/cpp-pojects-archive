#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string str;
    ifstream file("C:\\Users\\User\\Desktop\\егэ инф\\24\\24 (1).txt");
    file >> str;
    file.close();
    int counter = 0, buf = 0, error = 0, i = 0, marker;
    while (i < str.size()) {
        if (str[i] == 'D') {
            error++;
            if (error == 1) marker = i + 1;
        }
        if (error < 2) {
            counter++;
            i++;
        }
        else {
            error = 0;
            if (buf < counter) buf = counter;
            i = marker;
            counter = 0;
        }
    }
    cout << buf;
}
