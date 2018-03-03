#pragma once

#include "QueueElem.h"
#include "Contest.h"

using namespace std;

template< class T >
class Queue
{
public:
	Queue();
	~Queue();
	
	int getSize() const; //���-�������, ���������� size

	void enqueue(const T&); //������� ���������� �������� � �������
	bool isEmpty() const; //�������� ����� �� �������
	void printQueue() const; //����������� �������

	bool isLoginCorrect(const char*) const; //�������� ������ �� ������������
	bool isPasswordCorrect(const char*, int&) const; //�������� ������ �� ������������
	bool objectEdit(const int) const; //��������� ����������� ������� �������
	void objectDelete(const int); //�������� ����������� ������� �� �������

	void objectList() const; //������� ������ �������� (�� ������������� ����)

	T getObject() const; //���������� �������������� ����� ��������� �������
	
	void search(T&) const; //����� �� �������
	void sort(); //���������� ������� �� �����������

	Queue< T >& operator=(const Queue&); //���������� ��������� ������������

private:
	QueueElem< T > *beginPtr, *endPtr; //��������� �� ������ � ��������� ��������
	int size; //������ �������
};