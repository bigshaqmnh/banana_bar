#pragma once

#include "Participants.h"

class Tutor :public Participants
{
public:
	Tutor(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0, char* = "", int = 0, int = 0);
	Tutor(const Tutor&); //конструктор копирования
	~Tutor();
	//сет и гет функции
	void setTutorFio(const char*);
	void setHours(const int);
	void setCost(const int);

	char* getTutorFio() const;
	int getHours() const;
	int getCost() const;
	int getId() const;

	Tutor fill(const char*); //функция заполения полей объекта
	void save(Tutor&, ofstream&) const; //функция записи объекта в файл
	bool edit(); //функция редактирования полей объекта
	void hat(); //шапка дял вывода информации в виде таблицы

	bool search(Tutor&); //функция поиска

	Tutor& operator=(Tutor&); //перегрузка оператора присваивания
	bool operator==(Tutor&); //перегрузка оператора сравнения
	bool operator>(const Tutor&); //перегрузка оператора сравнения
	friend ostream& operator<<(ostream&, Tutor&); //перегрузка операторов
	friend istream& operator >> (istream&, Tutor&); //вывода и ввода в поток

private:
	char* tutor_fio; //Ф.И.О. репетитора
	int hours, cost; //учебные часы, стоимость одного часа
	const int id = 3; //идентификатор класса
};