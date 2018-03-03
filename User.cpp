#include "User.h"

User::User(char* s1, char* s2, int a)
{
	strcpy_s(user_name, strlen(s1) + 1, s1);
	strcpy_s(password, strlen(s2) + 1, s2);
	role = a;
}
//-------------------------------------------------------------
void User::setUserName(const char* s)
{
	strcpy_s(user_name, strlen(s) + 1, s);
}
//-------------------------------------------------------------
void User::setPassword(const char* s)
{
	strcpy_s(password, strlen(s) + 1, s);
}
//-------------------------------------------------------------
void User::setRole(const int a)
{
	role = a;
}
//-------------------------------------------------------------
char* User::getUserName()
{
	return user_name;
}
//-------------------------------------------------------------
char* User::getPassword()
{
	return password;
}
//-------------------------------------------------------------
int User::getRole() const
{
	return role;
}
//-------------------------------------------------------------
User User::fill(const char* str) //функция заполения полей объекта из строки
{
	User obj;
	
	int j, ind;
			
	for (ind = 0, j = 0; str[j] != ' ';) //поля в строке разделены пробелами
	{
		obj.user_name[ind] = str[j];
		j++; ind++;
	}
	obj.user_name[ind] = '\0';

	for (ind = 0, j++; str[j] != ' ';)
	{
		obj.password[ind] = str[j];
		j++; ind++;
	}
	obj.password[ind] = '\0';

	obj.role = str[++j] - 48; //роль - целочисленное значение

	return obj; //возвращаем заполненный объект
}
//-------------------------------------------------------------
bool User::edit()
{
	char choice, temp[30];
	int a;
	bool flag_1, flag_2;

	do
	{
		flag_1 = false;

		system("cls");
		purple cout << "What field do you want to edit?" << endl;
		blue cout << "1.User name \n2.User password \n3.User role" << endl;
		cout << "0.Back to menu" << endl;

		cin >> choice;

		yellow
		switch (choice)
		{
		case '1':
		{
			cout << "Enter new user name: ";
			cin.ignore();
			cin.getline(temp, 30);
			setUserName(temp);
			break;
		}
		case '2':
		{
			cout << "Enter new password: ";
			cin.ignore();
			cin.getline(temp, 30);
			setPassword(temp);
			break;
		}
		case '3':
		{
			do
			{
				flag_2 = false;

				purple cout << "Choose a new role for the user:" << endl;
				blue cout << "1.Simple user \n2.Admin" << endl;

				cin >> a;

				if (a != 1 && a != 2)
				{
					red cout << "\nWrong input! Try again." << endl;
					flag_2 = true;
				}
				else role = --a; //роль имеет значения 0 или 1
			} while (flag_2);
		}
		case '0': return false;
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			Sleep(1500);
			flag_1 = true;
		}
		}
	} while (flag_1);

	return true; //изменения были произведены
}
//-------------------------------------------------------------
void User::hat()
{
	green cout << "|---------------------------------------------------------|" << endl;

	cout << setw(23) << left << "|  User name" << setw(21) << left << "|Password" 
		<< setw(14) << left << "|Role" << "|"<< endl;

	cout << "|---------------------------------------------------------|" << endl;
}
//-------------------------------------------------------------
ostream& operator<<(ostream& out, const User& obj)
{
	yellow out << setw(20) << left << obj.user_name;
	green out << "|";
	yellow out << setw(20) << left << obj.password;
	green out << "|";
	if (obj.role) { yellow out << setw(13) << left << "admin"; } //выводим роль словами
	else { yellow out << setw(13) << left << "simple user"; }
	green out << "|" << endl;

	out << "|---------------------------------------------------------|";

	return out;
}
//-------------------------------------------------------------
istream& operator>>(istream& in, User& obj)
{
	char temp[30];
	int a;
	bool flag;

	yellow cout << "Enter new user name: ";
	cin.ignore();
	in.getline(temp, 30);
	strcpy_s(obj.user_name, strlen(temp) + 1, temp);

	cout << "Enter new user password: ";
	in.getline(temp, 30);
	strcpy_s(obj.password, strlen(temp) + 1, temp);

	do
	{
		flag = false;

		purple cout << "Choose the role of a new user" << endl;
		blue cout << "1.Simple user \n2.Admin" << endl;

		in >> a;

		if (a != 1 && a != 2)
		{
			red cout << "\nWrong input! Try again." << endl;
			flag = true;
		}
		else obj.role = --a;
	} while (flag);

	return in;
}
//-------------------------------------------------------------
User& User::operator=(const User& obj)
{
	if (this != &obj) //чтобы объект не присвоился самому себе
	{
		strcpy_s(user_name, obj.user_name);
		strcpy_s(password, obj.password);
		role = obj.role;
	}
	return *this;
}
//-------------------------------------------------------------
char* User::operator~() //для функции objectList класса Queue
{
	return user_name;
}