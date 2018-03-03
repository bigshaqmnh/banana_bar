#pragma once

#include "Participants.h"

class Tutor :public Participants
{
public:
	Tutor(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0, char* = "", int = 0, int = 0);
	Tutor(const Tutor&); //����������� �����������
	~Tutor();
	//��� � ��� �������
	void setTutorFio(const char*);
	void setHours(const int);
	void setCost(const int);

	char* getTutorFio() const;
	int getHours() const;
	int getCost() const;
	int getId() const;

	Tutor fill(const char*); //������� ��������� ����� �������
	void save(Tutor&, ofstream&) const; //������� ������ ������� � ����
	bool edit(); //������� �������������� ����� �������
	void hat(); //����� ��� ������ ���������� � ���� �������

	bool search(Tutor&); //������� ������

	Tutor& operator=(Tutor&); //���������� ��������� ������������
	bool operator==(Tutor&); //���������� ��������� ���������
	bool operator>(const Tutor&); //���������� ��������� ���������
	friend ostream& operator<<(ostream&, Tutor&); //���������� ����������
	friend istream& operator >> (istream&, Tutor&); //������ � ����� � �����

private:
	char* tutor_fio; //�.�.�. ����������
	int hours, cost; //������� ����, ��������� ������ ����
	const int id = 3; //������������� ������
};