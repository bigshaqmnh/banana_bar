#pragma once

#include "Participants.h"

class SelfEducation :public Participants
{
public:
	SelfEducation(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0, int = 0);
	~SelfEducation() {};
	//сет и гет функции
	void setExperience(const int);

	int getExperience() const;
	int getId() const;
	
	SelfEducation fill(const char*); //функция заполения полей объекта
	void save(SelfEducation&, ofstream&) const; //функция записи объекта в файл
	bool edit(); //функция редактирования полей объекта
	void hat(); //шапка дял вывода информации в виде таблицы

	bool search(SelfEducation&); //функция поиска

	SelfEducation& operator=(SelfEducation&); //перегрузка оператора присваивания
	bool operator==(SelfEducation&); //перегрузка оператора сравнения
	bool operator>(const SelfEducation&); //перегрузка оператора сравнения
	friend ostream& operator<<(ostream&, SelfEducation&); //перегрузка операторов
	friend istream& operator>>(istream&, SelfEducation&); //вывода и ввода в поток

private:
	int experience; //стаж игры
	const int id = 1; //идентификатор класса
};