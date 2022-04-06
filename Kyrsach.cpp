#include <iostream>
#include <string>
#include <locale>
#include "windows.h"
#include <algorithm>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;

void Cezar_Sypher()
{
	cout << "Введіть слово: " << endl;
	cin.ignore();
	string s; int k;
	getline(cin, s);
	cout << "Введіть ключ (кількість сдвигів): " << endl;
	cin >> k;
	for (auto& c : s)
	{
		if (c >= 'а' && c <= 'я')
			c = ((c - 'а' + k) % 32) + 'а';
		else if (c >= 'А' && c <= 'Я')
			c = ((c - 'А' + k) % 32) + 'А';
	}

	cout << "Ваш шифр - " << s << endl;
	system("pause>nul");
	system("cls");
}

void Cezar_Desypher()
{
	cout << "Введіть слово для дешифровки: " << endl;
	cin.ignore();
	string s; int k;
	getline(cin, s);
	cout << "Введіть ключ (кількість сдвигів): " << endl;
	cin >> k;
	if (s >= "а" && s <= "z") //Доделать момент
		for (auto& c : s)
		{
			if (c >= 'a' && c <= 'z')
				c = ((c - 'a' + k) % 26) + 'a';
			else if (c >= 'A' && c <= 'Z')
				c = ((c - 'A' + k) % 26) + 'A';
		}
	for (auto& c : s)
	{
		if (c >= 'а' && c <= 'я')
			c = ((c - 'а' - k) % 32) + 'а';
		else if (c >= 'А' && c <= 'Я')
			c = ((c - 'А' - k) % 32) + 'А';
	}
	cout << "Ваше повідомлення - " << s << endl;
	system("pause>nul");
	system("cls");
}

void Twocode_Sypher()
{
	cout << "Введіть слово: ";
	cin.ignore();
	string s;
	int int_char, temp_int = 0;
	getline(cin, s);
	cout << endl;
	cout << "Ваш шифр - ";
	for (unsigned char ch : s)
	{
		int_char = int(ch);
		int k = 128; //k= 10000000b
		while (k > 0)
		{
			cout << bool(int_char&k); // печатаем нужный разряд.
			k = k >> 1; //сдвигаем k поразрядно вправо на 1.Что есть деление на 2
		}
		cout << " "; //Пробел между символами
	}
	system("pause>null");
	system("cls");

}
void Twocode_Desypher()
{
	vector <int> word10;
	string s;
	int temp_int = 0, x = 7;
	cout << "Введіть двійковий код: ";
	cin.ignore();
	getline(cin, s);
	for (unsigned char ch : s)
	{

		if (ch == '0')
		{
			temp_int += 0;
			--x;
			//cout << temp_int << endl;
		}
		if (ch == '1')
		{
			temp_int += 1 * pow(2, x);
			//cout << temp_int << endl;
			--x;

		}
		if (ch == ' ' || x == -1)
		{
			word10.push_back(temp_int);
			temp_int = 0;
			x = 7;
		}

	}
	cout << "Ваше повідомлення - ";
	for (int i = 0; i < word10.size(); i++)
	{
		cout << char(word10[i]);
	}
	system("pause>null");
	system("cls");
}

void A1Z26_Sypher()
{
	string s;
	int int_char, temp_int = 0;
	vector<unsigned char> alphabet;
	unsigned char temp_letter;
	cout << "Введіть слово: ";
	cin.ignore();
	getline(cin, s);
	cout << endl;

	for (auto ch = char(224); ch <= char(255); ch++)
	{
		temp_letter = ch;
		alphabet.push_back(ch);
	}

	cout << "Ваш шифр - ";
	temp_letter = s[s.size() - 1];
	for (unsigned char ch : s) //По каждой букве проходит цикл
	{
		unsigned char next = s[s.size()+2]; // цикл след буквы
		if (ch >= 32 && ch <= 63)
		{
			cout << ch;
		}
		for (int i = 0; i < alphabet.size(); ++i) //Сравнивает каждую букву с алфавита с текущей буквой загаданого слова и записывает в виде номера в алфавите
		{
			if (ch == temp_letter || next == char(32)) {

				if (int(alphabet[i]) == int(ch))
					cout << i + 1;
			}
			else if (int(alphabet[i]) == int(ch))
				cout << i + 1 << "-";
		}


	}
	system("pause>null");
	system("cls");
}

void A1Z26_Desypher()
{
	string s;
	int int_char;
	vector<unsigned char> alphabet;
	unsigned char temp_letter;
	string letter;
	cout << "Введіть слово: ";
	cin.ignore();
	getline(cin, s);
	cout << endl;

	s += "-";
	for (auto ch = 224; ch <= 255; ch++)
	{
		temp_letter = ch;
		alphabet.push_back(ch);
	}

	cout << "Ваше повідомлення - ";
	temp_letter = s[s.size() - 1];
	for (unsigned char ch : s) //По каждой букве проходит цикл
	{

		if (ch == char(45))
		{
			int_char = stoi(letter);
			for (int i = 0; i < alphabet.size(); ++i) //Сравнивает каждую букву с алфавита с текущей буквой загаданого слова и записывает в виде номера в алфавите
			{
				if (int_char == i)	cout << alphabet[i - 1];
			}
			letter.erase();
		}
		else letter += ch;

	}
	system("pause>null");
	system("cls");
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Ви увійшли у програму-шифрувальник." << endl;
Menu:
	string str;
	int k, x;
	cout << "Оберіть метод шифрування: " << endl;
	cout << "1. Шифр Цезаря" << endl << "2. Двійковий код" << endl << "3. Шифр A1Z26" << endl;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		system("cls");
		cout << "Виберіть один з варіантів: " << endl << "1. Шифровка" << endl << "2. Дешифровка" << endl;
		cin >> x;
		if (x == 1)
		{	
			Cezar_Sypher();
			goto Menu;
		}
		else if (x == 2)
		{
			Cezar_Desypher();
			goto Menu;
		}
	}

	case 2:
		{
		system("cls");
		cout << "Виберіть один з варіантів: " << endl << "1. Шифровка" << endl << "2. Дешифровка" << endl;
		cin >> x;
		if (x == 1) 
		{
			Twocode_Sypher();
			goto Menu;
		}
		else if (x == 2)
		{
			Twocode_Desypher();
			goto Menu;
		}
	}
	break;

	case 3:
	{
		system("cls");
		cout << "Виберіть один з варіантів: " << endl << "1. Шифровка" << endl << "2. Дешифровка" << endl;
		cin >> x;
		if (x == 1)
		{
			A1Z26_Sypher();
			goto Menu;
		}
		if (x == 2)
		{
			A1Z26_Desypher();
			goto Menu;
		}
	
	}

	} //Закрывает Switch()
	if (k > 3)
	{
		cout << "Такого варіанту не має";
		Sleep(100);
		system("cls");
		goto Menu;
	}
	cout << endl;

	system("pause>nul");
	return 0;
}

