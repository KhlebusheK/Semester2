// Struct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Worker
{
 FIO FIO;
 Address Address;
 char nationality[30];
 Birthday Birthday;
 int shopNumber[10];
 int personnelNumber[10];
char education[100];
int yearOfEmployment[5];
};
struct FIO
{
	char surname[30];
	char name[30];
	char patronymic[30];
};
struct Address 
{
	int postcode[15];
	char country[30];
	char region[25];
	char area[10];
	char city[15];
	char street[20];
	int house[5];
	int apartment[5];
};
struct Birthday 
{
public:
	int year[5];
	char month[10];
	int number[3];
};


int main()
{
	Worker Ivanov;
	Ivanov.education = "BSU";
	cout << Ivanov.education;
    return 0;
}

