#pragma once

#include "Participants.h"

class MusicalSchool :public Participants
{
public:
	MusicalSchool(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0, char* = "", char* = "", char* = "", int = 0);
	MusicalSchool(const MusicalSchool&); //����������� �����������
	~MusicalSchool();
	//��� � ��� �������
	void setSchoolName(const char*);
	void setAdress(const char*);
	void setSpeciality(const char*);
	void setMark(const int);

	char* getAdress() const;
	char* getSchoolName() const;
	char* getSpeciality() const;
	int getMark() const;
	int getId() const;

	MusicalSchool fill(const char*); //������� ��������� ����� �������
	void save(MusicalSchool&, ofstream&) const; //������� ������ ������� � ����
	bool edit(); //������� �������������� ����� �������
	void hat(); //����� ��� ������ ���������� � ���� �������

	bool search(MusicalSchool&); //������� ������

	MusicalSchool& operator=(MusicalSchool&); //���������� ��������� ������������
	bool operator==(MusicalSchool&); //���������� ��������� ���������
	bool operator>(const MusicalSchool&); //���������� ��������� ���������
	friend ostream& operator<<(ostream&, MusicalSchool&); //���������� ����������
	friend istream& operator >> (istream&, MusicalSchool&); //������ � ����� � �����

private:
	char *school_name, *adress, *speciality; //�������� �����, ����� �����, �������������
	int mark; //������ � �������
	const int id = 2; //������������� ������
};