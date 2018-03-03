#pragma once
#define u_filename "Users.txt"

#include <iostream>
#include <cstring>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

#define red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
#define orange SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
#define yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
#define green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#define blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
#define purple SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED);

using namespace std;

class Contest
{
public:
	Contest(char* = "");
	Contest(const Contest&); //констркутор копирования
	~Contest();
	//сет и гет функции
	void setContestName(const char*);
	char* getContestName() const;

	void fillContestName(); //функция заполенния названия конкурса
	
private:
	char* contest_name; //название конкурса
};