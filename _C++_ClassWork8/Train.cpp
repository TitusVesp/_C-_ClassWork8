#include "Train.h"
#include <algorithm>

bool isPermutation(char* str1, char* str2, int size)
{
	std::sort(str1, str1 + size);
	std::sort(str2, str2 + size);

	for (int i = 0; i < size; ++i)
	{
		if (str1[i] != str2[i])
			return false;
	}

	return true;
}

//Використання гглобальних зміних через недосконалість структури(бажано в цій задачі, щоб дотримуватись правил інкапсуляції використовувати клас)!!!
Train* a = new Train[10];
int sizeStruct;

void Input()
{
	cout << "Imput qualiti of Data that you want to have(no more then 10): " << endl;
	int n = 0;
	cin >> n;
	if (n >= 10) return;
	Train* a_tmp = new Train[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Imput name: " << endl;
		cin >> a_tmp[i].destination;
		cout << "Imput Train number: " << endl;
		cin >> a_tmp[i].trainNum;
		cout << "Impute Date(Year, Month, Day< hour, Min): " << endl;
		cin >> a_tmp[i].Date.year >> a_tmp[i].Date.month >> a_tmp[i].Date.day >> a_tmp[i].Date.hour >> a_tmp[i].Date.min;
	}
	sizeStruct = n;
	Sort();
	a = a_tmp;
}

void Find()
{
	cout << "Imput desination: " << endl;
	char tmp[64];
	while (tmp[0] < 0 || tmp[0] == '\0')
		cin.getline(tmp, 64);
	for (int i = 0; i < 10; i++)
	{
		if (isPermutation(a[i].destination, tmp, strlen(tmp)))
		{
			cout << " " << "Name: " << " " << endl;
			cout << " " << a[i].destination << endl;
			cout << " " << "Train number: " << " " << endl;
			cout << " " << a[i].trainNum << endl;
			cout << " " << "Date(Year, Month, Day, hour, Min): " << " " << endl;
			cout << " " << a[i].Date.year << " " << a[i].Date.month << " " << a[i].Date.day << " " << a[i].Date.hour << " " << a[i].Date.min << endl;
		}
	}

	cout << "Incorrect input of destination! " << endl;
}

void OutPut()
{
	for (int i = 0; i < a[0].numOfTrains; i++)
	{
		if (a[i].destination > 0)
		{
			cout << " " << "Name: " << " " << endl;
			cout << " " << a[i].destination << endl;
			cout << " " << "Train number: " << " " << endl;
			cout << " " << a[i].trainNum << endl;
			cout << " " << "Date(Year, Month, Day< hour, Min): " << " " << endl;
			cout << " " << a[i].Date.year << " " << a[i].Date.month << " " << a[i].Date.day << " " << a[i].Date.hour << " " << a[i].Date.min << endl;
		}
	}
}

void Sort()
{
	for (int i = 0; i < a[0].numOfTrains; i++)
	{
		for (int j = 0; j < a[0].numOfTrains - 1; j++)
		{
			if (a[j].destination > a[j + 1].destination) swap(a[j], a[j + 1]);
		}
	}
}

void InFile()
{
	ofstream input("Main");
	ofstream inputTxt("ReadMain.txt");
	input.clear();
	inputTxt.clear();
	for (int i = 0; i < sizeStruct; i++) input.write((char*)& a[i], sizeof(Train));
	for (int i = 0; i < sizeStruct; i++)
	{
			inputTxt << " " << "Name: " << " " << endl;
			inputTxt << " " << a[i].destination << endl;
			inputTxt << " " << "Train number: " << " " << endl;
			inputTxt << " " << a[i].trainNum << endl;
			inputTxt << " " << "Date(Year, Month, Day< hour, Min): " << " " << endl;
			inputTxt << " " << a[i].Date.year << " " << a[i].Date.month << " " << a[i].Date.day << " " << a[i].Date.hour << " " << a[i].Date.min << endl;
	}
	input.close();
	inputTxt.close();
}

void FromFile()
{
	ifstream output("Main");
	Train* train = new Train[10];
	for (int i = 0; i < sizeStruct; i++)
	{
		output.read((char*)& train[i], sizeof(Train));
		{
			cout << " " << "Name: " << " " << endl;
			cout << " " << a[i].destination << endl;
			cout << " " << "Train number: " << " " << endl;
			cout << " " << a[i].trainNum << endl;
			cout << " " << "Date(Year, Month, Day< hour, Min): " << " " << endl;
			cout << " " << a[i].Date.year << " " << a[i].Date.month << " " << a[i].Date.day << " " << a[i].Date.hour << " " << a[i].Date.min << endl;
		}
	}
}
