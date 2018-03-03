#include "MusicalSchool.h"

MusicalSchool::MusicalSchool(char* s1, char* s2, char* s3, char* s4, int a, int b, char* s5, char* s6, char* s7, int c) :
	Participants(s1, s2, s3, s4, a, b)
{
	school_name = new char[strlen(s5) + 1];
	strcpy_s(school_name, strlen(s5) + 1, s5);

	adress = new char[strlen(s6) + 1];
	strcpy_s(adress, strlen(s6) + 1, s6);

	speciality = new char[strlen(s7) + 1];
	strcpy_s(speciality, strlen(s7) + 1, s7);

	mark = c;
}
//-----------------------------------------------------------------------------------------
MusicalSchool::MusicalSchool(const MusicalSchool& obj):
	Participants(obj)
{
	school_name = new char[strlen(obj.school_name) + 1];
	strcpy_s(school_name, strlen(obj.school_name) + 1, obj.school_name);

	adress = new char[strlen(obj.adress) + 1];
	strcpy_s(adress, strlen(obj.adress) + 1, obj.adress);

	speciality = new char[strlen(obj.speciality) + 1];
	strcpy_s(speciality, strlen(obj.speciality) + 1, obj.speciality);

	mark = obj.mark;
}
//-----------------------------------------------------------------------------------------
MusicalSchool::~MusicalSchool()
{
	delete[]school_name;
	delete[]adress;
	delete[]speciality;
}
//-----------------------------------------------------------------------------------------
void MusicalSchool::setAdress(const char* s)
{
	adress = new char[strlen(s) + 1];
	strcpy_s(adress, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
void MusicalSchool::setSchoolName(const char* s)
{
	school_name = new char[strlen(s) + 1];
	strcpy_s(school_name, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
void MusicalSchool::setSpeciality(const char* s)
{
	speciality = new char[strlen(s) + 1];
	strcpy_s(speciality, strlen(s) + 1, s);
}
//-----------------------------------------------------------------------------------------
void MusicalSchool::setMark(const int a)
{
	mark = a;
}
//-----------------------------------------------------------------------------------------
char* MusicalSchool::getAdress() const
{
	return adress;
}
//-----------------------------------------------------------------------------------------
char* MusicalSchool::getSchoolName() const
{
	return school_name;
}
//-----------------------------------------------------------------------------------------
char* MusicalSchool::getSpeciality() const
{
	return speciality;
}
//-----------------------------------------------------------------------------------------
int MusicalSchool::getMark() const
{
	return mark;
}
//-----------------------------------------------------------------------------------------
int MusicalSchool::getId() const
{
	return id;
}
//-----------------------------------------------------------------------------------------
MusicalSchool MusicalSchool::fill(const char* str) //заполенние полей объекта из строки
{
	MusicalSchool obj;
	
	int j = obj.p_fill(str), ind;
	char temp[50];

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setSchoolName(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setAdress(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j] != '/';)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.setSpeciality(temp);
	memset(temp, '\0', 50);

	for (ind = 0, j++; str[j];)
	{
		temp[ind] = str[j];
		j++; ind++;
	}
	temp[ind] = '\0';
	obj.mark = atoi(temp); //преобразуем в число

	return obj;
}
//-----------------------------------------------------------------------------------------
void MusicalSchool::save(MusicalSchool& obj, ofstream& file) const
{
	file << obj.getFio() << "/" << obj.getInstrument() << "/" << obj.getCountry() << "/" << obj.getAward()
		<< "/" << obj.school_name << "/" << obj.adress << "/" << obj.speciality << "/" << obj.mark << endl;
}
//-----------------------------------------------------------------------------------------
bool MusicalSchool::edit()
{
	char choice = Participants::edit(), temp[50]; //если будет выбрано изменение одного из полей этого класса, то 
												//в choice вернется 5, 6, 7 или 8, иначе вернется 0
	yellow
	switch (choice)
	{
	case '5':
	{
		cout << "Enter new school name: ";
		cin.getline(temp, 50);
		setSchoolName(temp);
		break;
	}
	case '6':
	{
		cout << "Enter new school adress: ";
		cin.getline(temp, 50);
		setAdress(temp);
		break;
	}
	case '7':
	{
		cout << "Enter new participant speciality: ";
		cin.getline(temp, 50);
		setSpeciality(temp);
		break;
	}
	case '8':
	{
		cout << "Enter new mark: ";
		cin >> mark;
		break;
	}
	case '0': return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------
void MusicalSchool::hat()
{
	Participants::hat(id); //вызываем начало шапки
	green cout << setw(26) << left << "|School name" << setw(31) << left << "|School adress"
		<< setw(16) << left << "|Speciality" << setw(9) << left << "|Mark" << right << "|" << endl;

	cout << "|------------------------------------------------------------------------------"
		<<"----------------------------------------------------------------------|"<< endl;
}
//-----------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, MusicalSchool& obj)
{
	out << dynamic_cast<Participants&> (obj); //приведение типа базового класса к производному

	yellow out << setw(25) << left << obj.school_name;
	green out << "|";
	yellow out << setw(30) << left << obj.adress;
	green out << "|";
	yellow out << setw(15) << left << obj.speciality;
	green out << "|";
	yellow out << setw(8) << left << obj.mark;
	green out << "|" << endl;

	out << "|--------------------------------------------------------------------------------"
		<< "--------------------------------------------------------------------|";

	return out;
}
//-----------------------------------------------------------------------------------------
istream& operator>>(istream& in, MusicalSchool& obj)
{
	char temp[30];
	
	in >> dynamic_cast<Participants&> (obj); //приведение типа базового класса к производному

	yellow cout << "\nEnter school name: ";
	cin.ignore();
	in.getline(temp, 30);
	obj.setSchoolName(temp);

	cout << "\nEnter school adress: ";
	in.getline(temp, 30);
	obj.setAdress(temp);

	cout << "\nEnter speciality of the participant: ";
	in.getline(temp, 30);
	obj.setSpeciality(temp);

	cout << "\nEnter mark of the participant: ";
	cin >> obj.mark;

	return in;
}
//-----------------------------------------------------------------------------------------
MusicalSchool& MusicalSchool::operator=(MusicalSchool& obj)
{
	if (this != &obj) //чтобы объект не присвоился самому себе
	{
		setFio(obj.getFio());
		setInstrument(obj.getInstrument());
		setCountry(obj.getCountry());
		setAward(obj.getAward());
		setSchoolName(obj.school_name);
		setAdress(obj.adress);
		setSpeciality(obj.speciality);
		mark = obj.mark;
	}
	return *this;
}
//-----------------------------------------------------------------------------------------
bool MusicalSchool::operator>(const MusicalSchool& obj)
{
	bool compare = Participants::operator>(obj); //для сравнения с полями базового класса

	if (compare) return compare; //если в базовом классе сравнение успешно
	else if (getSortOpt() == 5 && (*this).mark > obj.mark) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool MusicalSchool::operator==(MusicalSchool& obj)
{
	bool compare = Participants::operator==(obj); //для сравнения с полями базового класса

	if (compare) return compare; //если в базовом классе сравнение успешно
	else if (strstr((*this).school_name, obj.school_name) && strlen(obj.school_name)) compare = true;
	else if (strstr((*this).adress, obj.adress) && strlen(obj.adress)) compare = true;
	else if (!strcmp((*this).speciality, obj.speciality)) compare = true;
	else if ((*this).mark == obj.mark) compare = true;

	return compare;
}
//-----------------------------------------------------------------------------------------
bool MusicalSchool::search(MusicalSchool& obj)
{
	char choice, temp[50];
	bool flag_1, flag_2;

	do
	{
		flag_1 = false;
	
		choice = obj.p_search(id); //заполняем поля объекта, относящиеся к классу Participants

		yellow
		switch (choice)
		{
		case '5':
		{
			cout << "Enter the name of the musical school: ";
			cin.getline(temp, 50);
			obj.setSchoolName(temp);
			break;
		}
		case '6':
		{
			cout << "Enter the adress of the musical school: ";
			cin.getline(temp, 50);
			obj.setAdress(temp);
			break;
		}
		case '7':
		{
			cout << "Enter the speciality of the participant: ";
			cin.getline(temp, 50);
			obj.setSpeciality(temp);
			break;
		}
		case '8':
		{
			cout << "Enter the mark: ";
			cin >> obj.mark;
			break;
		}
		case '0': return false;
		}
		do
		{
			flag_2 = false;

			purple cout << "\nDo you want to add another field for search? (1 - Yes, 2 - No)" << endl;
			cin >> choice;

			if (choice == '1') flag_1 = true; //продолжение цикла для выбора еще одного поля для сортировки
			else if (choice != '2')
			{
				red cout << "Wrong input! Try again!";
				flag_2 = true;
			}
		} while (flag_2);
	} while (flag_1);

	return true;
}