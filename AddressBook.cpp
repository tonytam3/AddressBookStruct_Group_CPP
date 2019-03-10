#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct contact {
	string firstName;
	string lastName;
	int phoneNumber;
	string addressBook;

	struct contact *next;
};

void progInto();
void addContact(struct contact **head);
void editMechanism(struct contact *current);
void searchContact(struct contact *head, int modify);
void displayContact(contact *head);
void removeContact(contact **head);
string lowerCase(string input);

contact *head = NULL;
contact *tail = NULL;

int main() {
	progInto();
}

void progInto() {

	int input = 0;

	do {
		cout << "Welcome, which option number would you like to perform:\n 1) Add Contact\n 2) Remove Contact \n 3) Update Contact\n 4) Search Contact\n 5) Sort Contacts(NOT Functional Yet)\n 6) Display Contact\n 7) Exit\n" << endl;
		cin >> input;
		switch (input) {
		case 1:
			cout << "Performing Add Contact Function..." << endl;
			addContact(&head);
			break;
		case 2:
			cout << "Performing Remove Contact Function..." << endl;
			cout << head<< endl;
			removeContact(&head);
			break;
		case 3:
			cout << "Performing Update Contact Function..." << endl;
			searchContact(head, 1);
			break;
		case 4:
			cout << "Performing Search Contact Function..." << endl;
			searchContact(head, 2);
			break;
		case 5:
			cout << "Performing Sort Contact Function...(NOT Functional Yet)" << endl;
			//sortContact();
			break;
		case 6:
			cout << "Performing Display Contact Function" << endl;
			displayContact(head);
			break;
		case 7:
			cout << "Exiting the program..... Goodbye" << endl;
			exit(0);
			break;
		default:
			cout << "This is an invalid option... please enter another number." << endl;
			break;
		}
	} while (input < 7 || input > 7);
}

void addContact(struct contact **head) { //Just pushing on new nodes onto the list. Manipulating the address of head with ** and passing &head
	contact* new_node = new contact;

	string name;
	int number;
	string address;


	cout << "Please enter first name" << endl;
	cin >> name;
	new_node->firstName = name;

	cout << "Please enter last name" << endl;
	cin >> name;
	new_node->lastName = name;

	cout << "Please enter phone number" << endl;
	cin >> number;
	new_node->phoneNumber = number;

	cout << "Please enter Address" << endl;
	cin >> address;
	new_node->addressBook = address;

	new_node->next = *head;
	*head = new_node;
}

void displayContact(contact *head) {

	cout << head << endl;

	if (head == NULL) {
		cout << "This List is Empty" << endl;
		return;
	}

	while (head != NULL) {
		cout << head->lastName << "; " << head->firstName << "; " << head->phoneNumber << "; " << head->addressBook << endl;
		head = head->next;
	}
}



void editMechanism(struct contact *current) {
	int input = 0;
	string newString;
	int newNumber;
	int editSwitch;

	cout << current->lastName << ", " << current->firstName << "; " << current->phoneNumber << "; " << current->addressBook << endl;
	cout << "Do you wish edit this contact?\n 1) Yes\n 2) No" << endl;
	cin >> editSwitch;

	switch (editSwitch) {
	case 1:
		do {
			cout << "Which part of the contact do you wish to edit?\n 1) First Name\n 2)Last Name\n 3) Phone Number\n 4) Address\n 5) Exit" << endl;
			cin >> input;

			switch (input) {
			case 1:
				cout << "Enter first name..." << endl;
				cin >> newString;
				current->firstName = newString; break;
			case 2:
				cout << "Enter last name..." << endl;
				cin >> newString;
				current->lastName = newString; break;
			case 3:
				cout << "Enter phone number..." << endl;
				cin >> newNumber;
				current->phoneNumber = newNumber; break;
			case 4:
				cout << "Enter address..." << endl;
				cin >> newString;
				current->addressBook = newString; break;
			case 5:
				break;
			default:
				cout << "Invalid Option" << endl;
				break;
			}
		} while (input > 5 || input < 5);
		//editSwitch = false;
		break;

	case 2:
		break;
	}
}

