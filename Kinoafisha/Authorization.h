#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
int menuNum;

class User
{
private:
	//Аргументы
	string Login, Pass;
	fstream log;
	fstream pass;
	string login = "login.txt";
	string password = "password.txt";
public:
	//Default constructor means basic arguments initalizations
	User()
	{
		this->Login = Login;
		this->Pass = Pass;
#ifdef If  
		cout << "Конструктор по умолчанию " << this << endl << endl;
#endif
	}
	//Destructor
	~User()
	{
#ifdef If
		cout << "Деструктор " << this << endl;
#endif
	}
	
	//Setter (cin >> )
	string SetPass(string NewPass)
	{
		ifstream fin;
		fin.open(password);
		if (!fin.is_open())
		{
			cout << "Ошибка!" << endl;
		}
		else
		{
			vector<string>Vect;
			string Temp;
			while (!fin.eof())
			{
				Temp = "";
				fin >> Temp;
				Vect.push_back(Temp);
				for (auto i : Vect)
				{
					if (i == Pass) replace(Vect.begin(), Vect.end(), Pass, NewPass);
				}
			}
			fin.close();

			ofstream out("password.txt");
			for (auto i : Vect)
			{
				out << i << endl;
			}
			out.close();

			return Pass;
		}
	}

	//Print user data
	void Print()
	{
		cout << "Мій кабінет" << endl;
		cout << "Логін: " << Login << "\t";
		cout << "Пароль: " << Pass << endl << endl;
		std::cout << "1.Змінити пароль. " << std::endl;
		std::cout << "2.Мої квитки. " << std::endl;
		std::cout << "3.Вихід " << std::endl;

	}


		void Logcheker(fstream &log,fstream &pass)
		{
			string Pass_search = "";
			string Log_search = "";
			string str;
			vector <string> ArrLog;
			vector <string> ArrPass;
			if (!log.is_open() && !pass.is_open())
			{
				cout << "Ошибка!" << endl;
			}
			else
			{
				cout << "Введите свой логин: ";
				cin.ignore();
				getline(cin, Log_search);
				while (log >> str)
				{
					ArrLog.push_back(str);
				}
					str = "";
					cout << "Введите пароль: ";
					getline(cin, Pass_search);
					while (pass >> str)
					{
						ArrPass.push_back(str);
					}	
					Login = Log_search;
					Pass = Pass_search;
			}
			if (ArrLog[0] == Log_search && ArrPass[0] == Pass_search)
			{
				cout << "Данные введены верно!" << "Вы вошли как админ " << endl;
				Sleep(1000);
				system("cls");
				HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED );
				menuNum = 1;
	
			}
			else if (ArrLog[1] == Log_search && ArrPass[1] == Pass_search)
			{
				cout << "Данные введены верно!" <<"Вы вошли как менеджер" << endl;
				Sleep(1000);
				system("cls");
				HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_GREEN);
				menuNum = 2;
			}
			else if (ArrLog[2] == Log_search && ArrPass[2] == Pass_search)
			{
				cout << "Данные введены верно!" << "Вы вошли как пользователь" << endl;
				Sleep(1000);
				system("cls");
				HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE );
				menuNum = 3;
			}
			else if (ArrLog[3] == Log_search && ArrPass[3] == Pass_search)
			{
				cout << "Данные введены верно!" << " Но он выходит за лимит аккаунтов." << endl;
				Sleep(2000);
				system("cls");
				exit(0);
			}
			else
			{
				cout << "Пароль или логин введен не правильно!" << endl;
				Sleep(1000);
				system("cls");
				exit(0);
			}
		}

		

	int Entrance()
	{
		log.open(login, fstream::in | fstream::out | fstream::app);
		pass.open(password, fstream::in | fstream::out | fstream::app);
		
		if (!log.is_open() && !pass.is_open())
		{
			cout << "Ошибка!" << endl;
		}
		else
		{
			Logcheker(log,pass);
			log.close();
			pass.close();
			return 0;
		}
	}
	int Sign_up()
	{
		log.open(login, fstream::in | fstream::out | fstream::app);
		pass.open(password, fstream::in | fstream::out | fstream::app);

		if (!log.is_open() && !pass.is_open())
		{
			cout << "Ошибка!" << endl;
		}
		else
		{
			string log_cheker;
			string pass_cheker;
			cout << "Введите свой логин: "; cin >> log_cheker;
			cout << "Введите пароль: "; cin >> pass_cheker;
			log << endl;
			log << log_cheker;
			pass << endl;
			pass << pass_cheker;

			cout << "Регистрация прошла успешно!" << endl;
			Sleep(1000);
			system("cls");
			log.close();
			pass.close();
			RunMenu();
			return 0;

		}
	}
	int RunMenu()
	{
		int punkt;
		cout << "Добро пожаловать!" << endl;
		cout << "1.Вход" << endl;
		cout << "2.Регистрация" << endl;
		cin >> punkt;

		if (punkt != 1 && punkt != 2)
		{
			cout << "Выбран неверный пункт меню!" << endl;
		}
		if (punkt == 1)
		{
			system("cls");
			Entrance();
		}
		if (punkt == 2)
		{
			system("cls");
			Sign_up();
		}
		return 0;
	}

};

