#pragma once

#include "Contest.h"

class Organization:public Contest
{
public:
	Organization(char* = "", char* = "");
	Organization(const Organization&); //����������� �����������
	~Organization();
	//��� � ��� �������
	void setCountry(const char*);
	void setSortOpt(const int);

	char* getCountry() const;
	int getSortOpt() const;

	virtual const int getId() { return 0; } //����������� ������� ���������
										//������������������ ������ ������������ ������
	int o_fill(const char*); //������� ��������� ����� �������

	bool sort(const int); //������� ����������

	virtual void hat(const int); //����� ��� ������ ���������� � ���� �������
	bool operator==(const Organization&) const; //���������� ��������� ���������
	bool operator>(const Organization&) const; //���������� ��������� ���������
	friend ostream& operator<<(ostream&, const Organization&); //���������� ����������
	friend istream& operator >> (istream&, Organization&); //������ � ����� � �����

private:
	char* country; //������
	static int sort_opt; //����� ����������
};