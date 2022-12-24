#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

void calendar()
{
	HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_ALL, "ru");
	int year{}, week{ 1 }, startYear{ 2001 }, day{ 1 }, location{ 0 },visDay{};
	cout << "Введите год:\t";
	cin >> year;
	const int MOUNTH = 12;
	string Month[MOUNTH] = { "Январь","Февраль","Март","Апрель","Май","Июнь","Июль","Август","Сеньтябрь","Октябрь","Ноябрь","Декабрь" };
	const int WEEK = 7;
	string WeekDay[WEEK] = { "пн", "вт", "ср", "чт", "пт", "сб", "вс" };
	const int DAY = 12;
	/*следующе это проверка на високосные года, ведь если год делится на 100 без остатка, то он также должен делится 
	и на 400 без остатка - тогда он считается високосным (данная проверка необходима для дат "столетий" с двумя нулями в конце) */
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400==0)
				visDay = 29;
			else
				visDay = 28;
		}
		else
			visDay = 29;
	}
	else
		visDay = 28;
	int MonthDay[DAY] = { 31,visDay ,31, 30, 31,30, 31, 31, 30, 31, 30, 31 };
    //Счёт годов которые находятся до 2001 г.
	if (startYear >= year)
	{
		for (int i = (startYear-1); i >= year; i--)
		{
			// Производится проверка на високосный год
			if (i % 4 == 0) {
				if (i % 100 == 0) {
					if (i % 400==0) 
						week -= 2;
					else
						week -= 1;
				}
				else
					week -= 2;
			}
			else
				week -= 1;
			//Выявление дня начала отчёта
			if (week == 0)
				week = 7;
			if (week == (-1))
				week = 6;
		}
	}
	//Счёт годов которые находятся после 2001 г.
	if (startYear < year)
	{
		for (int i = startYear; i < year; i++)
		{
			//Прозиводится проверка на високосный год
			if (i % 4 == 0) {
				if (i % 100 == 0) {
					if (i % 400==0)
						week += 2;
					else
						week += 1;
				}
				else
					week += 2;
			}
			else
				week += 1;
		//Выявление дня начала отчёта
		}
		if (week % 7 == 0)
			week = 7;
		else
		week = week % 7;
	}
	for (int i = 0; i < MOUNTH; i++)
	{
		//Вывод, определение расположения для месяцев и недель, а также указание их цвета
		cout << endl << endl << "			";
		SetConsoleTextAttribute(hColor, 14);
		cout<<Month[i] << endl << endl;
		for (int d = 0; d < WEEK; d++){
			cout << "    ";
			SetConsoleTextAttribute(hColor, 14);
			cout<<"|" << WeekDay[d] << "|" ;
		}
		cout << endl << endl;
		//Вывод, определение расположения для дней а также указание их цвета
		for (int j = 0; j < (week - 1); j++)
		{
			cout << "	";
		}
		location = (week - 1);
		for (int j = 0; j < MonthDay[i]; j++)
		{
			if (location == 5 && day < 10) {
				cout << "    ";
				SetConsoleTextAttribute(hColor, 11);
				cout << "|" << day << "|" << " ";
			}
			else if (location == 6) {
				cout << "    ";
				SetConsoleTextAttribute(hColor, 12);
				cout << "|" << day << "|";
			}
			else if (location == 5 && day >= 10) {
				cout << "    ";
				SetConsoleTextAttribute(hColor, 11);
				cout << "|" << day << "|";
			}
			else {
				cout << "     ";
				SetConsoleTextAttribute(hColor, 7);
				cout<< day << "	";
			}
			day++;
			location++;
			if (location == 7)
			{
				cout << endl << endl;
				location = 0;
			}
		}
		day = 1;
		week = location + 1;
	}
	cout << endl<<endl;
	SetConsoleTextAttribute(hColor, 7);
}