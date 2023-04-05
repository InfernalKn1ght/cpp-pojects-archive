#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    int n, sum=0, i=0, counter=0;
    vector <int> v;
    ifstream file("C:\\Users\\User\\Desktop\\егэ инф\\27\\27_demo_A.txt");
    file >> n;
    while (!file.eof()) {
        int num;
        file >> num;
        if (!file.eof()) {
            v.push_back(num);
            sum += num;
            if (num % 2 != 0) counter++;
            i++;
        }
    }
    cout << counter << endl << endl;
    file.close();
    counter = counter % 10;
    int ind = 0, sum1 =0;
    i = 0;
    while (ind < counter) {
        if (v[i] % 2 != 0) {
            ind++;
        }
        sum1 += v[i];
        i++;
    }
    int sum2 = 0;
    ind = 0, i = v.size()-1;
    while (ind < counter) {
        if (v[i] % 2 != 0) {
            ind++;
        }
        sum2 += v[i];
        i--;
    }
    cout << sum - min(sum1, sum2);
}
