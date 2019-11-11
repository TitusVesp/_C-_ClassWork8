#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Train
{
public:
	int numOfTrains;
	char destination[64];
	int trainNum;
     struct 
	{
	public :
		int year, month, day, hour, min;
	} Date;
};

void Input();
void Find();
void OutPut();
void Sort();

void InFile();
void FromFile();