#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	for (int i = 10; i <= 2021; i++) {
		int sum1 = 0, sum2 = 0;
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			if (((j + 1) % 2) == 0) sum1 += str[j] - '0';
			if (((str[j] - '0') % 2) == 0) sum2 += str[j] - '0';
		}
		if (abs(sum1 - sum2) == 13) cout << str << "  " << abs(sum1 - sum2) << endl;;
	}
}
