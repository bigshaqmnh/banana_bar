#include "Tutor.h"

Tutor::Tutor(char* s1, char* s2, char* s3, char* s4, int a, int b, char* s5, int c, int d) :
	Participants(s1, s2, s3, s4, a, b)
{
	tutor_fio = new char[strlen(s5) + 1];
	strcpy_s(tutor_fio, strlen(s5) + 1, s5);

	hours = c;
	cost = d;
}
//-----------------------------------------------------------------------------------------
Tutor::Tutor(const Tutor& obj) :
	Participants(obj)
{
	tutor_fio = new char[strlen(obj.tutor_fio) + 1];
	strcpy_s(tutor_fio, strlen(obj.tutor_fio) + 1, obj.tutor_fio);

	hours = obj.hours;
	cost = obj.cost;
}
//-----------------------------------------------------------------------------------------
Tutor::~Tutor()
{
	delete[]tutor_fio;
}
//-----------------------------------------------------------------------------------------
void Tutor::setTutorFio(const char* s)
{
	tutor_fio = new char[strlen(s) + 1];
	strcpy_s(tutor_fio, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
void Tutor::setHours(const int a)
{
	hours = a;
}
//-----------------------------------------------------------------------------------------
void Tutor::setCost(const int a)
{
	cost = a;
}
//-----------------------------------------------------------------------------------------
char* Tutor::getTutorFio() const
{
	return tutor_fio;
}
//-----------------------------------------------------------------------------------------
int Tutor::getHours() const
{
	return hours;
}
//-----------------------------------------------------------------------------------------
int Tutor::getCost() const
{
	return cost;
}
//-----------------------------------------------------------------------------------------
int Tutor::getId() const
{
	return id;
}
//-----------------------------------------------------------------------------------------
Tutor Tutor::fill(const char* str)
{
	Tutor obj;

	int j = obj.p_fill(str), ind;
	char temp[50];

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setTutorFio(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.hours = atoi(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j];)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.cost = atoi(temp);

	return obj;
}
//-----------------------------------------------------------------------------------------
bool Tutor::edit()
{
	char choice = Participants::edit(), temp[50];

	yellow
	switch (choice)
	{
	case '5':
	{
		cout << "Enter new tutor FIO: ";
		cin.getline(temp, 50);
		setTutorFio(temp);
		break;
	}
	case '6':
	{
		cout << "Enter new new ammount of study hours: ";
		cin >> hours;
		break;
	}
	case '7':
	{
		cout << "Enter new cost: ";
		cin >> cost;
		break;
	}
	case '0': return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------
void Tutor::hat()
{
	Participants::hat(id);
	green cout << setw(21) << left << "|Tutor FIO" << setw(16) << left << "|Studied hours"
		<< setw(9) << left << "|Cost, $" << "|" << endl;

	cout << "|----------------------------------------------------------------------------"
		<< "------------------------------------|" << endl;
}
//-----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, Tutor& obj)
{
	out << dynamic_cast<Participants&> (obj);

	yellow out << setw(20) << left << obj.tutor_fio;
	green out << "|";
	yellow out << setw(15) << left << obj.hours;
	green out << "|";
	yellow out << setw(8) << left << obj.cost;
	green out << "|" << endl;

	out << "|----------------------------------------------------------------------------"
		<< "------------------------------------|";

	return out;
}
//-----------------------------------------------------------------------------------------
istream& operator >> (istream& in, Tutor& obj)
{
	char temp[30];

	in >> dynamic_cast<Participants&> (obj);

	yellow cout << "\nEnter tutor FIO: ";
	cin.ignore();
	in.getline(temp, 30);
	obj.setTutorFio(temp);
	
	cout << "\nEnter the ammount of study hours: ";
	cin >> obj.hours;

	cout << "\nEnter the cost for one hour of studies: ";
	cin >> obj.cost;

	return in;
}
//-----------------------------------------------------------------------------------------
void Tutor::save(Tutor& obj, ofstream& file) const
{
	file << obj.getFio() << "/" << obj.getInstrument() << "/" << obj.getCountry() << "/" << obj.getAward()
		<< "/" << obj.tutor_fio << "/" << obj.hours << "/" << obj.cost << endl;
}
//-----------------------------------------------------------------------------------------
Tutor& Tutor::operator=(Tutor& obj)
{
	if (this != &obj)
	{
		setFio(obj.getFio());
		setInstrument(obj.getInstrument());
		setCountry(obj.getCountry());
		setAward(obj.getAward());
		setTutorFio(obj.tutor_fio);
		hours = obj.hours;
		cost = obj.cost;
	}
	return *this;
}
//-----------------------------------------------------------------------------------------
bool Tutor::operator==(Tutor& obj)
{
	bool compare = Participants::operator==(obj);

	if (compare) return compare;
	else if (strstr((*this).tutor_fio, obj.tutor_fio) && strlen(obj.tutor_fio)) compare = true;
	else if ((*this).hours == obj.hours) compare = true;
	else if ((*this).cost == obj.cost) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool Tutor::operator>(const Tutor& obj)
{
	bool compare = Participants::operator>(obj);

	if (compare) return compare;
	else
	{
		if (getSortOpt() == 6 && strcmp((*this).tutor_fio, obj.tutor_fio) > 0) compare = true;
		if (getSortOpt() == 7 && (*this).hours > obj.hours) compare = true;
	}

	return compare;
}
//-----------------------------------------------------------------------------------------
bool Tutor::search(Tutor& obj)
{
	char choice, temp[50];
	bool flag_1, flag_2;

	do
	{
		flag_1 = false;

		choice = obj.p_search(id);

		yellow
		switch (choice)
		{
		case '5':
		{
			cout << "Enter the FIO of the tutor: ";
			cin.getline(temp, 50);
			setTutorFio(temp);
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