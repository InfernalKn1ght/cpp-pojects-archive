#include <iostream>
#include <ctime>
using namespace std;
void print(int arr[], int  n) {
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}
int main()
{
    srand(time(0));
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
    print(arr, n);
    for (int i = 1; i < n; i++) {
        bool F = 0;
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                F = 1;
            }
        }
        if (F == 0) break;
    }
    print(arr, n);
}