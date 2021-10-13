// Importing input output operations file
#include <iostream>
// Importing file class
#include <fstream>
// Importing standard library file
#include <stdlib.h>

using namespace std;

// Variables declared outside any function
// hence scope is global, hence global variables
string fname, lname, phone_num;

// Methods

// Helper Methods followed by
// Main driver method

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);

// Method 1
// Helper method
void self_exit()
{
	system("cls");
	cout << "\n\n\n\t\tThank You for using Contact-Saver!";
	exit(1);
}

// Method 2
// Helper method
void help()
{
	cout << "Help Center";
	cout << endl << endl;
	system("pause");
	system("cls");
}

// Method 3
// Helper method
void addContact()
{
	ofstream phone("number.txt", ios::app);
	system("cls");
	cout << "\n\n\tEnter First Name : ";
	cin >> fname;
	cout << "\n\tEnter Last Name : ";
	cin >> lname;
	cout << "\n\tEnter Phone Number : ";
	cin >> phone_num;

	if (check_digits(phone_num) == true) {
		if (check_numbers(phone_num) == true) {
			if (phone.is_open()) {
				phone << fname << " " << lname << " "
					<< phone_num << endl;
				cout << "\n\tContact saved successfully !";
			}
			else {
				cout << "\n\tError in opening record!";
			}
		}
		else {
			cout << "\n\tOnly numbers are allowed!";
		}
	}
	else {
		cout << "\n\tPhone number should be of 10 digits "
				"only.";
	}
	cout << endl << endl;
	system("pause");
	system("cls");
	phone.close();
}

// Method 4
// Helper method
void searchContact()
{
	bool found = false;
	ifstream myfile("number.txt");
	string keyword;
	cout << "\n\tEnter Name to search : ";
	cin >> keyword;
	while (myfile >> fname >> lname >> phone_num) {
		if (keyword == fname || keyword == lname) {
			system("cls");
			cout << "\n\n\n\t\tCONTACT DETAILS";
			cout << "\n\nFirst Name : " << fname;
			cout << "\nLast Name : " << lname;
			cout << "\nPhone Number : " << phone_num;
			found = true;
			break;
		}
	}
	if (found == false)
		cout << "\nNo such contact is found!";

	cout << endl << endl;
	system("pause");
	system("cls");
}

// Method 5
// Helper method
bool check_digits(string x)
{
	if (x.length() == 10)
		return true;
	else
		return false;
}

// Method 6
// Helper method
bool check_numbers(string x)
{
	bool check = true;

	for (int i = 0; i < x.length(); i++) {
		if (!(int(x[i]) >= 48 && int(x[i]) <= 57)) {
			check = false;
			break;
		}
	}

	if (check == true)
		return true;

	if (check == false)
		return false;

	cout << endl << endl;
	system("pause");
	system("cls");
}

// Method 7
// Main driver method
int main()
{
	int choice;
	system("cls");
	system("color 0A");
	while (1) {
		cout << "\n\n\n\t\t\tCONTACT SAVER";
		cout << "\n\n\t1. Add Contact\n\t2. Search "
				"Contact\n\t3. Help\n\t4. Exit\n\t> ";
		cin >> choice;

		// Switch case
		switch (choice) {
		case 1:
			addContact();
			break;

		case 2:
			searchContact();
			break;

		case 3:
			help();
			break;

		case 4:
			self_exit();
			break;

		default:
			cout << "\n\n\tInvalid Input!";
		}
	}
	return 0;
}
