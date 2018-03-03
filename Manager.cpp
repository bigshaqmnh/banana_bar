#include "Manager.h"

Manager::Manager(char* s1, char* s2, char* s3, char* s4) :
	Organization(s1, s2)
{
	fio = new char[strlen(s3) + 1];
	strcpy_s(fio, strlen(s3) + 1, s3);

	job = new char[strlen(s4) + 1];
	strcpy_s(job, strlen(s4) + 1, s4);
}
//-----------------------------------------------------------------------------------------
Manager::Manager(const Manager& obj):
	Organization(obj)
{
	fio = new char[strlen(obj.fio) + 1];
	strcpy_s(fio, strlen(obj.fio) + 1, obj.fio);

	job = new char[strlen(obj.job) + 1];
	strcpy_s(job, strlen(obj.job) + 1, obj.job);
}
//-----------------------------------------------------------------------------------------
Manager::~Manager()
{
	delete[]fio;
	delete[]job;
}
//-----------------------------------------------------------------------------------------
void Manager::setFio(const char* s)
{
	fio = new char[strlen(s) + 1];
	strcpy_s(fio, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
void Manager::setJob(const char* s)
{
	job = new char[strlen(s) + 1];
	strcpy_s(job, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
char* Manager::getFio() const
{
	return fio;
}
//-----------------------------------------------------------------------------------------
char* Manager::getJob() const
{
	return job;
}
//-----------------------------------------------------------------------------------------
int Manager::getId() const
{
	return id;
}
//-----------------------------------------------------------------------------------------
Manager Manager::fill(const char* str)
{
	Manager obj;

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

	for (ind = 0, j++; str[j];)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setJob(temp);
	
	return obj;
}
//-----------------------------------------------------------------------------------------
void Manager::save(Manager& obj, ofstream& file) const
{
	file << obj.getCountry() << "/" << obj.fio << "/" << obj.job << endl;
}
//-----------------------------------------------------------------------------------------
bool Manager::edit()
{
	char choice, temp[50];
	bool flag;

	do
	{
		flag = false;

		system("cls");
		purple cout << "What field do you want to edit?" << endl;
		blue cout << "1.Change country of the manager" << endl;
		cout << "2.Change FIO of the manager" << endl;
		cout << "3.Change job of the manager" << endl;
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
			cout << "Enter the new job: ";
			cin.getline(temp, 50);
			setJob(temp);
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
void Manager::hat()
{
	Organization::hat(id);
	green cout << setw(21) << left << "|FIO" << setw(16) << left << "|Job" << "|" << endl;

	cout << "|------------------------------------------------------|" << endl;
}
//-----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, Manager& obj)
{
	out << dynamic_cast<Organization&> (obj);

	yellow out << setw(20) << left << obj.fio;
	green out << "|";
	yellow out	<< setw(15) << left << obj.job;
	green out << "|" << endl;

	out << "|------------------------------------------------------|";

	return out;
}
//-----------------------------------------------------------------------------------------
istream& operator>>(istream& in, Manager& obj)
{
	in >> dynamic_cast<Organization&> (obj);

	char temp[50];

	yellow cout << "\nEnter the FIO of the manager: ";
	in.getline(temp, 50);
	obj.setFio(temp);

	cout << "\nEnter the job of the manager: ";
	in.getline(temp, 50);
	obj.setJob(temp);

	return in;
}
//-----------------------------------------------------------------------------------------
Manager& Manager::operator=(Manager& obj)
{
	if (this != &obj)
	{
		setCountry(obj.getCountry());
		setFio(obj.fio);
		setJob(obj.job);
	}
	return *this;
}
//-----------------------------------------------------------------------------------------
bool Manager::operator==(Manager& obj)
{
	bool compare = Organization::operator==(obj);

	if (compare) return true;
	else if (strstr((*this).fio, obj.fio) && strlen(obj.fio)) compare = true;
	else if (!strcmp((*this).job, obj.job)) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool Manager::operator>(const Manager& obj)
{
	bool compare = Organization::operator>(obj);

	if (compare) return compare;
	else if (getSortOpt() == 4 && strcmp((*this).fio, obj.fio) > 0) compare = true;
	
	return compare;
}
//-----------------------------------------------------------------------------------------
char* Manager::operator~() const
{
	return fio;
}
//-----------------------------------------------------------------------------------------
bool Manager::search(Manager& obj)
{
	char choice, temp[50];
	bool flag_1, flag_2;

	do
	{
		flag_1 = false;

		system("cls");
		blue cout << "1.Search by country" << endl;
		cout << "2.Search by FIO of the manager" << endl;
		cout << "3.Search by the job of the manager" << endl;
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
			cout << "Enter the job: ";
			cin.ignore();
			cin.getline(temp, 50);
			setJob(temp);
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