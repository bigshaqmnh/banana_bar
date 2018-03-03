#include "Contest.h"

Contest::Contest(char* s)
{
	contest_name = new char[strlen(s) + 1];
	strcpy_s(contest_name, strlen(s) + 1, s);
}
//---------------------------------------------------------------------------------------------
Contest::Contest(const Contest& obj)
{
	contest_name = new char[strlen(obj.contest_name) + 1];
	strcpy_s(contest_name, strlen(obj.contest_name) + 1, obj.contest_name);
}
//---------------------------------------------------------------------------------------------
Contest::~Contest()
{
	delete[]contest_name;
}
//---------------------------------------------------------------------------------------------
void Contest::setContestName(const char* s)
{
	contest_name = new char[strlen(s) + 1];
	strcpy_s(contest_name, strlen(s) + 1, s);
}
//---------------------------------------------------------------------------------------------
char* Contest::getContestName() const
{
	return contest_name;
}
//---------------------------------------------------------------------------------------------
void Contest::fillContestName()
{
	char s[50];

	yellow cout << "\nEnter the Contest name: ";
	cin.ignore();
	cin.getline(s, 50);

	contest_name = new char[strlen(s) + 1];
	strcpy_s(contest_name, strlen(s) + 1, s);
}