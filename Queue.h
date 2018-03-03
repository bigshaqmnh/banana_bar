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
	
	int getSize() const; //гет-функци€, возвращает size

	void enqueue(const T&); //функци€ добавлени€ элемента в очередь
	bool isEmpty() const; //проверка пуста ли очередь
	void printQueue() const; //распечатать очередь

	bool isLoginCorrect(const char*) const; //проверка логина на правильность
	bool isPasswordCorrect(const char*, int&) const; //проверка парол€ на правильность
	bool objectEdit(const int) const; //изменение конкретного объекта очереди
	void objectDelete(const int); //удаление конкретного объекта из очереди

	void objectList() const; //вывести список объектов (по определ€ющему полю)

	T getObject() const; //возвращает информационную часть заданного объекта
	
	void search(T&) const; //поиск по очереди
	void sort(); //сортировка очереди по возрастанию

	Queue< T >& operator=(const Queue&); //перегрузка оператора присваивани€

private:
	QueueElem< T > *beginPtr, *endPtr; //указатели на первый и последний элементы
	int size; //размер очереди
};