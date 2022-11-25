#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

//Used for Initialization
bool firstEntrance = true;

string name;

int Exit = 0;

//The Item class that we use for storing data
class item 
{
public:
	string itemName = "";
	string itemID;
	int itemCount = 0;
};

//Our items are here!
list<item> item_list = {  };

//Write our data to console
void render(){
	//Clear the console
	system("cls");
	//Write warehouse name
	cout << "	" << name << "'s Warehouse" << "\n\n"<< endl;
	cout << "Current Items in your Warehouse:\n\n";

	//Loop throught all of the items and print them on console
	list<item>::iterator temp = item_list.begin();
	for (int i = 0; i < item_list.size(); i++) {
		cout << i << ".   Item Name: " << (*temp).itemName << " Item ID: " << (*temp).itemID << " Item Count: " << (*temp).itemCount << endl;
		advance(temp, 1);
	}
	cout << "\n";
}

void initialize() {
	//When we first open the app, program asks for our name
	firstEntrance = false;
	cout << "Welcome to the Warehouse Application. Please Enter Your Warehouse Name: ";
	cin >> name;
	render();
}

int main() {
	if (firstEntrance == true) {
		initialize();
	}
	do {
		int choice;
		//Get input from user
		cout << "Choose an action:\n\n";
		cout << "1) Add new Item\n";
		cout << "2) Delete an Item\n";
		cout << "3) Edit an Item\n";
		cout << "4) Exit\n" << endl;
		cout << "Your action: ";
		cin >> choice;

		//Do things according to the choice
		if (choice == 1) {
			//Add new item
			item tempItem;
			string iName;
			string iID;
			int iCount;
			cout << "Enter Item Name: ";
			cin >> iName;
			cout << "\nEnter Item ID: ";
			cin >> iID;
			cout << "\nEnter Item Count: ";
			cin >> iCount;
			tempItem.itemName = iName;
			tempItem.itemCount = iCount;
			tempItem.itemID = iID;
			item_list.push_back(tempItem);
		}
		else if (choice == 2) {
			//Delete an item
			int num;
			cout << "Select an Index to delete: ";
			cin >> num;
			while (num >= item_list.size()) {
				cout << "Invalid Index No!\n";
				cout << "Select an Index to delete: ";
				cin >> num;
			}
			list<item>::iterator itr1;
			itr1 = item_list.begin();
			advance(itr1, num);
			item_list.erase(itr1);
		}
		else if (choice == 3) {
			//Delete an item
			int num;
			int count;
			char choice;
			string name;
			cout << "Select an Index to edit: ";
			cin >> num;
			while (num >= item_list.size()) {
				cout << "Invalid Index No!\n";
				cout << "Select an Index to edit: ";
				cin >> num;
			}
			list<item>::iterator itr1;
			itr1 = item_list.begin();
			advance(itr1, num);
			cout << "\nDo you want to edit the name?(y/n)";
			cin >> choice;
			if (choice == 'y') {
				cout << "Enter the new Name: ";
				cin >> name;
				(*itr1).itemName = name;
			}
			cout << "\nDo you want to edit the ID?(y/n)";
			cin >> choice;
			if (choice == 'y') {
				cout << "Enter the new ID: ";
				cin >> name;
				(*itr1).itemID = name;
			}
			cout << "\nDo you want to edit the count?(y/n)";
			cin >> choice;
			if (choice == 'y') {
				cout << "Enter the new count: ";
				cin >> count;
				(*itr1).itemCount = count;
			}
		}
		else if (choice == 4) {
			Exit = 1;
			exit(0);
		}
		else {
			cout << "Invalid operation! ";
		}
		render();
	} while (Exit != 1);

	return 0;
}