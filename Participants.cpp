#include "Participants.h"

int Participants::sort_opt;

Participants::Participants(char* s1, char* s2, char* s3, char* s4, int a, int b) :
	Contest(s1)
{
	fio = new char[strlen(s2) + 1];
	strcpy_s(fio, strlen(s2) + 1, s2);

	instrument = new char[strlen(s3) + 1];
	strcpy_s(instrument, strlen(s3) + 1, s3);

	country = new char[strlen(s4) + 1];
	strcpy_s(country, strlen(s4) + 1, s4);

	award = a;
	sort_opt = b;
}
//------------------------------------------------------------------------------------------------
Participants::Participants(const Participants& obj)
{
	fio = new char[strlen(obj.fio) + 1];
	strcpy_s(fio, strlen(obj.fio) + 1, obj.fio);

	instrument = new char[strlen(obj.instrument) + 1];
	strcpy_s(instrument, strlen(obj.instrument) + 1, obj.instrument);

	country = new char[strlen(obj.country) + 1];
	strcpy_s(country, strlen(obj.country) + 1, obj.country);

	award = obj.award;
}
//------------------------------------------------------------------------------------------------
Participants::~Participants()
{
	delete[]fio;
	delete[]instrument;
	delete[]country;
}
//------------------------------------------------------------------------------------------------
void Participants::setFio(const char* s)
{
	fio = new char[strlen(s) + 1];
	strcpy_s(fio, strlen(s) + 1, s);
}
//------------------------------------------------------------------------------------------------
void Participants::setInstrument(const char* s)
{
	instrument = new char[strlen(s) + 1];
	strcpy_s(instrument, strlen(s) + 1, s);
}
//------------------------------------------------------------------------------------------------
void Participants::setCountry(const char* s)
{
	country = new char[strlen(s) + 1];
	strcpy_s(country, strlen(s) + 1, s);
}
//------------------------------------------------------------------------------------------------
void Participants::setAward(const int a)
{
	award = a;
}
//------------------------------------------------------------------------------------------------
void Participants::setSortOpt(const int a)
{
	sort_opt = a;
}
//------------------------------------------------------------------------------------------------
char* Participants::getFio() const
{
	return fio;
}
//------------------------------------------------------------------------------------------------
char* Participants::getInstrument() const
{
	return instrument;
}
//------------------------------------------------------------------------------------------------
char* Participants::getCountry() const
{
	return country;
}
//------------------------------------------------------------------------------------------------
int Participants::getAward() const
{
	return award;
}
//------------------------------------------------------------------------------------------------
int Participants::getSortOpt() const
{
	return sort_opt;
}
//------------------------------------------------------------------------------------------------
int Participants::p_fill(const char* str) //заполенние объекта из строки
{
	int j, ind;
	char temp[50];

	for (ind = 0, j = 0; str[j] != '/';) //поля в строке разделены символом /
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0'; //завершаем строку
	setFio(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	setInstrument(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	setCountry(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	award = atoi(temp); //имеет тип int
	
	return j;
}
//------------------------------------------------------------------------------------------------
char Participants::edit()
{
	char choice, temp[50];
	int option = getId(); //получаем идентификатор вызывающего класса
	bool flag;

	do
	{
		flag = false;

		system("cls");
		purple cout << "What field do you want to edit?" << endl;
		blue cout << "1.Change FIO of the participant" << endl;
		cout << "2.Musical instrument of the participant" << endl;
		cout << "3.Change country of the participant" << endl;
		cout << "4.Change the awarded place of the participant" << endl;
		if (option == 1) cout << "5.Change how many years did the participant study" << endl;
		if (option == 2)
		{
			cout << "5.Change the school name" << endl;
			cout << "6.Change the adress of the musical school" << endl;
			cout << "7.Change the speciality of the participant" << endl;
			cout << "8.Change the mark in the diploma" << endl;
		}
		if (option == 3)
		{
			cout << "5.Change FIO of the tutor" << endl;
			cout << "6.Change the ammount of study hours" << endl;
			cout << "7.Change the cost for one hour" << endl;
		}
		cout << "0.Back to menu" << endl;

		cin >> choice;
		cin.ignore(); //чтоб не перескакивало getline
		//возвращаем выбор, если изменяемое поле не относится к данному классу
		if (option == 1 && choice == '5') return choice;
		if (option == 2 && (choice - 48) >= 5 && (choice - 48) <= 8) return choice;
		if (option == 3 && (choice - 48) >= 5 && (choice - 48) <= 7) return choice;

		yellow
		switch (choice)
		{
		case '1':
		{
			cout << "Enter new FIO: ";
			cin.getline(temp, 50);
			setFio(temp);
			break;
		}
		case '2':
		{
			cout << "Enter new musical instrument: ";
			cin.getline(temp, 50);
			setInstrument(temp);
			break;
		}
		case '3':
		{
			cout << "Enter new country: ";
			cin.getline(temp, 50);
			setCountry(temp);
			break;
		}
		case '4':
		{
			cout << "Enter new awarded place: ";
			cin >> award;
			break;
		}
		case '0': return choice;
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			Sleep(1500);
			flag = true;
		}
		}
	} while (flag);

	return 0;
}
//------------------------------------------------------------------------------------------------
char Participants::p_search(const int option)
{
	char choice, temp[50];
	bool flag;

	do
	{
		flag = false;

		system("cls");
		blue cout << "1.Search by FIO" << endl;
		cout << "2.Search by instrument" << endl;
		cout << "3.Search by country" << endl;
		cout << "4.Search by award" << endl;
		if (option == 1) cout << "5.Search by experience" << endl;
		if (option == 2)
		{
			cout << "5.Search by the school name" << endl;
			cout << "6.Search by the adress of the musical school" << endl;
			cout << "7.Search by the speciality of the participant" << endl;
			cout << "8.Search by the mark in the diploma" << endl;
		}
		if (option == 3) cout << "5.Search by FIO of the tutor" << endl;
		cout << "0.Back to menu" << endl;

		cin >> choice;
		cin.ignore(); //чтоб не перескакивало getline
		//возвращаем выбор, если изменяемое поле не относится к данному классу
		if ((option == 1 || option == 3) && choice == '5') return choice;
		if (option == 2 && (choice - 48) >= 5 && (choice - 48) <= 8) return choice;
		
		yellow
		switch (choice)
		{
		case '1':
		{
			cout << "Enter the FIO: ";
			cin.getline(temp, 50);
			setFio(temp);
			break;
		}
		case '2':
		{
			cout << "Enter the name of the instrument: ";
			cin.getline(temp, 50);
			setInstrument(temp);
			break;
		}
		case '3':
		{
			cout << "Enter the name of the country: ";
			cin.getline(temp, 50);
			setCountry(temp);
			break;
		}
		case '4':
		{
			cout << "Enter the participant's awarded place: ";
			cin >> award;
			break;
		}
		case '0': return choice;
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			Sleep(1500);
			flag = true;
		}
		}
	} while (flag);

	return 0;
}
//------------------------------------------------------------------------------------------------
bool Participants::sort(const int option)
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		system("cls");
		blue cout << "1.Sort by FIO" << endl;
		cout << "2.Sort by country" << endl;
		cout << "3.Sort by award" << endl;
		if (option == 1) cout << "4.Sort by experience" << endl;
		if (option == 2) cout << "4.Sort by the mark in the diploma" << endl;
		if (option == 3)
		{
			cout << "4.Sort by FIO of the tutor" << endl;
			cout << "5.Sort by number of study hours" << endl;
		}
		cout << "0.Back to menu" << endl;

		cin >> choice;

		yellow
		if (option == 1 && choice == '4')
		{
			cout << "Sorted by experience: " << endl;
			sort_opt = 4; //задаем опцию для перегрузки оператора >
			return true;
		}
		if (option == 2 && choice == '4')
		{
			cout << "Sorted by the mark in the diploma: " << endl;
			sort_opt = 5;
			return true;
		}
		if (option == 3)
		{
			if (choice == '4')
			{
				cout << "Sorted by FIO of the tutor: " << endl;
				sort_opt = 6;
			}
			if (choice == '5')
			{
				cout << "Sorted by the number of study hours: " << endl;
				sort_opt = 7;
			}
			return true;
		}

		switch (choice)
		{
		case '1':
		{
			cout << "Sorted by FIO: " << endl;
			sort_opt = 1;
			break;
		}
		case '2':
		{
			cout << "Sorted by country: " << endl;
			sort_opt = 2;
			break;
		}
		case '3':
		{
			cout << "Sorted by award: " << endl;
			sort_opt = 3;
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
void Participants::hat(const int option)
{
	green cout << "|------------------------------------------------------------------";
	if (option == 1) cout << "-----------|" << endl; //верхняя граница таблицы
	if (option == 2) cout << "----------------------------------------------------------------------------------|" << endl;
	if (option == 3) cout << "----------------------------------------------|" << endl;

	cout << setw(23) << left << "|  FIO" << setw(18) << left << "|Instrument" << setw(17) 
		<< left << "|Country" << setw(9) << left << "|Award";
}
//-----------------------------------------------------------------------------------------------
bool Participants::operator==(const Participants& obj) const
{
	bool compare = false;

	if (strstr((*this).fio, obj.fio) && strlen(obj.fio)) compare = true; //является ли искомая строка частью Ф.И.О.
	else if (!strcmp((*this).instrument, obj.instrument)) compare = true;
	else if (!strcmp((*this).country, obj.country)) compare = true;
	else if ((*this).award == obj.award) compare = true;

	return compare;
}
//------------------------------------------------------------------------------------------------
bool Participants::operator>(const Participants& obj) const
{
	bool compare = false;

	if (sort_opt == 1 && strcmp((*this).fio, obj.fio) > 0) compare = true; //для сортировки по алфавиту
	if (sort_opt == 2 && strcmp((*this).country, obj.country) > 0) compare = true;
	if (sort_opt == 3 && (*this).award > obj.award) compare = true;

	return compare;
}
//------------------------------------------------------------------------------------------------
char* Participants::operator~() const //для вывода функцией objectList Ф.И.О. участников
{
	return fio;
}
//------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, const Participants& obj)
{
	yellow out << setw(20) << left << obj.fio;
	green out << "|";
	yellow out << setw(17) << left << obj.instrument;
	green out << "|";
	yellow out << setw(16) << left << obj.country;
	green out << "|";
	yellow out << setw(8) << obj.award;
	green out << "|";

	return out;
}
//----------------------------------------------------------------------------------------------
istream& operator>>(istream& in, Participants& obj)
{
	char temp[50];

	yellow cout << "\nEnter FIO of the participant: ";
	cin.ignore();
	in.getline(temp, 50);
	obj.setFio(temp);

	cout << "\nEnter the musical instrument: ";
	in.getline(temp, 50);
	obj.setInstrument(temp);

	cout << "\nEnter the country of the participant: ";
	in.getline(temp, 50);
	obj.setCountry(temp);

	cout << "\nEnter the awarded place of the participant: ";
	in >> obj.award;

	return in;
}