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

		while (currentPtr) //последовательно удаляем все элементы очереди
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
	return size; //возвращаем текущий размер очереди
}
//-------------------------------------------------------------
template< class T >
void Queue< T >::enqueue(const T& obj)
{
	QueueElem< T > *newPtr = new QueueElem< T >(obj); //выделяем память и заполняем данные нового элемента

	if (isEmpty()) //если очередь пуста, новый элемент будет одновременно первым и последним
		beginPtr = endPtr = newPtr;
	else
	{
		endPtr->nextPtr = newPtr; //иначе добавляем новый элемент в конец
		endPtr = newPtr;
	}

	size++; //очередь стала больше на 1 элемент
}
//----------------------------------------------------------
template< class T >
bool Queue< T >::isEmpty() const
{
	return beginPtr == 0; //если указатель на начало равен 0, вернет true
}
//----------------------------------------------------------
template< class T >
void Queue< T >::printQueue() const
{
	if (isEmpty()) //проверка пуста ли очередь
	{
		red cout << "\nThere are no objects in the queue!" << endl;
		return;
	}

	QueueElem< T > *currentPtr = beginPtr;

	(currentPtr->info).hat(); //вывсти шапку

	for (int i = 1; currentPtr; ++i) //в цикле выводим объекты
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
		if (!strcmp((currentPtr->info).getUserName(), login)) //проверяем совпадает ли логин
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
		if (!strcmp((currentPtr->info).getPassword(), password)) //проверяем совпадает ли пароль
		{
			role = (currentPtr->info).getRole(); //если совпал, то заносим роль вошедшего пользователя
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
		cout << i << "." << ~currentPtr->info << endl; //выводим список объектов в очереди
		currentPtr = currentPtr->nextPtr;
	}
}
//---------------------------------------------------------
template< class T >
bool Queue< T >::objectEdit(const int pos) const
{
	QueueElem< T > *currentPtr = beginPtr;

	for (int i = 0; i < pos; ++i)
		currentPtr = currentPtr->nextPtr; //переставляем указатель на объект, который хотим редактировать

	if ((currentPtr->info).edit()) //если отредактировали
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
	if (!pos) //если удаляем первый элемент
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
			currentPtr = currentPtr->nextPtr; //переставляем указатель на удаляемый элемент
			tempPtr = tempPtr->nextPtr; //переставляем указатель на элемент, стоящий перед удаляемым
		}

		if (currentPtr == endPtr) //если удаляемый элемент последний в очереди
		{
			tempPtr->nextPtr = 0;
			endPtr = tempPtr;
		}
		else tempPtr->nextPtr = currentPtr->nextPtr;

		delete currentPtr;
	}

	size--; //уменьшаем размер очереди
}
//--------------------------------------------------------
template< class T >
T Queue< T >::getObject() const //функция, возвращающая информационную часть элемента
{
	static QueueElem< T > *currentPtr = beginPtr; //делаем указатель статическим, поскольку
	T obj;									//функция будет вызываться в цикле дургой функцией

	obj = currentPtr->info;
	currentPtr = currentPtr->nextPtr;

	if (!currentPtr) currentPtr = beginPtr; //если указатель дошел до конца очереди, скинуть на начало

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
	(currentPtr->info).hat(); //вызываем шапку для отображения результатов в виде таблицы

	while (currentPtr)
	{
		if (currentPtr->info == obj) //задействуется перегрузка оператора сравнения по каждому из полей
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
			if (firstPtr->info > secondPtr->info) //задействуется перегрузка оператора сравнения
			{									//для заданной опции сортировки
				if (tempPtr == firstPtr)
					beginPtr = secondPtr; //переставляем указатель начала очереди
				else
					tempPtr->nextPtr = secondPtr;

				firstPtr->nextPtr = secondPtr->nextPtr; //меняем указатели для сравниваемых элементов
				secondPtr->nextPtr = firstPtr;

				swap(firstPtr, secondPtr); //меняем элементы местами
				go = true; //пока находятся элементы, стоящие не на своих местах по возрастанию
			}
			tempPtr = firstPtr;
			firstPtr = firstPtr->nextPtr; //берем следующие элементы для сравнения
			secondPtr = secondPtr->nextPtr;
		}
	} while (go);

	tempPtr = beginPtr;		//Переставляем указатель на последний элемент

	for (int i = 0; i < size - 1; ++i)
		tempPtr = tempPtr->nextPtr;

	endPtr = tempPtr;
	
	printQueue();
}
//--------------------------------------------------------
template< class T >
Queue< T >& Queue< T >::operator=(const Queue& obj)
{
	if (this != &obj) //чтобы объект не присвоился сам себе
	{
		beginPtr = obj.beginPtr;
		endPtr = obj.endPtr;
		size = obj.size;
	}
	return *this;
}