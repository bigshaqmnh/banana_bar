#pragma once

#include "Organization.h"

class Manager :public Organization
{
public:
	Manager(char* = "", char* = "", char* = "", char* = "");
	Manager(const Manager&); //����������� �����������
	~Manager();
	//��� � ��� �������
	void setFio(const char*);
	void setJob(const char*);

	char* getFio() const;
	char* getJob() const;
	int getId() const;

	Manager fill(const char*); //������� ��������� ����� �������
	void save(Manager&, ofstream&) const; //������� ������ ������� � ����
	bool edit(); //������� �������������� ����� �������
	void hat(); //����� ��� ������ ���������� � ���� �������

	bool search(Manager&); //������� ������

	Manager& operator=(Manager&); //���������� ��������� ������������
	bool operator==(Manager&); //���������� ��������� ���������
	bool operator>(const Manager&); //���������� ��������� ���������
	char* operator~() const; //���������� ��������� ~, ���������� ����������� ��� ���������
	friend ostream& operator<<(ostream&, Manager&); //���������� ����������
	friend istream& operator >> (istream&, Manager&); //������ � ����� � �����

private:
	char* fio, *job; //�.�.�., ������
	const int id = 2; //������������� ������
};