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
	//���������
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
		cout << "����������� �� ��������� " << this << endl << endl;
#endif
	}
	//Destructor
	~User()
	{
#ifdef If
		cout << "���������� " << this << endl;
#endif
	}
	
	//Setter (cin >> )
	string SetPass(string NewPass)
	{
		ifstream fin;
		fin.open(password);
		if (!fin.is_open())
		{
			cout << "������!" << endl;
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
		cout << "̳� ������" << endl;
		cout << "����: " << Login << "\t";
		cout << "������: " << Pass << endl << endl;
		std::cout << "1.������ ������. " << std::endl;
		std::cout << "2.�� ������. " << std::endl;
		std::cout << "3.����� " << std::endl;

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
				cout << "������!" << endl;
			}
			else
			{
				cout << "������� ���� �����: ";
				cin.ignore();
				getline(cin, Log_search);
				while (log >> str)
				{
					ArrLog.push_back(str);
				}
					str = "";
					cout << "������� ������: ";
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
				cout << "������ ������� �����!" << "�� ����� ��� ����� " << endl;
				Sleep(1000);
				system("cls");
				HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED );
				menuNum = 1;
	
			}
			else if (ArrLog[1] == Log_search && ArrPass[1] == Pass_search)
			{
				cout << "������ ������� �����!" <<"�� ����� ��� ��������" << endl;
				Sleep(1000);
				system("cls");
				HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_GREEN);
				menuNum = 2;
			}
			else if (ArrLog[2] == Log_search && ArrPass[2] == Pass_search)
			{
				cout << "������ ������� �����!" << "�� ����� ��� ������������" << endl;
				Sleep(1000);
				system("cls");
				HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE );
				menuNum = 3;
			}
			else if (ArrLog[3] == Log_search && ArrPass[3] == Pass_search)
			{
				cout << "������ ������� �����!" << " �� �� ������� �� ����� ���������." << endl;
				Sleep(2000);
				system("cls");
				exit(0);
			}
			else
			{
				cout << "������ ��� ����� ������ �� ���������!" << endl;
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
			cout << "������!" << endl;
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
			cout << "������!" << endl;
		}
		else
		{
			string log_cheker;
			string pass_cheker;
			cout << "������� ���� �����: "; cin >> log_cheker;
			cout << "������� ������: "; cin >> pass_cheker;
			log << endl;
			log << log_cheker;
			pass << endl;
			pass << pass_cheker;

			cout << "����������� ������ �������!" << endl;
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
		cout << "����� ����������!" << endl;
		cout << "1.����" << endl;
		cout << "2.�����������" << endl;
		cin >> punkt;

		if (punkt != 1 && punkt != 2)
		{
			cout << "������ �������� ����� ����!" << endl;
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
		cout << "������� �����:" << endl;
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
			cout << "� ����� �������� ���������� ���������� �������. ����� ����� ������� ������� ����� ����������. ������ ���� ����� ����� ���� ���������� ��������� �����������. ������������ ���������� � ����� � ������� ��������." << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin,a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 2:
		{
			cout << "����� � ��������� ������ ������� ����������� ��� �������, ��������� �������� ������� ����� ���� ����� �������� ��������-�����. ������� ��������� ��������, ����� ���������� �� ������� � ������� ��������, �� ������ �� ���������� ������� �������." << endl; 
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1) 
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 3:
		{
			cout << "� ������ ������ ������� ����� ����� ���� ��� ������ ���� Gucci: ������������ ������� ��������, �������, ������� � ��������. ���� � ������ ����� �� �������� ���������� �������� ����� � 1995 ����. �� ������ ���������, ������������ ������������ ������ ������� �������� �������� �������." << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 4:
		{
			cout << "����� ����� �������������� ����������� �� ������������ ��������� ��������� �� ������������! ����������� ������ ����������� ���, ����� ���������� � ��������� �������. �� ��������� ��������� �� ������� � ����������� ����������� �������������� ���, ������� �������������� ��������� ����� � ��� �� ������." << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 5:
		{
			cout << "����� ������� � ���� ������������, ������������ � ������ �����, ����� ������������� ����� ����� �������� ���� ���������� ������ � ���, ��� ������������ ���� ����������.��� �����, ������� ������ ���� ���� � ��� ������������ ����� ����.� ���� ��� ���� � ����, ������� � ��������� �������� ����� ���������� � ����������� �����." << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 6:
		{
			cout << "��� ������, ���� � ���� ���������� ��������� ������� ���, � ������ ��� ���������? ������ ����������� ����� ������ ������! �������, �����, �������, ������ � ���� ������ ����������� � �������� �������� ��������, ����� ����������� ��������� ����� ������������ � ����������� �������, �� ������� ������ ������� �����. " << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 7:
		{
			cout << "�������� ������ �����������, ����������� �� �������� ������������ ������ � ����������� ����������� ������ 20-�� ����, ������� ��������� � ����� ������� ���������, �������������� � �The French Dispatch�." << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 8:
		{
			cout << "������ � ������������� ���� ����������� ���������� ����������, ����� ������� �� �����. ��� ��������� �� ���� 5 ��������� ��� ����� � ���������� ������������� �������������� �����������. " << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 9:
		{
			cout << "��� ���� �� ���� ����������� ����� ��� ������: ����������, �������������, ���������������� � �����������. ����� ����, ��� �� �������� ���������� �������, �� ��������� �������� ��������� ����������� �����, ������� ������� ��� �������� ���������." << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
				Sleep(1000);
				break;
			}
			else break;
		}
		case 10:
		{
			cout << "��������������� ����� ����� ��������� ����� ������� �������, ��� ������ ����� ������� ������. ���������� ������� ����� ����� ����������� ������� ����������� ���� � ����������� �������� ��������. ���� ������� � �������������� � ������������ ���������������, ������� �������� ������ �������� ������������." << endl;
			Seans();
			cout << "������ ������" << endl;
			cout << "1.���" << "\t 2.ͳ" << endl;
			cin >> punkt;
			if (punkt == 1)
			{
				cout << "�� ���� �����?" << endl;
				cin >> punktTime;
				ticket.push_back(films[x - 1]);
				cout << "������ ���� ��������� 120 ���.";
				cin.ignore();
				getline(cin, a);
				cout << "������� ����������..." << endl;
				Sleep(2000);
				cout << "�� �������� ������ �� ����� " << films[x - 1] << endl;
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
			cout << "�������� ����� �������� �������� ������ ����������: ";
			cin >> num;
			number(num);
			films.clear();
		}
		fs.close();
	}
	void MyTickets()
	{
		cout << "���� ������: " << endl;
		for (int i = 0; i < ticket.size(); i++)
		{
			cout << i+1 << ". " << ticket[i] << endl;
		}
	
	}
};


