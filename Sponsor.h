#pragma once

#include "Organization.h"

class Sponsor :public Organization
{
public:
	Sponsor(char* = "", char* = "", char* = "", int = 0);
	Sponsor(const Sponsor&); //конструктор копирования
	~Sponsor();
	//сет и гет функции
	void setLegalName(const char*);
	void setBudget(const int);

	char* getLegalName() const;
	int getBudget() const;
	int getId() const;
	
	Sponsor fill(const char*); //функция заполения полей объекта
	void save(Sponsor&, ofstream&) const; //функция записи объекта в файл
	bool edit(); //функция редактирования полей объекта
	void hat(); //шапка дял вывода информации в виде таблицы

	bool search(Sponsor&); //функция поиска

	Sponsor& operator=(Sponsor&); //перегрузка оператора присваивания
	bool operator==(Sponsor&); //перегрузка оператора сравнения
	bool operator>(const Sponsor&); //перегрузка оператора сравнения
	char* operator~() const; //перегрузка оператора ~, возвращает юридическое имя спонсора
	friend ostream& operator<<(ostream&, Sponsor&); //перегрузки операторов
	friend istream& operator >> (istream&, Sponsor&); //вывода и ввода в поток

private:
	char* legal_name; //юридическое имя
	int contribution; //вклад
	const int id = 1; //идентификатор класса
};