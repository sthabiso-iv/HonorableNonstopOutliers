// Importing input output operations file
#include <iostream>
// Importing file class
#include <fstream>
// Importing standard library file
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Variables declared outside any function
// hence scope is global, hence global variables
string listn, fname, lname, phone_num;

// Methods

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);
void sortContact();
void deleteDuplicates();

void sortContact(){
    // Empty vector holding all names from file
    vector<string> fname;

    // Read names from file LineUp.txt
    ifstream in("number.txt");
    if(!in.is_open())
        cout << "Unable to open file\n";

    // this is wrong, by the way: while(in.good()){
    string word;
    while(getline(in, word))
            fname.push_back(word);

    sort(fname.begin(), fname.end());

    // Loop to print names
    for (size_t i = 0; i < fname.size(); i++)
        cout << fname[i] << '\n';


}
// Method 1
// Helper method
void self_exit()
{
	system("cls");
	cout << "\n\n\n\t\tThank You for using In the Loop";
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

	while (1) {
		cout << "\n\n\n\t\t\tSearch, Add and Sort";
		cout << "\n\n\t1. Add Contact\n\t2. Search "
				"Contact\n\t3. Help\n\t4. Exit\n\t5. Sort\n\t> ";
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

    case 5:
			sortContact();
			break;

		default:
			cout << "\n\n\tInvalid Input!";
		}
	}
	return 0;
}
