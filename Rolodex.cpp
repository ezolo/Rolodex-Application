#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
class RolodexEntry
{
	string name;
	string address;
	long zip;
	string phone;
	string email;
public:
	RolodexEntry(string name, string address, long zip, string phone, string email)
	{
		//setting up all the key components for user to enter
		set_name(name);
		set_address(address);
		set_zip(zip);
		set_phone(phone);
		set_email(email);
	}
	RolodexEntry()
	{
		set_name("");
		set_address("");
		set_zip(0);
		set_phone("");
		set_email("");
	}
	string get_name()
	{
		return name;
	}
	void set_name(string new_name)
	{
		name = new_name;
	}
	string get_address()
	{
		return address;
	}
	void set_address(string new_addr)
	{
		address = new_addr;
	}
	long get_zip()
	{
		return zip;
	}
	void set_zip(long new_zip)
	{
		zip = new_zip;
	}
	string get_phone()
	{
		return phone;
	}
	void set_phone(string new_phone)
	{
		phone = new_phone;
	}
	string get_email()
	{
		return email;
	}
	void set_email(string new_email)
	{
		email = new_email;
	}
	//layout of menu for add entry
	void menu1();
	void disply()
	{
		cout << "\nName: " << name;
		cout << "\nAddress: " << address;
		cout << "\nZip: " << zip;
		cout << "\nPhone: " << phone;
		cout << "\nEmail: " << email << endl << endl;
	}
};
//the following shows how to add an entry
void add(vector <RolodexEntry>& vec, RolodexEntry entry)
{
	vec.push_back(entry);
}
void edit(vector <RolodexEntry>& vec, short entry_index, RolodexEntry entry)
{
	vec[entry_index - 1] = entry;
}
void del(vector <RolodexEntry>& vec, short entry_index)
{
	//The following shows how to delete an entry
	vec.erase(vec.begin() + entry_index - 1);
}
RolodexEntry search_name(vector <RolodexEntry>& vec, string name)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].get_name().find(name) != -1)
		{
			return vec[i];
		}
	}
	return RolodexEntry();
}
//the following shows how to search for an entry by address
RolodexEntry search_address(vector <RolodexEntry>& vec, string address)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].get_address().find(address) != -1)
		{
			return vec[i];
		}
	}
	return RolodexEntry();
}
//the following shows how to search for an entry by phone number
RolodexEntry search_phone(vector <RolodexEntry>& vec, string phone)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].get_phone().find(phone) != -1)
		{
			return vec[i];
		}
	}
	return RolodexEntry();
}
//the following shows how to search for an entry by email
RolodexEntry search_email(vector <RolodexEntry>& vec, string email)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].get_email().find(email) != -1)
		{
			return vec[i];
		}
	}
	return RolodexEntry();
}
//the following will display the current entries
void disply(vector <RolodexEntry>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].disply();
	}
}
RolodexEntry read_entry()
{
	string name, address, phone, email;
	long zip;
	cin.ignore(1, '\n');
	cout << "\nName: ";
	getline(cin, name);
	cout << "\nAddress: ";
	getline(cin, address);
	cout << "\nZip: ";
	cin >> zip;
	cout << "\nPhone: ";
	cin.ignore(1, '\n');
	getline(cin, phone);
	cout << "\nEmail: ";
	getline(cin, email);
	return RolodexEntry(name, address, zip, phone, email);
}
//the search function, all put together (search by any component)
void search(vector <RolodexEntry>& vec)
{
	char choice;
	string temp;
	RolodexEntry entry;
	do {
		cout << "\n1) search by Name\n";
		cout << "\n2) search by Address\n";
		cout << "\n3) search by phone number";
		cout << "\n4) search by Email address";
		cout << "\n5) Return to Main Menu";
		cin >> choice;
		if (choice == '1' || toupper(choice) == 'N')
		{
			cout << "Enter a name to search: ";
			cin >> temp;
			entry = search_name(vec, temp);
			entry.disply();
		}
		else if (choice == '2' || toupper(choice) == 'A')
		{
			cout << "Enter the Address to search: ";
			cin >> temp;
			entry = search_address(vec, temp);
			entry.disply();
		}
		else if (choice == '3' || toupper(choice) == 'P')
		{
			cout << "Enter the phone to search: ";
			cin >> temp;
			entry = search_phone(vec, temp);
			entry.disply();
		}
		else if (choice == '4' || toupper(choice) == 'E')
		{
			cout << "Enter the Email to search: ";
			cin >> temp;
			entry = search_email(vec, temp);
			entry.disply();
		}
		else if (choice == '5' || toupper(choice) == 'Q')
		{
		}
		else
		{
			cout << "Invalid Choice\n";
		}
	} while ((toupper(choice) != '5') && (toupper(choice != 'R')));
}
int main()
{
	RolodexEntry entry;
	vector <RolodexEntry> phone_book;
	char choice;
	short num;
	do
	{
		//A general menu of how the rolodex will look like (each functionality listed in order)
		cout << "**********************\n*1) Add entry *\n**********************";
		cout << "\n*2) Edit entry *\n**********************";

		cout << "\n*3) Delete entry *\n**********************";
		cout << "\n*4) Search for entry *\n**********************";
		cout << "\n*5) Print all entries*\n**********************";
		cout << "\n*6) Quit *\n**********************\n";
		cin >> choice;
		if (choice == '1' || toupper(choice) == 'A')
		{
			cout << "Enter the entry that need to be added";
			entry = read_entry();
			add(phone_book, entry);
		}
		else if (choice == '2' || toupper(choice) == 'E')
		{
			cout << "Which number entry do you want to modify : ";
			cin >> num;
			cout << "\nEnter the updated information of the entry";
			entry = read_entry();
			edit(phone_book, num, entry);
		}
		else if (choice == '3' || toupper(choice) == 'D')
		{
			cout << "\nEnter the index of Entry to be deleted: ";
			cin >> num;
			del(phone_book, num);
		}
		else if (choice == '4' || toupper(choice) == 'S')
		{
			search(phone_book);
		}
		else if (choice == '5' || toupper(choice) == 'P')
		{
			disply(phone_book);
		}
		else if (choice == '6' || toupper(choice) == 'Q')
		{
		}
		else
		{
			cout << "Invalid Choice\n";
		}
	} while ((choice != '6') && (toupper(choice) != 'Q'));
	return 0;
}