#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	/*string str = "";
	str = string(70, '8');
	cout << str << endl << endl;
	while ((str.find("2222")!= string::npos) or (str.find("8888")!=string::npos)) {
		int i = str.find("2222");
		if (i != -1) str.replace(i, 4, "88");
		else {
			i = str.find("8888");
			str.replace(i, 4, "22");
		}
		cout << str << endl << endl;
	}
	cout << str;*/
	for (int x = 1; x <= 40; x++) {
		for (int y = 1; y <= 40; y++) {
			for (int z = 1; z <= 40; z++) {
				string str = "0" + string(x, '1') + string(y, '2') + string(z, '3') + "0";
				while (str.find("00") == string::npos) {
					int i = str.find("01");
					if (i != -1) str.replace(i, 2, "210");
					i = str.find("02");
					if (i != -1) str.replace(i, 2, "3101");
					i = str.find("03");
					if (i != -1) str.replace(i, 2, "2012");
				}
				int c1 = 0, c2=0, c3 = 0;
				for (int j = 0; j < str.size(); j++) {
					if (str[j] == '1') c1++;
					if (str[j] == '2') c2++;
					if (str[j] == '3') c3++;
				}
				if (c1 == 70 and c2 == 56 and c3 == 23) cout << x + y + z + 2;
			}
		}
	}
}
