#pragma once

template< class T > class Queue;

template< class T >
class QueueElem
{
	friend class Queue <T>; //��������� ����� ������� �������

public:
	QueueElem(const T&);

private:
	T info; //�������������� ����� �������� �������
	QueueElem< T > *nextPtr; //��������� �� ��������� �������
};

template< class T >
QueueElem< T >::QueueElem(const T& inf) :
	info(inf), nextPtr(0)
{}