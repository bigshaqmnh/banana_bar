#pragma once

#include "User.h"
#include "SelfEducation.h"
#include "MusicalSchool.h"
#include "Tutor.h"
#include "Sponsor.h"
#include "Manager.h"
#include "Volunteer.h"
#include "Queue.cpp"

template< class T >
class Interface
{
public:
	Interface(int = 0);
	~Interface() {};

	void authorization(); //������� ����������� ������������
	void menu(); //������� ����
	void participants_menu() const; //���� ����������
	void organization_menu() const; //���� �����������
	void users_menu(); //���� �������������
	void option(); //����� ����� ��� ������ � �������

	int strcount(const char*) const; //������� ���-�� ����� � �����
	void openFile(T&, char*); //������� �������� �����
	void saveToFile() const; //���������� ������ � ������������� � ����
	void saveToFile(T&, const bool, char*) const; // ���������� ������ �� ���������� � ����
	bool saveCheck() const; //���������� ��������� �� ������ ����� ���������
	
private:
	int role; //���� ������������
	Queue< T > queue; //������ ���� �������, ��� ������ � �������
};