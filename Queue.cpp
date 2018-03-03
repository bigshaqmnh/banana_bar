#include "Queue.h"

template< class T >
Queue< T >::Queue() :
	beginPtr(0), endPtr(0), size(0)
{}
//---------------------------------------------------------------
template< class T >
Queue< T >::~Queue()
{
	if (!isEmpty())
	{
		QueueElem< T > *currentPtr = beginPtr;
		QueueElem< T > *tempPtr;

		while (currentPtr) //��������������� ������� ��� �������� �������
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;

			delete tempPtr;
		}
	}
}
//-------------------------------------------------------------
template< class T >
int Queue< T >::getSize() const
{
	return size; //���������� ������� ������ �������
}
//-------------------------------------------------------------
template< class T >
void Queue< T >::enqueue(const T& obj)
{
	QueueElem< T > *newPtr = new QueueElem< T >(obj); //�������� ������ � ��������� ������ ������ ��������

	if (isEmpty()) //���� ������� �����, ����� ������� ����� ������������ ������ � ���������
		beginPtr = endPtr = newPtr;
	else
	{
		endPtr->nextPtr = newPtr; //����� ��������� ����� ������� � �����
		endPtr = newPtr;
	}

	size++; //������� ����� ������ �� 1 �������
}
//----------------------------------------------------------
template< class T >
bool Queue< T >::isEmpty() const
{
	return beginPtr == 0; //���� ��������� �� ������ ����� 0, ������ true
}
//----------------------------------------------------------
template< class T >
void Queue< T >::printQueue() const
{
	if (isEmpty()) //�������� ����� �� �������
	{
		red cout << "\nThere are no objects in the queue!" << endl;
		return;
	}

	QueueElem< T > *currentPtr = beginPtr;

	(currentPtr->info).hat(); //������ �����

	for (int i = 1; currentPtr; ++i) //� ����� ������� �������
	{
		cout << "|" << i << "." << currentPtr->info << endl;
		currentPtr = currentPtr->nextPtr;
	}
}
//----------------------------------------------------------
template< class T >
bool Queue< T >::isLoginCorrect(const char* login) const
{
	QueueElem< T > *currentPtr = beginPtr;

	while (currentPtr)
	{
		if (!strcmp((currentPtr->info).getUserName(), login)) //��������� ��������� �� �����
			return true;

		currentPtr = currentPtr->nextPtr;
	}

	return false;
}
//---------------------------------------------------------
template< class T >
bool Queue< T >::isPasswordCorrect(const char* password, int& role) const
{
	QueueElem< T > *currentPtr = beginPtr;

	while (currentPtr)
	{
		if (!strcmp((currentPtr->info).getPassword(), password)) //��������� ��������� �� ������
		{
			role = (currentPtr->info).getRole(); //���� ������, �� ������� ���� ��������� ������������
			return true;
		}

		currentPtr = currentPtr->nextPtr;
	}

	return false;
}
//----------------------------------------------------------
template< class T >
void Queue< T >::objectList() const
{
	QueueElem< T > *currentPtr = beginPtr;

	blue
	for (int i = 1; currentPtr; ++i)
	{
		cout << i << "." << ~currentPtr->info << endl; //������� ������ �������� � �������
		currentPtr = currentPtr->nextPtr;
	}
}
//---------------------------------------------------------
template< class T >
bool Queue< T >::objectEdit(const int pos) const
{
	QueueElem< T > *currentPtr = beginPtr;

	for (int i = 0; i < pos; ++i)
		currentPtr = currentPtr->nextPtr; //������������ ��������� �� ������, ������� ����� �������������

	if ((currentPtr->info).edit()) //���� ���������������
	{
		green cout << "\nThe field was changed successfully!" << endl;
		return true;
	}
	return false;
}
//--------------------------------------------------------
template< class T >
void Queue< T >::objectDelete(const int pos)
{
	if (!pos) //���� ������� ������ �������
	{
		QueueElem< T > *tempPtr = beginPtr;

		if (beginPtr == endPtr)
			beginPtr = endPtr = 0;
		else
			beginPtr = beginPtr->nextPtr;

		delete tempPtr;
	}
	else
	{
		QueueElem< T > *currentPtr = beginPtr->nextPtr;
		QueueElem< T > *tempPtr = beginPtr;

		for (int i = 0; i < pos - 1; ++i)
		{
			currentPtr = currentPtr->nextPtr; //������������ ��������� �� ��������� �������
			tempPtr = tempPtr->nextPtr; //������������ ��������� �� �������, ������� ����� ���������
		}

		if (currentPtr == endPtr) //���� ��������� ������� ��������� � �������
		{
			tempPtr->nextPtr = 0;
			endPtr = tempPtr;
		}
		else tempPtr->nextPtr = currentPtr->nextPtr;

		delete currentPtr;
	}

	size--; //��������� ������ �������
}
//--------------------------------------------------------
template< class T >
T Queue< T >::getObject() const //�������, ������������ �������������� ����� ��������
{
	static QueueElem< T > *currentPtr = beginPtr; //������ ��������� �����������, ���������
	T obj;									//������� ����� ���������� � ����� ������ ��������

	obj = currentPtr->info;
	currentPtr = currentPtr->nextPtr;

	if (!currentPtr) currentPtr = beginPtr; //���� ��������� ����� �� ����� �������, ������� �� ������

	return obj;
}
//--------------------------------------------------------
template< class T >
void Queue< T >::search(T& obj) const
{
	QueueElem< T > *currentPtr = beginPtr;

	int i = 0;
	bool find = false;

	yellow cout << "\nFound objects: " << endl;
	(currentPtr->info).hat(); //�������� ����� ��� ����������� ����������� � ���� �������

	while (currentPtr)
	{
		if (currentPtr->info == obj) //������������� ���������� ��������� ��������� �� ������� �� �����
		{
			find = true;
			green cout << "|" << ++i << "." << currentPtr->info << endl;
		}
		currentPtr = currentPtr->nextPtr;
	}

	if (!find) { purple cout << "\nNothing was found!"; }
}
//--------------------------------------------------------
template< class T >
void Queue< T >::sort()
{
	QueueElem< T > *tempPtr, *firstPtr, *secondPtr;
	bool go;

	if (isEmpty())
	{
		red cout << "\nCan't sort! The queue is empty!" << endl;
		return;
	}

	do
	{
		go = false;
		firstPtr = tempPtr = beginPtr;
		secondPtr = beginPtr->nextPtr;

		while (secondPtr)
		{
			if (firstPtr->info > secondPtr->info) //������������� ���������� ��������� ���������
			{									//��� �������� ����� ����������
				if (tempPtr == firstPtr)
					beginPtr = secondPtr; //������������ ��������� ������ �������
				else
					tempPtr->nextPtr = secondPtr;

				firstPtr->nextPtr = secondPtr->nextPtr; //������ ��������� ��� ������������ ���������
				secondPtr->nextPtr = firstPtr;

				swap(firstPtr, secondPtr); //������ �������� �������
				go = true; //���� ��������� ��������, ������� �� �� ����� ������ �� �����������
			}
			tempPtr = firstPtr;
			firstPtr = firstPtr->nextPtr; //����� ��������� �������� ��� ���������
			secondPtr = secondPtr->nextPtr;
		}
	} while (go);

	tempPtr = beginPtr;		//������������ ��������� �� ��������� �������

	for (int i = 0; i < size - 1; ++i)
		tempPtr = tempPtr->nextPtr;

	endPtr = tempPtr;
	
	printQueue();
}
//--------------------------------------------------------
template< class T >
Queue< T >& Queue< T >::operator=(const Queue& obj)
{
	if (this != &obj) //����� ������ �� ���������� ��� ����
	{
		beginPtr = obj.beginPtr;
		endPtr = obj.endPtr;
		size = obj.size;
	}
	return *this;
}