#pragma once

#include "Participants.h"

class MusicalSchool :public Participants
{
public:
	MusicalSchool(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0, char* = "", char* = "", char* = "", int = 0);
	MusicalSchool(const MusicalSchool&); //конструктор копирования
	~MusicalSchool();
	//сет и гет функции
	void setSchoolName(const char*);
	void setAdress(const char*);
	void setSpeciality(const char*);
	void setMark(const int);

	char* getAdress() const;
	char* getSchoolName() const;
	char* getSpeciality() const;
	int getMark() const;
	int getId() const;

	MusicalSchool fill(const char*); //функция заполения полей объекта
	void save(MusicalSchool&, ofstream&) const; //функция записи объекта в файл
	bool edit(); //функция редактирования полей объекта
	void hat(); //шапка дял вывода информации в виде таблицы

	bool search(MusicalSchool&); //функция поиска

	MusicalSchool& operator=(MusicalSchool&); //перегрузка оператора присваивания
	bool operator==(MusicalSchool&); //перегрузка оператора сравнения
	bool operator>(const MusicalSchool&); //перегрузка оператора сравнения
	friend ostream& operator<<(ostream&, MusicalSchool&); //перегрузка операторов
	friend istream& operator >> (istream&, MusicalSchool&); //вывода и ввода в поток

private:
	char *school_name, *adress, *speciality; //название школы, адрес школы, специализация
	int mark; //оценка в дипломе
	const int id = 2; //идентификатор класса
};