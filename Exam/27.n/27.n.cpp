#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	int ch_n = 111111110, n_n = 111111110, n_ch = 11111110, q, min_sum= 0, max_sum = 0;
	ifstream file("C:\\Users\\User\\Desktop\\егэ инф\\27\\27_26A.txt");
	file >> q;
	while (!file.eof()) {
		int num1, num2;
		file >> num1 >> num2;
		if (!file.eof()) {
			cout << num1 << " " << num2 << endl;
			if (num2 % 2 != 0) {
				//cout << num1 << " " << num2 << endl;
				if ((num1 % 2 != 0) and (num2 % 2 != 0) and ((num1+ num2) < n_n)) n_n = num1 + num2;
				if (((min(num1, num2)) % 2 != 0) and ((max(num1, num2)) % 2 == 0) and ((num1 + num2) < ch_n)) ch_n = num1 + num2;
				if (((max(num1, num2)) % 2 != 0) and ((min(num1, num2)) % 2 == 0) and ((num1 + num2) < ch_n)) n_ch = num1 + num2;
				min_sum += min(num1, num2);
				max_sum += max(num1, num2);
			}
		}
	}
	cout << ch_n << "    " << n_ch << "    " << n_n <<endl << max_sum << "    " << min_sum;
}
