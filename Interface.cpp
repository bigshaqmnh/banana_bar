#include "Interface.h"

template< class T >
Interface< T >::Interface(int a)
{
	role = a; //задаем роль пользователя (обычный/администратор)
}
//--------------------------------------------------------------------------------------
template< class T >
void Interface< T >::menu() //главное меню
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		system("cls");
		purple cout << "Main menu:" << endl;
		blue cout << "1.Work with Participants" << endl;
		cout << "2.Work with Organization" << endl;
		if (role) cout << "3.Work with Users" << endl; //доступно только админу
		cout << "0.Exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			participants_menu(); //меню для работы с участниками
			break;
		}
		case '2':
		{
			organization_menu(); //меню для работы с организацией
			break;
		}
		case '3':
		{
			if (!role) //если обычный пользователь сделает выбор
			{
				red cout << "Wrong input! Try again." << endl;
				flag = true;
				Sleep(1500);
				break;
			}
			else users_menu(); //меню для работы с пользователями
			break;
		}
		case '0': break;
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			flag = true;
			Sleep(1500);
		}
		}
	} while (choice != '0' || flag); //пока не захотим выйти, повторит цикл при некорректном вводе
}
//--------------------------------------------------------------------------------------
template< class T >
void Interface< T >::participants_menu() const
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		system("cls");
		blue cout << "1.Work with Self-educated participants" << endl;
		cout << "2.Work with participants from Musical Schools" << endl;
		cout << "3.Work with participants studied with Tutors" << endl;
		cout << "0.Back to main menu" << endl;

		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			Interface< SelfEducation > obj(role); //создаем объект шаблонного класса интерфейс
			obj.option();						//для работы с участниками-самоучками
			break;
		}
		case '2':
		{
			Interface< MusicalSchool > obj(role);
			obj.option();
			break;
		}
		case '3':
		{
			Interface< Tutor > obj(role);
			obj.option();
			break;
		}
		case '0': continue;
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			Sleep(1500);
			flag = true;
		}
		}
	} while (flag);
}
//--------------------------------------------------------------------------------------
template< class T >
void Interface< T >::organization_menu() const
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		system("cls");
		blue cout <<"1.Work with Sponsors"<< endl;
		cout <<"2.Work with Managers"<< endl;
		cout <<"3.Work with Volunteers"<< endl;
		cout <<"0.Back to main menu"<< endl;

		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			Interface< Sponsor > obj(role);
			obj.option();
			break;
		}
		case '2':
		{
			Interface< Manager > obj(role);
			obj.option();
			break;
		}
		case '3':
		{
			Interface< Volunteer > obj(role);
			obj.option();
			break;
		}
		case '0': continue;
		default:
		{
			red cout <<"Wrong input! Try again."<< endl;
			Sleep(1500);
			flag = true;
		}
		}
	} while (flag);
}
//--------------------------------------------------------------------------------------
template< class T >
void Interface< T >::option() //функция выбора опции работы с данными
{
	T obj; //создаем объект для вызова функций его класса

	char filename[30], choice_1; //имя файла, где хранится (будет храниться) информация класса Т
	int choice_2; //для выбора номера редактируемого/удаляемого элемента
	bool flag_1, flag_2, file = false, change = false; //file знает был ли открыт файл, change - изменялась ли информация

	do
	{
		flag_1 = false;

		system("cls");
		blue cout << "1.Open file with data" << endl;
		cout << "2.Add object" << endl;
		cout << "3.Show all objects" << endl;
		cout << "4.Search object by parameter" << endl;
		cout << "5.Sort objects by parameter" << endl;
		cout << "6.Save changes" << endl;
		if (role) //опции, доступные только администратору
		{
			cout << "7.Edit object" << endl;
			cout << "8.Delete object" << endl;
		}
		cout << "0.Return to main menu" << endl;

		cin >> choice_1;

		switch (choice_1)
		{
		case '1':
		{
			if (!queue.isEmpty())
			{
				if (saveCheck()) saveToFile(obj, file, filename); //спрсит сохранить ли активную информацию перед открытием файла
				queue.~Queue(); //очистка очереди
				Queue< T > n_queue; //создание новой очереди
				queue = n_queue; //присвоение очереди, объявленной в интерфейсе, новой
			}
			file = true; //файл открыт
			change = false; //изменений с полученной из файла информацией пока не производилось
			openFile(obj, filename); //функция открытия файла, имя передается по указателю
			break;
		}
		case '2':
		{
			change = true;
			if (queue.isEmpty()) obj.fillContestName(); //если данных в очереди нет, то вписать название конкурса
			T n_obj; //создаем и заполняем новый объект
			cin >> n_obj;
			queue.enqueue(n_obj); //добавляем созданный объект в очередь
			green cout << "New object was successfully added!" << endl;
			break;
		}
		case '3':
		{
			orange cout << "\nThe objects of contest \"" << obj.getContestName() << "\" are:" << endl; //выводим информацию по данному конкурсу
			queue.printQueue();
			break;
		}
		case '4':
		{
			if (queue.isEmpty()) { red cout << "\nCan't search! The queue is empty!" << endl; }
			else
			{
				T n_obj;
				if (obj.search(n_obj)) queue.search(n_obj); //заполняем поля нового объекта данными, которые хотим найти
				else continue;								//и передаем его в функцию поиска в очереди
			}
			break;
		}
		case '5':
		{
			if (queue.isEmpty()) { red cout << "\nCan't sort! The  queue is empty!" << endl; }
			else
			{
				if (obj.sort(obj.getId())) queue.sort(); //если хотим воспользоваться сортировкой - сортируем
				else continue;
			}
			break;
		}
		case '6':
		{
			if (queue.isEmpty()) { red cout << "\nThere is no data to save!" << endl; }
			else
			{
				change = false; //изменения после сохранения пока не производились
				saveToFile(obj, file, filename); //функция сохранения информации
			}
			break;
		}
		case '7':
		{
			if (!role)
			{
				red cout << "Wrong input! Try again." << endl;
				break;
			}
			if (queue.isEmpty()) { red cout << "\nThere is no information!" << endl; }
			else do
			{
				flag_2 = false;

				yellow cout << "Choose who do you want to edit: " << endl;
				queue.objectList(); //вывести список объектов по фамилии/юридическому имени

				cin >> choice_2;
				if (choice_2 < 1 || choice_2 > queue.getSize())
				{
					red cout << "\nWrong input! Try again." << endl;
					flag_2 = true;
				}
				else if (queue.objectEdit(--choice_2)) change = true; //передаем порядковый номер объекта, который хотим изменить
			} while (flag_2);
			continue;
		}
		case '8':
		{
			if (!role)
			{
				red cout << "Wrong input! Try again." << endl;
				break;
			}
			if (queue.isEmpty()) { red cout << "\nThere is no information!" << endl; }
			else do
			{
				flag_2 = false;

				yellow cout << "Choose who do you want to delete: " << endl;
				queue.objectList(); //вывести список объектов по фамилии/юридическому имени

				cin >> choice_2;
				if (choice_2 < 1 || choice_2 > queue.getSize())
				{
					red cout << "\nWrong input! Try again." << endl;
					flag_2 = true;
				}
				else
				{
					change = true;
					queue.objectDelete(--choice_2); //передаем порядковый номер объекта, который хотим удалить
					green cout << "Object was successfully deleted." << endl;
				}
			} while (flag_2);
			break;
		}
		case '0':
		{
			if (change && saveCheck()) saveToFile(obj, file, filename); //если есть несохраненная информация, спросить сохранить ли ее
			else continue;
			break;
		}
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			flag_1 = true;
		}
		}
		if (choice_1 - 48 >= 3 && choice_1 - 48 <= 5) //для функций просмотра, поиска и сортировки
		{
			purple cout << "\nPress any key to continue...";
			_getch();
			continue;
		}
		Sleep(1500); //приостановить выполнение программы для вывода сообщений
	} while (choice_1 != '0' || flag_1);
}
//-------------------------------------------------------------------------------------
template< class T >
void Interface< T >::users_menu() //меню работы с пользователями, аналогично option()
{
	T obj;

	char choice_1;
	int choice_2;
	bool flag_1, flag_2, change = false;

	do
	{
		flag_1 = false;

		system("cls");
		blue cout << "1.Add a new user" << endl;
		cout << "2.Show all users" << endl;
		cout << "3.Edit user data" << endl;
		cout << "4.Delete user" << endl;
		cout << "0.Back to main menu" << endl;

		cin >> choice_1;

		switch (choice_1)
		{
		case '1':
		{
			change = true;
			cin >> obj;
			queue.enqueue(obj);
			green cout << "\nNew user has been successfully added." << endl;
			break;
		}
		case '2':
		{
			orange cout << "List of users:" << endl;
			queue.printQueue();
			purple cout << "\nPress any key to continue...";
			_getch();
			continue;
		}
		case '3':
		{
			do
			{
				flag_2 = false;

				yellow cout << "Choose the user you want to edit: " << endl;
				queue.objectList();

				cin >> choice_2;
				if (choice_2 < 1 || choice_2 > queue.getSize())
				{
					red cout << "\nWrong input! Try again." << endl;
					flag_2 = true;
				}
				else
				{
					if (queue.objectEdit(--choice_2)) change = true;
					else users_menu();
				}
			} while (flag_2);
			break;
		}
		case '4':
		{
			do
			{
				flag_2 = false;

				yellow cout << "Choose the user you want to delete: " << endl;
				queue.objectList();

				cin >> choice_2;
				if (choice_2 < 1 || choice_2 > queue.getSize())
				{
					red cout << "\nWrong input! Try again." << endl;
					flag_2 = true;
				}
				else
				{
					change = true;
					queue.objectDelete(--choice_2);
					green cout << "User was successfully deleted." << endl;
				}
			} while (flag_2);
			break;
		}
		case '0':
		{
			if (change) saveToFile();
			continue;
		}
		default:
		{
			red cout << "Wrong input! Try again." << endl;
			flag_1 = true;
		}
		}
		Sleep(1500);
	} while (choice_1 != '0' || flag_1);
}
//-------------------------------------------------------------------------------------
template< class T >
void Interface< T >::authorization()
{
	int num_of_users = strcount(u_filename); //узнать количество пользователей, записанных в файле

	if (!num_of_users) //если пользователи не найдены, зайти в режиме администратора
	{
		purple cout << "No accounts were found. Entering as admin..." << endl;
		Sleep(1500);
		role = 1;
		menu();
	}
	else
	{
		char login[30], password[30], temp[65];
		bool flag_1, flag_2;
			
		ifstream file(u_filename); //создаем поток для чтения из файла
		
		for (int i = 0; i < num_of_users; ++i)
		{
			file.getline(temp, 65); //считываем строку из файла
			queue.enqueue(T::fill(temp)); //статическая функция fill создаст объект, заполненит его поля и вернет этот объект 
		}

		file.close(); //закрываем поток

		do
		{
			flag_1 = false;

			yellow cout << "Enter your login: ";
			cin.getline(login, 30);

			if (queue.isLoginCorrect(login)) //проверка существования логина
			{
				do
				{
					flag_2 = false;
					int r;

					yellow cout << "Enter your password: ";
					cin.getline(password, 30);

					if (queue.isPasswordCorrect(password, r)) //проверка правильности ввода пароля, в r запишется роль вошедшего пользователя
					{
						purple cout << "\nWelcome, user " << login << "!" << endl;
						Sleep(1500);
						role = r; //заносим роль авторизовавшегося пользователя
						menu(); //вызов главного меню
					}
					else
					{
						red cout << "\nWrong password! Try again." << endl;
						flag_2 = true;
					}
				} while (flag_2);
			}
			else
			{
				red cout << "\nThere are no users with such login. Try again." << endl;
				flag_1 = true;
			}
		} while (flag_1);
	}
}
//----------------------------------------------------------------------------------
template< class T >
int Interface< T >::strcount(const char* filename) const //функция подсчета строк в файле, имя которого является аргументом
{
	int count = 0;
	char temp[200];

	ifstream file(filename); //создаем поток для чтения из файла

	if (!file.is_open()) //если не удалось открыть файл
	{
		red cout << "Unable to open file " << filename << endl;
		return 0;
	}
	else while (!file.eof()) //пока указатель не достигнет конца файла
	{
		file.getline(temp, 200);
		count++;
	}

	file.close();

	return count - 1; //возвращаем количество строк - 1
}
//----------------------------------------------------------------------------------
template< class T >
void Interface< T >::openFile(T& obj, char* filename) //функция открытия файла
{
	char temp[200];
	int num;
	
	yellow cout << "Enter the name of a file you want to open: ";
	cin.ignore();
	cin.getline(filename, 30);

	if (!strstr(filename, ".txt")) strcat_s(filename, strlen(filename) + 5, ".txt"); //если введенное имя файла не содержит расширения, добавить его

	if (num = strcount(filename)) //если в файле есть хоть одна запись
	{
		ifstream file(filename); //открываем поток для чтения из файла
		
		for (int i = 0; i < num; ++i) //пока не закончатся записи
		{
			file.getline(temp, 200); //считать строку из файла
			
			if (!i) //если первая строка файла, занести ее как название конкурса
			{
				obj.setContestName(temp);
				continue;
			}
			
			queue.enqueue(obj.fill(temp));	//добавить заполненный объект в очередь
		}
		green cout << "\nThe file was opened successfully!" << endl;

		file.close();
	}
	else { red cout << "\nFailed to load data." << endl; }
}
//-------------------------------------------------------------------------------------
template< class T >
void Interface< T >::saveToFile() const
{
	ofstream file; //создаем поток для записи в файл
	file.open(u_filename, ios::trunc); //чистим файл пользователей

	for (int i = 0; i < queue.getSize(); ++i) //пока не закончится очередь
	{
		T obj = queue.getObject(); //получаем объект из очереди

		file << obj.getUserName() << " " << obj.getPassword() << " " << obj.getRole() << endl; //заносим данные объекта в файл
	}

	file.close();
}
//-------------------------------------------------------------------------------------
template< class T >
void Interface< T >::saveToFile(T& obj, const bool isFileOpen, char* filename) const
{
	if (!isFileOpen) //если файл не был открыт до этого
	{
		yellow cout << "You don't have any file opened. \nEnter the name for a new file: ";
		cin.ignore();
		cin.getline(filename, 30);
		if (!strstr(filename, ".txt")) strcat_s(filename, strlen(filename) + 5, ".txt");
	}
	
	ofstream file;
	file.open(filename, ios::trunc);

	file << obj.getContestName() << endl; //записываем в первую строку файла название конкурса

	for (int i = 0; i < queue.getSize(); ++i)
		obj.save(queue.getObject(), file);

	file.close();

	green cout << "\nYour information was saved successfully!" << endl;
}
//-------------------------------------------------------------------------------------
template< class T >
bool Interface< T >::saveCheck() const //функция спрашивает хочет ли пользователь сохранить информацию
{
	char choice;
	bool flag;

	do
	{
		flag = false;

		purple cout << "You have unsaved data! Do you want to save it? (1 - Yes, 2 - No)" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1': return true;
		case '2':
		{
			return false;
		}
		default:
		{
			red cout << "\nWrong input! Try again." << endl;
			flag = true;
		}
		}
	} while (flag);

	return true;
}