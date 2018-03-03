#pragma once

#include "Contest.h"

class User
{
public:
	User(char* = "", char* = "", int = 0);
	~User() {};
	//сет и гет функции
	void setUserName(const char*);
	void setPassword(const char*);
	void setRole(const int);

	char* getUserName();
	char* getPassword();
	int getRole() const;

	static User fill(const char*); //статическая функция заполения полей объекта
	bool edit(); //функция редактирования полей объекта
	void hat(); //шапка дял вывода информации в виде таблицы

	User& operator=(const User&); //перегрузка оператора присваивания
	char* operator~(); //перегрузка оператора ~, возвращает имя пользователя
	friend ostream& operator<<(ostream&, const User&); //перегрузки операторов
	friend istream& operator>>(istream&, User&); //вывода и ввода в поток

private:
	char user_name[30], password[30]; //имя пользователя, пароль
	int role; //роль (1 - админ, 0 - обычный пользователь)
};