#pragma once

#include "Organization.h"

class Volunteer :public Organization
{
public:
	Volunteer(char* = "", char* = "", char* = "", char* = "", char* = "");
	Volunteer(const Volunteer&); //конструктор копирования
	~Volunteer();
	//сет и гет функции
	void setFio(const char*);
	void setTelNumber(const char*);
	void setOccupation(const char*);

	char* getFio() const;
	char* getTelNumber() const;
	char* getOccupation() const;
	int getId() const;

	Volunteer fill(const char*); //функция заполения полей объекта
	void save(Volunteer&, ofstream&) const; //функция записи объекта в файл
	bool edit(); //функция редактирования полей объекта
	void hat(); //шапка дял вывода информации в виде таблицы

	bool search(Volunteer&); //функция поиска

	Volunteer& operator=(Volunteer&); //перегрузка оператора присваивания
	bool operator==(Volunteer&); //перегрузка оператора сравнения
	bool operator>(const Volunteer&); //перегрузка оператора сравнения
	char* operator~() const; //перегрузка оператора ~, возвращает имя волонтера
	friend ostream& operator<<(ostream&, Volunteer&); //перегрузки операторов
	friend istream& operator >> (istream&, Volunteer&); //вывода и ввода в поток

private:
	char* fio, *tel_number, *occupation; //Ф.И.О., номер теоефона, занятость
	const int id = 3; //идентификатор класса
};