#include <iostream>
using namespace std;
int main()
{
    int a[5] = { 1,5,7,9,2 };
    int* p = a;
    for (int i = 0; i < 5; i++) {
        cout << *p;
        p++;
    }
}
