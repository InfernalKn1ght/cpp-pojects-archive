#include <iostream>
using namespace std;
struct list {
	string last_name;
	int year;
	list* next;
	list* prev;
};

int main()
{
	list* list1 = new list;
	list* buffer = list1;
	bool first_time = true;
	string marker = "go", marker1 = "go", marker2;
	while (marker == "go") {
		cout << "Print go to continue or any key to stop the programm: ";
		cin >> marker;
		if (marker != "go") break;
		cout << "List of functions: " << endl << "press p to print list" << endl << "press i to input name and year" << endl << "press p2 to print list backwards" << endl << "Enter your choice: ";
		cin >> marker2;
		if (marker2 == "i") {
			while (true) {
				if (buffer != NULL) {
					cout << "Continue? Print go or any key to stop: ";
					cin >> marker1;
					if (marker1 == "go") {
						if (!first_time) {
							buffer->next = new list;
							buffer->next->prev = new list;
							buffer->next->prev = buffer;
							buffer = buffer->next;
							buffer->next = NULL;
						}
					}
					else break;
					if (first_time) buffer->prev = NULL;
					cout << "Input last name: ";
					cin >> buffer->last_name;
					cout << "Input year: ";
					cin >> buffer->year;
					first_time = false;
				}
			}
		}
		if (marker2 == "p") {
			list* buffer1 = list1;
			while (buffer1 != NULL) {
				cout << endl << "Last name: " << buffer1->last_name << endl << "Year: " << buffer1->year << endl << endl;
				buffer1 = buffer1->next;
			}
		}
		if (marker2 == "p2") {
			list* buffer1 = list1;
			while (buffer1->next != NULL)buffer1 = buffer1->next;
			while (buffer1 != NULL) {
				cout << endl << "Last name: " << buffer1->last_name << endl << "Year: " << buffer1->year << endl << endl;
				buffer1 = buffer1->prev;
			}
		}
		marker1 = "go", marker2 = "";
	}
}
