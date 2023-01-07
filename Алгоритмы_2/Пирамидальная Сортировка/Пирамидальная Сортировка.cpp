#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
void print_v(vector <int> v) {
	cout << endl << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl << endl;
}
int main()
{
	srand(time(0));

	int n;
	cin >> n;
	vector <int> arr;
	for (int i = 0; i < n; i++) arr.push_back(rand() % 1000);
	print_v(arr);


	int size = arr.size() - 1;
	while (size > 0) {
		for (int i = size / 2 - 1; i >= 0; i--) {
			int left = i * 2 + 1, right = i * 2 + 2;
			if (arr[left] > arr[i]) swap(arr[left], arr[i]);
			if (arr[right] > arr[i]) swap(arr[right], arr[i]);
		}
		swap(arr[0], arr[size]);
		size--;
	}


	print_v(arr);
}