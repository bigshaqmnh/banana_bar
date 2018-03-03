#pragma once

#include "Participants.h"

class SelfEducation :public Participants
{
public:
	SelfEducation(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0, int = 0);
	~SelfEducation() {};
	//��� � ��� �������
	void setExperience(const int);

	int getExperience() const;
	int getId() const;
	
	SelfEducation fill(const char*); //������� ��������� ����� �������
	void save(SelfEducation&, ofstream&) const; //������� ������ ������� � ����
	bool edit(); //������� �������������� ����� �������
	void hat(); //����� ��� ������ ���������� � ���� �������

	bool search(SelfEducation&); //������� ������

	SelfEducation& operator=(SelfEducation&); //���������� ��������� ������������
	bool operator==(SelfEducation&); //���������� ��������� ���������
	bool operator>(const SelfEducation&); //���������� ��������� ���������
	friend ostream& operator<<(ostream&, SelfEducation&); //���������� ����������
	friend istream& operator>>(istream&, SelfEducation&); //������ � ����� � �����

private:
	int experience; //���� ����
	const int id = 1; //������������� ������
};