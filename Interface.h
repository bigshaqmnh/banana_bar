#pragma once

#include "User.h"
#include "SelfEducation.h"
#include "MusicalSchool.h"
#include "Tutor.h"
#include "Sponsor.h"
#include "Manager.h"
#include "Volunteer.h"
#include "Queue.cpp"

template< class T >
class Interface
{
public:
	Interface(int = 0);
	~Interface() {};

	void authorization(); //функция авторизации пользователя
	void menu(); //главное меню
	void participants_menu() const; //меню участников
	void organization_menu() const; //меню организации
	void users_menu(); //меню пользователей
	void option(); //выбор опции для работы с данными

	int strcount(const char*) const; //подсчет кол-ва строк в файле
	void openFile(T&, char*); //функция открытия файла
	void saveToFile() const; //сохранения данных о пользователях в файл
	void saveToFile(T&, const bool, char*) const; // сохранений данных об участниках в файл
	bool saveCheck() const; //спрашивает сохранять ли данные после изменения
	
private:
	int role; //роль пользователя
	Queue< T > queue; //объект типа очередь, для работы с данными
};