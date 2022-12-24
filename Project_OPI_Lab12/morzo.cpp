#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<string.h>
#include<cctype>
using namespace std;

//не таой уж и главный модуль
int mor_rus(string script[32], string numbers[10], HANDLE h);
int rus_mor(string script[32], string numbers[10], HANDLE h);
//главный модуль
void morzo()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	//стартовые переменные
	int version{};
	string script[32] = { ". -","- . . .",". - -","- - .","- . .",".",". . . -","- - . .",". .",". - - -","- . -",". - . .","- -","- .","- - -",". - - .",". - .",". . .","-",". . -",". . - .",". . . .","- . - .","- - - .","- - - -","- - . -",". - - . - .","- . - -","- . . -",". . . - . . .",". . - -",". - . -" }, numbers[10] = { "- - - - -",". - - - -",". . - - -",". . . - -",". . . . -",". . . . .","- . . . .","- - . . .","- - - . .","- - - - ." };

	//руский на морзо
	SetConsoleTextAttribute(h, 12);
	cout << "       Русский\t ||\tАзбука Морзе" << endl;
	cout << setw(40) << setfill('-') << "" << endl;
	for (int i = 0, t = 224; i < 32; i++, t++)
	{
		cout << "\t| " << (char)t << "\t || \t" << script[t - 224] << " |" << endl;
		cout << setw(40) << setfill('-') << "" << endl;
	}

	//цифры на морзо
	SetConsoleTextAttribute(h, 11);
	cout << "\n      Цифры |\t|Азбука Морзе|" << endl;
	cout << setw(30) << setfill('-') << "" << endl;
	for (int i = 0, t = 48; i < 10; i++, t++)
	{
		cout << "\t| " << (char)t << " |\t| " << numbers[t - 48] << " |" << endl;
		cout << setw(30) << setfill('-') << "" << endl;
	}
	SetConsoleTextAttribute(h, 15);

	cout << "\n\n\n";
	cout << setw(70) << setfill('=') << "" << endl;
	cout << setw(70) << setfill('=') << "" << endl;
	cout << "\t\t     Выберите вариант\n(1-с русского на морзо; 2-с морзо на русский; других не дано): ";
	//выбор модуя продолжение	
	cin >> version;
	switch (version)
	{
	case 1:
		SetConsoleTextAttribute(h, 10);
		rus_mor(script, numbers, h);
		break;

	case 2:
		SetConsoleTextAttribute(h, 5);
		mor_rus(script, numbers, h);
		break;

	default:
		cout << "\n\nЯ кажеться на руском сказал что варианта только 2 \n(? _ ?)";
		break;
	}
	cout << "\n\n\n";
	SetConsoleTextAttribute(h, 15);
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|ИЗ РУССКОГО В МОРЗО|&&&&&&&&&&&&&&&&&&&&&&&
int rus_mor(string script[32], string numbers[10], HANDLE h)
{
	char text[99999];
	int limit{}, help{};
	bool end = false;

	cout << "Введите предложение на русском что бы зашифроват его на языке морзо(только руские символы и цифры)" << endl;
	gets_s(text);
error:;
	gets_s(text);
	limit = strlen(text);
	//проверка на соблюдение условий
	for (int i = 0; i < limit; i++)
	{
		if (text[i] == ' ')
			continue;
		else if ((int)text[i] >= 48 && (int)text[i] <= 57)
			continue;
		else if ((int)text[i] >= -64 && (int)text[i] <= -33)
			text[i] = tolower(text[i]);

		else if ((int)text[i] > -1 || (int)text[i] < -32)
		{
			cout << "В предложении могу быть только руские символы и цифры. Попробуй снова" << endl;
			goto error;
		}
	}
	//процес шифрования
	cout << "Выберите вариант\n1-быстрое шифрование 2-шифрование с обяснением:";
	while (!end)
	{
		cin >> help;
		SetConsoleTextAttribute(h, 1);
		switch (help)
		{
			//быстрый шифр
		case 1:
			for (int i = 0; i < limit; i++)
			{
				if (text[i] == ' ')
					cout << " /";
				else if ((int)text[i] <= -1 && (int)text[i] >= -32)
					cout << script[(int)text[i] + 32] << "/";
				else if ((int)text[i] >= 48 && (int)text[i] <= 57)
					cout << numbers[(int)text[i] - 48] << "/";
				if ((i + 1) % 19 == 0)
					cout << endl;
			}
			end = true;
			break;
			//шифр с обьяснением 
		case 2:
			//обяснение
			for (int i = 0; i < limit; i++)
			{
				if (text[i] == ' ')
					cout << "пробел = ( /)" << endl << endl;
				else if ((int)text[i] <= -1 && (int)text[i] >= -32)
					cout << text[i] << " = " << script[(int)text[i] + 32] << "/" << endl << endl;
				else if ((int)text[i] >= 48 && (int)text[i] <= 57)
					cout << text[i] << " = " << numbers[(int)text[i] - 48] << "/" << endl;
			}
			//быстрый вывод ибо нефиг
			for (int i = 0; i < limit; i++)
			{
				if (text[i] == ' ')
					cout << " /";
				else if ((int)text[i] <= -1 && (int)text[i] >= -32)
					cout << script[(int)text[i] + 32] << "/";
				else if ((int)text[i] >= 48 && (int)text[i] <= 57)
					cout << numbers[(int)text[i] - 48];
				if ((i + 1) % 19 == 0)
					cout << endl;
			}
			end = true;
			break;
			//проверка на плохих людей
		default:
			SetConsoleTextAttribute(h, 4);
			cout << "Такого шифрования нет уж сорян" << endl;
			break;
		}
	}
	return 0;
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&|ИЗ МОРЗО В РУССКИЙ|&&&&&&&&&&&&&&&&&&&&&&&&
int mor_rus(string script[32], string numbers[10], HANDLE h)
{
	char text[99999];
	string* sheefr{}, noName{};
	int limit{}, tick{};
	cout << "\n\nПравила заполненмия:\n1)ВСЕ зашифрование символы должны закрываться \"/\"\n2)Между точками и черточками в зашифровоном символе ОБЯЗАТЬЕЛЬНО нужен пробел, пример П=(. - - ./)\n\nТеперь можете ввести шифр:\n";
	gets_s(text);
goToHell:;
	gets_s(text);
	limit = strlen(text);
	//проверка условий
	for (int i = 0; i < limit; i++)
	{
		if (text[i] == '/')
			tick++;
		else if (text[i] == ' ' || text[i] == '.' || text[i] == '-') {}
		else
		{
			cout << "Так дела не шифруються, переписывай\n";
			goto goToHell;
		}
	}
	//разбитие шифра 
	sheefr = new string[tick];
	for (int i = 0, t = 0; i < limit; i++)
	{
		if (text[i] == '/')
			t++;
		else
			sheefr[t] += text[i];
	}
	//сверение с таблицей и вывод
	SetConsoleTextAttribute(h, 14);
	for (int i = 0, t = 0, m = 0; i < tick; i++)
	{
		m = 0;
		t = 0;
		if (sheefr[i] == " ")
			noName += " ";
		else
		{
			for (int j = 0; j < 32; j++)
			{
				if (sheefr[i] == script[j])
				{
					noName += (char)(j + 224);
					break;
				}
				else
					t++;
			}
		}
		if (t == 32)
		{
			for (int j = 0; j < 10; j++)
			{
				if (sheefr[i] == numbers[j])
				{
					noName += (char)(j + 48);
					break;
				}
				else
					m++;
			}
		}
		if (m == 10)
		{
			cout << "Есть шифр который не получиться раскодирорвать";
			break;
		}
	}
	cout << noName;
	//delete[] sheefr;
	return 0;
}