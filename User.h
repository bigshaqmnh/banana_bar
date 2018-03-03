#pragma once

#include "Contest.h"

class User
{
public:
	User(char* = "", char* = "", int = 0);
	~User() {};
	//��� � ��� �������
	void setUserName(const char*);
	void setPassword(const char*);
	void setRole(const int);

	char* getUserName();
	char* getPassword();
	int getRole() const;

	static User fill(const char*); //����������� ������� ��������� ����� �������
	bool edit(); //������� �������������� ����� �������
	void hat(); //����� ��� ������ ���������� � ���� �������

	User& operator=(const User&); //���������� ��������� ������������
	char* operator~(); //���������� ��������� ~, ���������� ��� ������������
	friend ostream& operator<<(ostream&, const User&); //���������� ����������
	friend istream& operator>>(istream&, User&); //������ � ����� � �����

private:
	char user_name[30], password[30]; //��� ������������, ������
	int role; //���� (1 - �����, 0 - ������� ������������)
};