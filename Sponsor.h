#pragma once

#include "Organization.h"

class Sponsor :public Organization
{
public:
	Sponsor(char* = "", char* = "", char* = "", int = 0);
	Sponsor(const Sponsor&); //����������� �����������
	~Sponsor();
	//��� � ��� �������
	void setLegalName(const char*);
	void setBudget(const int);

	char* getLegalName() const;
	int getBudget() const;
	int getId() const;
	
	Sponsor fill(const char*); //������� ��������� ����� �������
	void save(Sponsor&, ofstream&) const; //������� ������ ������� � ����
	bool edit(); //������� �������������� ����� �������
	void hat(); //����� ��� ������ ���������� � ���� �������

	bool search(Sponsor&); //������� ������

	Sponsor& operator=(Sponsor&); //���������� ��������� ������������
	bool operator==(Sponsor&); //���������� ��������� ���������
	bool operator>(const Sponsor&); //���������� ��������� ���������
	char* operator~() const; //���������� ��������� ~, ���������� ����������� ��� ��������
	friend ostream& operator<<(ostream&, Sponsor&); //���������� ����������
	friend istream& operator >> (istream&, Sponsor&); //������ � ����� � �����

private:
	char* legal_name; //����������� ���
	int contribution; //�����
	const int id = 1; //������������� ������
};