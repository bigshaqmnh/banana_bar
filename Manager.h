#pragma once

#include "Organization.h"

class Manager :public Organization
{
public:
	Manager(char* = "", char* = "", char* = "", char* = "");
	Manager(const Manager&); //конструктор копирования
	~Manager();
	//сет и гет функции
	void setFio(const char*);
	void setJob(const char*);

	char* getFio() const;
	char* getJob() const;
	int getId() const;

	Manager fill(const char*); //функция заполения полей объекта
	void save(Manager&, ofstream&) const; //функция записи объекта в файл
	bool edit(); //функция редактирования полей объекта
	void hat(); //шапка дял вывода информации в виде таблицы

	bool search(Manager&); //функция поиска

	Manager& operator=(Manager&); //перегрузка оператора присваивания
	bool operator==(Manager&); //перегрузка оператора сравнения
	bool operator>(const Manager&); //перегрузка оператора сравнения
	char* operator~() const; //перегрузка оператора ~, возвращает юридическое имя менеджера
	friend ostream& operator<<(ostream&, Manager&); //перегрузки операторов
	friend istream& operator >> (istream&, Manager&); //вывода и ввода в поток

private:
	char* fio, *job; //Ф.И.О., работа
	const int id = 2; //идентификатор класса
};