#include <iostream>
#include <Windows.h>
#include "Authorization.h" 

//#define If
//Working with file

//Global arguments
int num,num1;
fstream fs;
string path = "kinoafisha.txt";
Ticket ticket;
User user1;


void Read() 
{
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		string text;
		while (!fs.eof())
		{
			text = "";
			getline(fs,text);
			cout << text << endl;
		}
	}
	fs.close();
}
int Menu(int num)
{
	switch (num)
	{
	case 1:
	{
	Main:
		std::cout << "1. Мій кабінет " << std::endl;
		std::cout << "2. Кіноафіша " << std::endl;
		std::cout << "3. Редагувати програму" << std::endl;
		std::cout << "4. Выход " << std::endl;
		std::cin >> num;
		system("cls");
		switch (num)
		{
		case 1:
		{
			user1.Print();
			std::cin >> num1;
			system("cls");
			switch (num1)
			{
			case 1:
			{


				std::cout << "Новий пароль: " << std::endl;
				std::string a;
				std::cin >> a;
				user1.SetPass(a);
				std::cout << "Пароль успешно изменён, нажите кнопку для продолжения." << std::endl;
				system("pause>>nul");
				system("cls");
				break;
			}
			case 2:
			{
				ticket.MyTickets();
				system("pause>nul");
				system("cls");
				goto Main;
				break;
			}
			case 3:
			{

				system("cls");
				goto Main;
				break;
			}

			}
			system("cls");
			goto Main;
			break;
		}
		case 2:
		{
			int x;
			Read();
		Func:
			cout << "1. Описание фильмов" << endl;
			cout << "2. Выйти " << endl;
			cin >> x;
			if (x != 1 && x != 2)
			{
				cout << "Выбран неверный пункт меню!" << endl;
				goto Func;
			}
			if (x == 1)
			{
				system("cls");
				ticket.BuyTicket();
				goto Main;
			}
			if (x == 2)
			{
				system("cls");
				goto Main;
			}
		}
		case 3:
		{
			int punkt;
			cout << "Вы можете отредактировать киноафишу в файле kinoafisha.txt" << endl;
			cout << "1. Выход" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				system("cls");
				goto Main;
			}
		}
		case 4:
		{
			exit(0);
		}

		}
	}
	case 2:
	{
	Main2:
		std::cout << "1. Мій кабінет " << std::endl;
		std::cout << "2. Кіноафіша " << std::endl;
		std::cout << "3. Выход " << std::endl;
		std::cin >> num;
		system("cls");
		switch (num)
		{
		case 1:
		{
			user1.Print();
			std::cin >> num1;
			system("cls");
			switch (num1)
			{
			case 1:
			{


				std::cout << "Новий пароль: " ;
				std::string a;
				std::cin >> a;
				user1.SetPass(a);
				std::cout << "Пароль успешно изменён, нажите кнопку для продолжения." << std::endl;
				system("pause>>nul");
				system("cls");
				break;
			}
			case 2:
			{
				ticket.MyTickets();
				system("pause>nul");
				system("cls");
				goto Main2;
				break;
			}
			case 3:
			{

				system("cls");
				goto Main2;
				break;
			}

			}
			system("cls");
			goto Main2;
			break;
		}
		case 2:
		{
			int x;
			Read();
		Func2:
			cout << "1. Описание фильмов" << endl;
			cout << "2. Проверить кол-во проданных билетов " << endl;
			cout << "3. Выйти " << endl;
			cin >> x;
			if (x != 1 && x != 2)
			{
				cout << "Выбран неверный пункт меню!" << endl;
				goto Func2;
			}
			if (x == 1)
			{
				system("cls");
				ticket.BuyTicket();
				goto Main2;
			}
			if (x == 2)
			{
				int punkt;
				system("cls");
				cout << "Продали " << rand()%50+rand()%10+1 << " Билетов" <<endl;
				cout << "1. Выйти" << endl;
				cin >> punkt;
				if (punkt == 1)
				{
					system("cls");
					goto Main2;
				}
			}
			if (x == 3)
			{
				system("cls");
				goto Main2;
			}
		}
		case 3:
		{
			exit(0);
		}

		}
	}
	case 3:
	{
	Main3:
		std::cout << "1. Мій кабінет " << std::endl;
		std::cout << "2. Кіноафіша " << std::endl;
		std::cout << "3. Выход " << std::endl;
		std::cin >> num;
		system("cls");
		switch (num)
		{
		case 1:
		{
			user1.Print();
			std::cin >> num1;
			system("cls");
			switch (num1)
			{
			case 1:
			{


				std::cout << "Новий пароль: " << std::endl;
				std::string a;
				std::cin >> a;
				user1.SetPass(a);
				std::cout << "Пароль успешно изменён, нажите кнопку для продолжения." << std::endl;
				system("pause>>nul");
				system("cls");
				break;
			}
			case 2:
			{
				ticket.MyTickets();
				system("pause>nul");
				system("cls");
				goto Main3;
				break;
			}
			case 3:
			{

				system("cls");
				goto Main3;
				break;
			}

			}
			system("cls");
			goto Main3;
			break;
		}
		case 2:
		{
			int x;
			Read();
		Func3:
			cout << "1. Описание фильмов" << endl;
			cout << "2. Выйти " << endl;
			cin >> x;
			if (x != 1 && x != 2)
			{
				cout << "Выбран неверный пункт меню!" << endl;
				goto Func3;
			}
			if (x == 1)
			{
				system("cls");
				ticket.BuyTicket();
				goto Main3;
			}
			if (x == 2)
			{
				system("cls");
				goto Main3;
			}
		}
		case 3:
		{
			exit(0);
		}

		}
	}
	}
	return num;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	user1.RunMenu();
	Menu(menuNum);
	system("pause>null");
	return 0;
}