class Ticket
{
private:
	vector<string> films;
	vector<string> ticket;
	int num;

public:
	void Seans()
	{
		int punktTime;
		vector<int>Time;
		cout << "Доступні сенси:" << endl;
		for (int i = 0; i < 6; ++i)
		{
			Time.push_back(rand() % 21 + rand() % 10);
		}
		sort(Time.begin(), Time.end());
		for (int  j = 0; j < 3; ++j)
		{
			cout << j + 1 << ". " << Time[j] << ":00  " << "  " << j + 4 << ". " << Time[j + 2] + 1 << ":" << rand() % 30 + 29 << endl;
		}
	}

	void number(const int x)
	{
		string a;
		int punkt,punktTime;
		switch (x)
		{
		case 1:
		{
			cout << "В горах Колумбии раскинулся живописный городок. Здесь живет большая дружная семья Мадригалов. Каждый член семьи имеет свои уникальные волшебные способности. Единственное исключение в семье – девочка Мирабель." << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin,a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 2:
		{
			cout << "Жизнь и репутация Питера Паркера оказываются под угрозой, поскольку Мистерио раскрыл всему миру тайну личности Человека-паука. Пытаясь исправить ситуацию, Питер обращается за помощью к Стивену Стрэнджу, но вскоре всё становится намного опаснее." << endl; 
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1) 
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 3:
		{
			cout << "В основу сюжета картины легла книга Сары Гей Форден «Дом Gucci: Сенсационная история убийства, безумия, гламура и алчности». Речь в фильме пойдёт об убийстве бизнесмена Маурицио Гуччи в 1995 году. По версии следствия, организовала преступление бывшая супруга Маурицио Патриция Реджани." << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 4:
		{
			cout << "Новая часть фантастических приключений из оригинальной вселенной Охотников за привидениями! Унаследовав старый заброшенный дом, семья переезжает в маленький городок. Их появление совпадает по времени с необычайной активностью паранормальных сил, которые переворачивают привычную жизнь с ног на голову." << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 5:
		{
			cout << "Шесть историй — пять реинкарнаций, происходящих в разное время, тесно переплетаются между собой… Основная идея «Облачного атласа» в том, что человеческая душа бессмертна.Все герои, которых играет один актёр — это реинкарнации одной души.У души нет пола и расы, поэтому в некоторых историях актёры появляются в неожиданных ролях." << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 6:
		{
			cout << "Что делать, если в доме поселилось настоящее исчадие ада, а именно два подростка? Срочно планировать самый жуткий отпуск! Мартиша, Гомес, Уэнсдей, Пагсли и дядя Фестер загружаются в семейный походный катафалк, чтобы отправиться навстречу новым приключениям и чудаковатым друзьям, от которых волосы встанут дыбом. " << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 7:
		{
			cout << "Любовное письмо журналистам, размещенное на форпосте американской газеты в вымышленном французском городе 20-го века, которое воплощает в жизнь сборник рассказов, опубликованных в «The French Dispatch»." << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 8:
		{
			cout << "Вечные — представители расы генетически улучшенных суперлюдей, тайно живущих на Земле. Они появились на свет 5 миллионов лет назад в результате экспериментов могущественных целестиалов. " << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 9:
		{
			cout << "Луи Уэйн за свою невероятную жизнь был многим: художником, изобретателем, предпринимателем и смотрителем. После того, как он усыновил бездомного котенка, он продолжил рисовать необычные изображения кошек, которые сделали его всемирно известным." << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 10:
		{
			cout << "Кратковременный покой Бонда прерывает новое срочное задание, где ставки снова слишком высоки. Суперагент бросает вызов самым влиятельным игрокам преступного мира и разоблачает коварные заговоры. Пора сойтись в противостоянии с таинственным злоумышленником, который обладает новыми опасными технологиями." << endl;
			Seans();
			cout << "Купити квиток" << endl;
			cout << "1.Так" << "\t 2.Ні" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "На який сеанс?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "Квиток буде коштувати 120 грн.";
				cin.ignore();
				getline(cin, a);
				cout << "Обробка транзакції..." << endl;
				Sleep(2000);
				cout << "Ви придбали квиток на фільм " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		}
		system("cls");
	}

	void BuyTicket()
	{
		string str;
		fstream fs;
		string path = "kinoafisha.txt";
		fs.open(path, fstream::in | fstream::out | fstream::app);
		

		if (!fs.is_open())
		{
			cout << "Error" << endl;
		}
		else
		{
			
			while (getline(fs,str))
			{
				films.push_back(str);
			}
			for (int r = 0; r < films.size(); r++)
			{

				cout << r+1 << ". " << films[r] << endl;
			}

			cout << endl;
			cout << "Выберите фильм описание которого хотите посмотреть: ";
			cin >> num;
			number(num);
			films.clear();
		}
		fs.close();
	}
	void MyTickets()
	{
		cout << "Ваши билеты: " << endl;
		for (int i = 0; i < ticket.size(); i++)
		{
			cout << i+1 << ". " << ticket[i] << endl;
		}
	
	}
};


