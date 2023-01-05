#include <iostream>
using namespace std;
struct list {
	string last_name;
	int year;
	list* next;
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
		cout << "List of functions: " << endl << "press p to print list" << endl << "press i to input name and year" << endl << "press s to search the person by year" << endl << "print del_l to delete last element" << endl << "print del_f to delete first element" << endl << "print add_f to add first element" << endl << "print add_l to add last element" << endl << "Enter your choice: ";
		cin >> marker2;
		if (marker2 == "i") {
			while (true) {
				if (buffer != NULL) {
					cout << "Continue? Print go or any key to stop: ";
					cin >> marker1;
					if (marker1 == "go") {
						if (!first_time) {
							buffer->next = new list;
							buffer = buffer->next;
							buffer->next = NULL;
						}
					}
					else break;
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
		if (marker2 == "s") {
			bool found = false;
			list* buffer1 = list1;
			int search;
			cout << "Enter a year: ";
			cin >> search;
			do {
				if (search == buffer1->year) {
					cout << endl << "Last name: " << buffer1->last_name << endl << "Year: " << buffer1->year << endl << endl;
					found = true;
				}
				buffer1 = buffer1->next;
			} while (buffer1 != NULL);
			if (!found) cout << "not found" << endl << endl;
		}
		if (marker2 == "del_l") {
			list* buffer1 = list1;
			while (buffer1->next->next != NULL) buffer1 = buffer1->next;
			buffer1->next = NULL;
		}
		if (marker2 == "del_f") {
			list1 = list1->next;
		}
		if (marker2 == "add_f") {
			list* buffer1 = new list;
			cout << "Input last name: ";
			cin >> buffer1->last_name;
			cout << "Input year: ";
			cin >> buffer1->year;
			buffer1->next = list1;
			list1 = buffer1;
		}
		if (marker2 == "add_l") {
			list* buffer1 = list1;
			while (buffer1->next != NULL) buffer1 = buffer1->next;
			buffer1->next = new list;
			buffer1 = buffer1->next;
			buffer = buffer1;
			buffer1->next = NULL;
			cout << "Input last name: ";
			cin >> buffer1->last_name;
			cout << "Input year: ";
			cin >> buffer1->year;
		}
		marker1 = "go", marker2 = "";
	}
}
