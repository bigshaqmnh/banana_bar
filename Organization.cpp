#include "Organization.h"

int Organization::sort_opt;

Organization::Organization(char* s1, char* s2) :
	Contest(s1)
{
	country = new char[strlen(s2) + 1];
	strcpy_s(country, strlen(s2) + 1, s2);
}
//------------------------------------------------------------------------------------------------
Organization::Organization(const Organization& obj)
{
	country = new char[strlen(obj.country) + 1];
	strcpy_s(country, strlen(obj.country) + 1, obj.country);
}
//------------------------------------------------------------------------------------------------
Organization::~Organization()
{
	delete[]country;
}
//------------------------------------------------------------------------------------------------
void Organization::setCountry(const char* s)
{
	country = new char[strlen(s) + 1];
	strcpy_s(country, strlen(s) + 1, s);
}
//------------------------------------------------------------------------------------------------
void Organization::setSortOpt(const int a)
{
	sort_opt = a;
}
//------------------------------------------------------------------------------------------------
char* Organization::getCountry() const
{
	return country;
}
//------------------------------------------------------------------------------------------------
int Organization::getSortOpt() const
{
	return sort_opt;
}
//------------------------------------------------------------------------------------------------
int Organization::o_fill(const char* str)
{
	int j, ind;
	char temp[50];

	for (ind = 0, j = 0; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	setCountry(temp);

	return j;
}
//------------------------------------------------------------------------------------------------
bool Organization::sort(const int option)
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		system("cls");
		blue cout << "1.Sort by country" << endl;
		if (option == 1)
		{
			cout << "2.Sort sponsors by legal name" << endl;
			cout << "3.Sort sponsors by size of contribution" << endl;
		}
		if (option == 2) cout << "2.Sort managers by FIO" << endl;
		if (option == 3) cout << "2.Sort volunteers by FIO" << endl;
		cout << "0.Back to menu" << endl;

		cin >> choice;

		yellow
		if (option == 1)
		{
			if (choice == '2')
			{
				cout << "Sorted by legal name: " << endl;
				sort_opt = 2;
			}
			if (choice == '3')
			{
				cout << "Sorted by size of contribution: " << endl;
				sort_opt = 3;
			}
			return true;
		}
		if ((option == 2 || option == 3) && choice == '2')
		{
			cout << "Sorted by FIO: " << endl;
			sort_opt = 4;
			return true;
		}

		switch (choice)
		{
		case '1':
		{
			cout << "Sorted by country: " << endl;
			sort_opt = 1;
			break;
		}
		case '0': return false;
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			flag = true; Sleep(1500);
		}
		}
	} while (flag);

	return true;
}
//------------------------------------------------------------------------------------------------
void Organization::hat(const int option)
{
	green cout << "|-----------------";
	if (option == 1) cout << "--------------------------------|" << endl;
	if (option == 2) cout << "-------------------------------------|" << endl;
	if (option == 3) cout << "------------------------------------------------------------|" << endl;

	cout << setw(18) << left << "|  Country";
}
//------------------------------------------------------------------------------------------------
bool Organization::operator==(const Organization& obj) const
{
	bool compare = false;

	if (!strcmp((*this).country, obj.country)) compare = true;

	return compare;
}
//------------------------------------------------------------------------------------------------
bool Organization::operator>(const Organization& obj) const
{
	bool compare = false;

	if (sort_opt == 1 && strcmp((*this).country, obj.country) > 0) compare = true;

	return compare;
}
//------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Organization& obj)
{
	yellow out << setw(15) << left << obj.country;
	green out << "|";

	return out;
}
//----------------------------------------------------------------------------------------------
istream& operator >> (istream& in, Organization& obj)
{
	char temp[50];

	yellow cout << "\nEnter the country of the person/organization: ";
	cin.ignore();
	in.getline(temp, 50);
	obj.setCountry(temp);

	return in;
}