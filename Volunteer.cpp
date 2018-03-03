#include "Volunteer.h"

Volunteer::Volunteer(char* s1, char* s2, char* s3, char* s4, char* s5) :
	Organization(s1, s2)
{
	fio = new char[strlen(s3) + 1];
	strcpy_s(fio, strlen(s3) + 1, s3);

	tel_number = new char[strlen(s4) + 1];
	strcpy_s(tel_number, strlen(s4) + 1, s4);

	occupation = new char[strlen(s5) + 1];
	strcpy_s(occupation, strlen(s5) + 1, s5);
}
//-----------------------------------------------------------------------------------------
Volunteer::Volunteer(const Volunteer& obj) :
	Organization(obj)
{
	fio = new char[strlen(obj.fio) + 1];
	strcpy_s(fio, strlen(obj.fio) + 1, obj.fio);

	tel_number = new char[strlen(obj.tel_number) + 1];
	strcpy_s(tel_number, strlen(obj.tel_number) + 1, obj.tel_number);

	occupation = new char[strlen(obj.occupation) + 1];
	strcpy_s(occupation, strlen(obj.occupation) + 1, obj.occupation);
}
//-----------------------------------------------------------------------------------------
Volunteer::~Volunteer()
{
	delete[]fio;
	delete[]tel_number;
	delete[]occupation;
}
//-----------------------------------------------------------------------------------------
void Volunteer::setFio(const char* s)
{
	fio = new char[strlen(s) + 1];
	strcpy_s(fio, strlen(s) + 1, s);
}//-----------------------------------------------------------------------------------------
void Volunteer::setTelNumber(const char* s)
{
	tel_number = new char[strlen(s) + 1];
	strcpy_s(tel_number, strlen(s) + 1, s);
}//-----------------------------------------------------------------------------------------
void Volunteer::setOccupation(const char* s)
{
	occupation = new char[strlen(s) + 1];
	strcpy_s(occupation, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
char* Volunteer::getFio() const
{
	return fio;
}
//-----------------------------------------------------------------------------------------
char* Volunteer::getTelNumber() const
{
	return tel_number;
}
//-----------------------------------------------------------------------------------------
char* Volunteer::getOccupation() const
{
	return occupation;
}
//-----------------------------------------------------------------------------------------
int Volunteer::getId() const
{
	return id;
}
//-----------------------------------------------------------------------------------------
Volunteer Volunteer::fill(const char* str)
{
	Volunteer obj;

	int j = obj.o_fill(str), ind;
	char temp[50];

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setFio(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setTelNumber(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j];)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setOccupation(temp);

	return obj;
}
//-----------------------------------------------------------------------------------------
void Volunteer::save(Volunteer& obj, ofstream& file) const
{
	file << obj.getCountry() << "/" << obj.fio << "/" << obj.tel_number << "/" << obj.occupation << endl;
}
//-----------------------------------------------------------------------------------------
bool Volunteer::edit()
{
	char choice, temp[50];
	bool flag;

	do
	{
		flag = false;

		system("cls");
		purple cout << "What field do you want to edit?" << endl;
		blue cout << "1.Change country of the volunteer" << endl;
		cout << "2.Change FIO of the volunteer" << endl;
		cout << "3.Change telephone number of the volunteer" << endl;
		cout << "4.Change occupation of the volunteer" << endl;
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
			cout << "Enter the new FIO: ";
			cin.getline(temp, 50);
			setFio(temp);
			break;
		}
		case '3':
		{
			cout << "Enter the new telephone number: ";
			cin.getline(temp, 50);
			setTelNumber(temp);
			break;
		}
		case '4':
		{
			cout << "Enter the new occupation: ";
			cin.getline(temp, 50);
			setOccupation(temp);
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
void Volunteer::hat()
{
	Organization::hat(id);
	green cout << setw(21) << left << "|FIO" << setw(18) << left << "|Tel.number" 
		<< setw(21) << left << "|Occupation" << "|" << endl;

	cout << "|-----------------------------------------------------------------------------|" << endl;
}
//-----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, Volunteer& obj)
{
	out << dynamic_cast<Organization&> (obj);

	yellow out << setw(20) << left << obj.fio;
	green out << "|";
	yellow out << setw(17) << left << obj.tel_number;
	green out << "|";
	yellow out	<< setw(20) << left << obj.occupation;
	green out << "|" << endl;

	out << "|-----------------------------------------------------------------------------|";

	return out;
}
//-----------------------------------------------------------------------------------------
istream& operator >> (istream& in, Volunteer& obj)
{
	in >> dynamic_cast<Organization&> (obj);

	char temp[50];

	yellow cout << "\nEnter the FIO of the volunteer: ";
	in.getline(temp, 50);
	obj.setFio(temp);

	cout << "\nEnter the telephone number of the volunteer: ";
	in.getline(temp, 50);
	obj.setTelNumber(temp);

	cout << "\nEnter the occupation of the volunteer: ";
	in.getline(temp, 50);
	obj.setOccupation(temp);

	return in;
}
//-----------------------------------------------------------------------------------------
Volunteer& Volunteer::operator=(Volunteer& obj)
{
	if (this != &obj)
	{
		setCountry(obj.getCountry());
		setFio(obj.fio);
		setTelNumber(obj.tel_number);
		setOccupation(obj.occupation);
	}
	return *this;
}
//-----------------------------------------------------------------------------------------
bool Volunteer::operator==(Volunteer& obj)
{
	bool compare = Organization::operator==(obj);

	if (compare) return true;
	else if (strstr((*this).fio, obj.fio) && strlen(obj.fio)) compare = true;
	else if (strstr((*this).tel_number, obj.tel_number) && strlen(obj.tel_number)) compare = true;
	else if (!strcmp((*this).occupation, obj.occupation)) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool Volunteer::operator>(const Volunteer& obj)
{
	bool compare = Organization::operator>(obj);

	if (compare) return compare;
	else if (getSortOpt() == 4 && strcmp((*this).fio, obj.fio) > 0) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
char* Volunteer::operator~() const
{
	return fio;
}
//-----------------------------------------------------------------------------------------
bool Volunteer::search(Volunteer& obj)
{
	char choice, temp[50];
	bool flag_1, flag_2;

	do
	{
		flag_1 = false;
		
		system("cls");
		blue cout << "1.Search by country" << endl;
		cout << "2.Search by FIO of the volunteer" << endl;
		cout << "3.Search by the telephone number of the volunteer" << endl;
		cout << "4.Search by the occupation of the volunteer" << endl;
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
			cout << "Enter the FIO: ";
			cin.ignore();
			cin.getline(temp, 50);
			setFio(temp);
			break;
		}
		case '3':
		{
			cout << "Enter the telephone number: ";
			cin.ignore();
			cin.getline(temp, 50);
			setTelNumber(temp);
			break;
		}
		case '4':
		{
			cout << "Enter the occupation: ";
			cin.ignore();
			cin.getline(temp, 50);
			setOccupation(temp);
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