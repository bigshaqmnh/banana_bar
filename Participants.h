#pragma once

#include "Contest.h"

class Participants :public Contest
{
public:
	Participants(char* = "", char* = "", char* = "", char* = "", int = 0, int = 0);
	Participants(const Participants&); //����������� �����������
	~Participants();
	//��� � ��� �������
	void setFio(const char*);
	void setInstrument(const char*);
	void setCountry(const char*);
	void setAward(const int);
	void setSortOpt(const int);
	
	char* getFio() const;
	char* getInstrument() const;
	char* getCountry() const;
	int getAward() const;
	int getSortOpt() const;

	virtual int getId() const { return 0; } //����������� ������� ���������
											//������������������ ������ ������������ ������
	int p_fill(const char*); //������� ��������� ����� �������
	char edit(); //������� �������������� ����� �������

	char p_search(const int); //������� ������
	bool sort(const int); //������� ����������
	
	virtual void hat(const int); //����� ��� ������ ���������� � ���� �������
	bool operator==(const Participants&) const; //���������� ��������� ���������
	bool operator>(const Participants&) const; //���������� ��������� ���������
	char* operator~() const; //���������� ��������� ~, ���������� �.�.�.
	friend ostream& operator<<(ostream&, const Participants&); //���������� ����������
	friend istream& operator>>(istream&, Participants&); //������ � ����� � �����

private:
	char *fio, *instrument, *country; //�.�.�., ����������, ������
	int award; //������� �����
	static int sort_opt; //����� ����������
};