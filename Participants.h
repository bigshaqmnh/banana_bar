#pragma once

#include "Contest.h"

class Participants :public Contest
{
public:
	Participants(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0);
	Participants(const Participants&); //конструктор копирования
	~Participants();
	//сет и гет функции
	void setFio(const char*);
	void setInstrument(const char*);
	void setCountry(const char*);
	void setAward(const int);
	void setSortOpt(const int);
	
	char* getFio() const;
	char* getInstrument() const;
	char* getCountry() const;
	int getAward() const;
	int getSortOpt() const;

	virtual int getId() const { return 0; } //виртуальная функция получения
											//идентификационного номера производного класса
	int p_fill(const char*); //функция заполения полей объекта
	char edit(); //функция редактирования полей объекта

	char p_search(const int); //функция поиска
	bool sort(const int); //функция сортировки
	
	virtual void hat(const int); //шапка дял вывода информации в виде таблицы
	bool operator==(const Participants&) const; //перегрузка оператора сравнения
	bool operator>(const Participants&) const; //перегрузка оператора сравнения
	char* operator~() const; //перегрузка оператора ~, возвращает Ф.И.О.
	friend ostream& operator<<(ostream&, const Participants&); //перегрузка операторов
	friend istream& operator>>(istream&, Participants&); //вывода и ввода в поток

private:
	char *fio, *instrument, *country; //Ф.И.О., инструмент, страна
	int award; //занятое место
	static int sort_opt; //опция сортировки
};