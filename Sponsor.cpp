#include "Sponsor.h"

Sponsor::Sponsor(char* s1, char* s2, char* s3, int a) :
	Organization(s1, s2)
{
	legal_name = new char[strlen(s3) + 1];
	strcpy_s(legal_name, strlen(s3) + 1, s3);

	contribution = a;
}
//-----------------------------------------------------------------------------------------
Sponsor::Sponsor(const Sponsor& obj):
	Organization(obj)
{
	legal_name = new char[strlen(obj.legal_name) + 1];
	strcpy_s(legal_name, strlen(obj.legal_name) + 1, obj.legal_name);

	contribution = obj.contribution;
}
//-----------------------------------------------------------------------------------------
Sponsor::~Sponsor()
{
	delete[]legal_name;
}
//-----------------------------------------------------------------------------------------
void Sponsor::setLegalName(const char* s)
{
	legal_name = new char[strlen(s) + 1];
	strcpy_s(legal_name, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
void Sponsor::setBudget(const int a)
{
	contribution = a;
}
//-----------------------------------------------------------------------------------------
char* Sponsor::getLegalName() const
{
	return legal_name;
}
//-----------------------------------------------------------------------------------------
int Sponsor::getBudget() const
{
	return contribution;
}
//-----------------------------------------------------------------------------------------
int Sponsor::getId() const
{
	return id;
}
//-----------------------------------------------------------------------------------------
Sponsor Sponsor::fill(const char* str)
{
	Sponsor obj;

	int j = obj.o_fill(str), ind;
	char temp[50];

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setLegalName(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j];)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.contribution = atoi(temp);

	return obj;
}
//-----------------------------------------------------------------------------------------
void Sponsor::save(Sponsor& obj, ofstream& file) const
{
	file << obj.getCountry() << "/"	<< obj.legal_name << "/" << obj.contribution << endl;
}
//-----------------------------------------------------------------------------------------
bool Sponsor::edit()
{
	char choice, temp[50];
	bool flag;

	do
	{
		flag = false;

		system("cls");
		purple cout << "What field do you want to edit?" << endl;
		blue cout << "1.Change country of the sponsor" << endl;
		cout << "2.Change legal name of the sponsor" << endl;
		cout << "3.Change the ammount of money the sponsor gave" << endl;
		cout << "0.Back to menu" << endl;

		cin >> choice;
		cin.ignore();

		yellow
		switch (choice)
		{
		case '1':
		{
			cout << "Enter the new country: ";
			cin.getline(temp, 50);
			setCountry(temp);
			break;
		}
		case '2':
		{
			cout << "Enter the new legal name: ";
			cin.getline(temp, 50);
			setLegalName(temp);
			break;
		}
		case '3':
		{
			cout << "Enter the new sum of money: ";
			cin >> contribution;
			break;
		}
		case '0': return false;
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			Sleep(1500);
			flag = true;
		}
		}
	} while (flag);

	return true;
}
//-----------------------------------------------------------------------------------------
void Sponsor::hat()
{
	Organization::hat(id);
	green cout << setw(21) << left << "|Legal name" << setw(11) << left << "|Budget, $" << "|" << endl;

	cout << "|-------------------------------------------------|" << endl;
}
//-----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, Sponsor& obj)
{
	out << dynamic_cast<Organization&> (obj);

	yellow out << setw(20) << left << obj.legal_name;
	green out << "|";
	yellow out	<< setw(10) << left << obj.contribution;
	green out << "|" << endl;

	out << "|-------------------------------------------------|";

	return out;
}
//-----------------------------------------------------------------------------------------
istream& operator >> (istream& in, Sponsor& obj)
{
	in >> dynamic_cast<Organization&> (obj);

	char temp[50];

	yellow cout << "\nEnter the legal name of the sponsor: ";
	in.getline(temp, 50);
	obj.setLegalName(temp);

	cout << "\nEnter the sum of money the sponsor gave: ";
	in >> obj.contribution;

	return in;
}
//-----------------------------------------------------------------------------------------
Sponsor& Sponsor::operator=(Sponsor& obj)
{
	if (this != &obj)
	{
		setCountry(obj.getCountry());
		setLegalName(obj.legal_name);
		contribution = obj.contribution;
	}
	return *this;
}
//-----------------------------------------------------------------------------------------
bool Sponsor::operator==(Sponsor& obj)
{
	bool compare = Organization::operator==(obj);

	if (compare) return true;
	else if (strstr((*this).legal_name, obj.legal_name) && strlen(obj.legal_name)) compare = true;
	else if ((*this).contribution == obj.contribution) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool Sponsor::operator>(const Sponsor& obj)
{
	bool compare = Organization::operator>(obj);

	if (compare) return compare;
	else
	{
		if (getSortOpt() == 2 && strcmp((*this).legal_name, obj.legal_name) > 0) compare = true;
		if (getSortOpt() == 3 && (*this).contribution > obj.contribution) compare = true;
	}

	return compare;
}
//-----------------------------------------------------------------------------------------
char* Sponsor::operator~() const
{
	return legal_name;
}
//-----------------------------------------------------------------------------------------
bool Sponsor::search(Sponsor& obj)
{
	char choice, temp[50];
	bool flag_1, flag_2;

	do
	{
		flag_1 = false;

		system("cls");
		blue cout << "1.Search by country" << endl;
		cout << "2.Search by the legal name" << endl;
		cout << "3.Search by the size of the donation" << endl;
		cout << "0.Back to menu" << endl;

		cin >> choice;

		yellow
		switch (choice)
		{
		case '1':
		{
			cout << "Enter the country: ";
			cin.ignore();
			cin.getline(temp, 50);
			obj.setCountry(temp);
			break;
		}
		case '2':
		{
			cout << "Enter the legal name: ";
			cin.ignore();
			cin.getline(temp, 50);
			setLegalName(temp);
			break;
		}
		case '3':
		{
			cout << "Enter the ammount of money: ";
			cin >> contribution;
			break;
		}
		case '0': return false;
		}
		do
		{
			flag_2 = false;

			purple cout << "\nDo you want to add another field for search? (1 - Yes, 2 - No)" << endl;
			cin >> choice;

			if (choice == '1') flag_1 = true;
			else if (choice != '2')
			{
				red cout << "Wrong input! Try again!";
				flag_2 = true;
			}
		} while (flag_2);
	} while (flag_1);

	return true;
}