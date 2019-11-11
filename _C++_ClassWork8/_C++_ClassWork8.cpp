// _C++_ClassWork8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Train.h"

int main()
{
	ofstream t("Main"); t.close();
	ofstream t1("ReadMain.txt"); t1.close();
	char key = 1;
	while (key != 0)
	{
		system("cls");
		cout << "1 - Input(ReWrite), 2 - Find, 3 - OutPut, 4 - InFile, 5 - FromFile" << endl;
		int n = 0;
		cin >> n;
		switch (n)
		{
		case 1:
			Input();
			break;
		case 2:
			Find();
			break;
		case 3:
			OutPut();
			break;
		case 4:
			InFile();
			break;
		case 5:
			FromFile();
			break;
		default:
			cout << "Incorrect input!" << endl;
			break;
		}

		cout << "Out - 0" << endl;
		cin >> key;
	}
}

