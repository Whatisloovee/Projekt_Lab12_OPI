#include <iostream>

using namespace std;
int Shifr_Cezyar();
void calendar();
void module_9();
void module_12();
int main()
{
	setlocale(0, "");
	int choose;
	bool flag = true;
	cout << "Проект \"Солянка\"";
	do {
		cout << "\n\n1-Шифр Цезаря(шифрование и дешифрование). \n2-Вывод календаря на указанны год. \n3-Вывод расписания занятий на заданный день. \n4-Таймер на заднное время. \n\n";

		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			Shifr_Cezyar();
			break;
		}
		case 2:
		{
			calendar();
			break;
		}
		case 3:
		{
			module_9();
			break;
		}
		case 4:
		{
			module_12();
			break;
		}
		case 5:
		{
			flag = false;
			break;
		}

		}
	} while (flag = true);

}