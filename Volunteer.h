#pragma once

#include "Organization.h"

class Volunteer :public Organization
{
public:
	Volunteer(char* = "", char* = "", char* = "", char* = "", char* = "");
	Volunteer(const Volunteer&); //����������� �����������
	~Volunteer();
	//��� � ��� �������
	void setFio(const char*);
	void setTelNumber(const char*);
	void setOccupation(const char*);

	char* getFio() const;
	char* getTelNumber() const;
	char* getOccupation() const;
	int getId() const;

	Volunteer fill(const char*); //������� ��������� ����� �������
	void save(Volunteer&, ofstream&) const; //������� ������ ������� � ����
	bool edit(); //������� �������������� ����� �������
	void hat(); //����� ��� ������ ���������� � ���� �������

	bool search(Volunteer&); //������� ������

	Volunteer& operator=(Volunteer&); //���������� ��������� ������������
	bool operator==(Volunteer&); //���������� ��������� ���������
	bool operator>(const Volunteer&); //���������� ��������� ���������
	char* operator~() const; //���������� ��������� ~, ���������� ��� ���������
	friend ostream& operator<<(ostream&, Volunteer&); //���������� ����������
	friend istream& operator >> (istream&, Volunteer&); //������ � ����� � �����

private:
	char* fio, *tel_number, *occupation; //�.�.�., ����� ��������, ���������
	const int id = 3; //������������� ������
};