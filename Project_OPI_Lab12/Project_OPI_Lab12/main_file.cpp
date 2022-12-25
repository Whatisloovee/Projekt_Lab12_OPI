#include <iostream>

using namespace std;
int Shifr_Cezyar();
void calendar();
void module_9();
void module_12();
void morzo();
int main()
{
	setlocale(0, "");
	int choose;
	
	cout << "Проект \"Солянка\"";
	do {
		cout << "\n\n1-Шифр Цезаря(шифрование и дешифрование). \n2-Вывод календаря на указанны год. \n3-Вывод расписания занятий на заданный день. \n4-Таймер на заднное время. \n5-Перевод с русского на азбуку Морзе и обратно. \n6-Выход.\n\n";

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
			morzo();
			break;
		}
		case 6:
		{
			
			return 0;
		}

		}
	} while (true);

}