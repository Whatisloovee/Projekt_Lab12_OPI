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
	cout << "������ \"�������\"";
	do {
		cout << "\n\n1-���� ������(���������� � ������������). \n2-����� ��������� �� �������� ���. \n3-����� ���������� ������� �� �������� ����. \n4-������ �� ������� �����. \n\n";

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