void searchContact(struct contact *head, int modify) {

	int input = 0;
	string name;
	int number;
	string tempName;
	string tempSearch;

	struct contact *current = head;
	struct contact *previous = NULL;
	do {
		cout << "How would you like perform this search?\n 1) By first name\n 2) By last name\n 3) By phone number?\n 4) exit" << endl;
		cin >> input;

		switch (input) {
		case 1:
			cout << "Please enter first name into search...\n" << endl;
			cin >> name;
			tempName = lowerCase(name);

			while (current != NULL) {
				tempSearch = lowerCase(current->firstName);
				if (tempSearch == tempName) {
					switch (modify) {
					case 1:
						editMechanism(current);
						current = current->next;
						break;
					case 2:
						cout << current->lastName << ", " << current->firstName << "; " << current->phoneNumber << "; " << current->addressBook << endl;
						current = current->next;
						break;
					}
				}
				else {
					switch (modify) {
					case 1:
					case 2:
						current = current->next;
						break;
					}
				}
			}
			break;

		case 2:
			cout << "Please enter last name into search...\n" << endl;
			cin >> name;
			while (current != NULL) {
				tempSearch = lowerCase(current->lastName);
				if (tempSearch == tempName) {
					switch (modify) {
					case 1:
						editMechanism(current);
						current = current->next;
						break;
					case 2:
						cout << current->lastName << ", " << current->firstName << "; " << current->phoneNumber << "; " << current->addressBook << endl;
						current = current->next;
						break;
					}
				}
				else {
					switch (modify) {
					case 1:
					case 2:
						current = current->next;
						break;
					}
				}
			}
			break;

		case 3:
			cout << "Please enter number into search...\n" << endl;
			cin >> number;
			while (current != NULL) {
				if (current->phoneNumber == number) {
					switch (modify) {
					case 1:
						editMechanism(current);
						current = current->next;
						break;
					case 2:
						cout << current->lastName << ", " << current->firstName << "; " << current->phoneNumber << "; " << current->addressBook << endl;
						current = current->next;
						break;
					}
				}
				else {
					switch (modify) {
					case 1:
					case 2:
						current = current->next;
						break;
					}
				}
			}
			break;

		case 4: break;

		default: cout << "Invalid Input;" << endl;

		}
	} while (input < 4 || input>4);

}

string lowerCase(string input) {
	string package = input;
	for (int i = 0; i < input.length(); i++) {
		package[i] = tolower(input[i]);
	}
	return package;
}

void removeContact(contact **head) {// Here head is an address that points to the first node.
	contact *current = *head; //making a temp struct called current
	cout << current<< endl;
	contact *previous = NULL;// initializing previous
	int input = 0;
	string name;
	int number;
	string tempName, tempFirst;

	cout << "How would you like to search for the contact to be deleted:\n 1) By First name\n 2) By last name\n 3)By number"<<endl;
	cin >> input;

	switch (input) {
	case 1:
		cout << "Enter first name...." << endl;
		cin >> name;
		tempName = lowerCase(name); // for these searches, a temp copy is made with all lower case for matching purposes
		if (current == NULL) {
			cout << "The List is Empty";
		}
		if (current != NULL && current->firstName == tempName) {
			*head = current->next;//current->next can contain an address or null depending on if there's another node after current
			delete(current);
			return;
		}
		else {
			while (current != NULL) {
				tempFirst = lowerCase(current->firstName);
				if (tempFirst != tempName) {
					previous = current;
					current = current->next;
				}
				else {
					break;
				}
			}

			if (current == NULL) {
				cout << "Couldn't find a match" << endl;
				return;
			}

			previous->next = current->next;
			delete(current);
		}
		break;
	case 2:
		cout << "Enter last name...." << endl;
		cin >> name;
		tempName = lowerCase(name); // for these searches, a temp copy is made with all lower case for matching purposes
		if (current == NULL) {
			cout << "The List is Empty";
		}
		if (current != NULL && current->lastName == tempName) {
			*head = current->next;//current->next can contain an address or null depending on if there's another node after current
			delete(current);
			return;
		}
		else {
			while (current != NULL) {
				tempFirst = lowerCase(current->lastName);
				if (tempFirst != tempName) {
					previous = current;
					current = current->next;
				}
				else {
					break;
				}
			}

			if (current == NULL) {
				cout << "Couldn't find a match" << endl;
				return;
			}

			previous->next = current->next;
			delete(current);
		}
		break;

	case 3:
		cout << "Enter phone number...." << endl;
		cin >> number;
		if (current == NULL) {
			cout << "The List is Empty";
		}
		if (current != NULL && current->phoneNumber == number) {
			*head = current->next;//current->next can contain an address or null depending on if there's another node after current
			delete(current);
			return;
		}
		else {
			while (current != NULL) {
				if (current->phoneNumber != number) {
					previous = current;
					current = current->next;
				}
				else {
					break;
				}
			}

			if (current == NULL) {
				cout << "Couldn't find a match" << endl;
				return;
			}

			previous->next = current->next;
			delete(current);
		}
		break;
	}
}

