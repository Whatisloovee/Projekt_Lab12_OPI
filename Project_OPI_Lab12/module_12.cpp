#include <iostream>
#include <windows.h> 

using namespace std;

void module_12()
{
	setlocale(LC_CTYPE, "ru");
	int sec, min, hour;
	cout << "Введите часы: ";
	cin >> hour;
	cout << endl;
	cout << "Введите минуты: ";
	cin >> min;
	cout << endl;
	cout << "Введите секунды: ";
	cin >> sec;
	while (true)
	{
		system("cls");	//Очистка экрана консоли
		cout << endl << "	  " << "Таймер запущен: ";
		cout << endl << endl << "	    " << hour << " : " << min << " : " << sec;
		Sleep(1000);	//задержка на одну секунду
		if (sec > 0) {
			sec--;
		}
		else if (sec == 0 && min > 0) {
			min--;
			sec = 59;	//обновление счётчика секуднд
		}
		else if (sec == 0 && min == 0 && hour > 0) {
			hour--;
			min = 59;	//обновление счётчика минут и секунд
			sec = 59;
		}
		else if (sec == 0 && min == 0 && hour == 0) {
			system("cls");
			cout << endl << endl << "	" << "Время вышло!!!" << endl << endl;
			break;
		}
	}
}