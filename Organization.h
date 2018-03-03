#pragma once

#include "Contest.h"

class Organization:public Contest
{
public:
	Organization(char* = "", char* = "");
	Organization(const Organization&); //конструктор копирования
	~Organization();
	//сет и гет функции
	void setCountry(const char*);
	void setSortOpt(const int);

	char* getCountry() const;
	int getSortOpt() const;

	virtual const int getId() { return 0; } //виртуальная функция получения
										//идентификационного номера производного класса
	int o_fill(const char*); //функция заполения полей объекта

	bool sort(const int); //функция сортировки

	virtual void hat(const int); //шапка дял вывода информации в виде таблицы
	bool operator==(const Organization&) const; //перегрузка оператора сравнения
	bool operator>(const Organization&) const; //перегрузка оператора сравнения
	friend ostream& operator<<(ostream&, const Organization&); //перегрузка операторов
	friend istream& operator >> (istream&, Organization&); //вывода и ввода в поток

private:
	char* country; //страна
	static int sort_opt; //опция сортировки
};