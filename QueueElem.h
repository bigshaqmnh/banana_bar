#pragma once

template< class T > class Queue;

template< class T >
class QueueElem
{
	friend class Queue <T>; //объ€вл€ем класс очередь дружным

public:
	QueueElem(const T&);

private:
	T info; //информационна€ часть элемента очереди
	QueueElem< T > *nextPtr; //указатель на следующий элемент
};

template< class T >
QueueElem< T >::QueueElem(const T& inf) :
	info(inf), nextPtr(0)
{}