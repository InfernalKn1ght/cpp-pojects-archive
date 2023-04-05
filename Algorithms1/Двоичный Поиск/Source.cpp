#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x[11] = { 124,214,214,2,1421,4,5,6,6575,6,85453 };
    int size = sizeof(x) / sizeof(int);
    sort(x, x + size);
    for (int i = 0; i < size; i++) cout << x[i] << " ";
    cout << endl;
    int z, law = 0, high = size - 1, mid;
    cin >> z;
    while (law <= high) {
        mid = (law + high) / 2;
        if (x[mid] > z)  high = mid - 1;
        if (x[mid] < z) law = mid + 1;
        if (x[mid] == z) {
            cout << mid;
            break;
        }
    }
}
