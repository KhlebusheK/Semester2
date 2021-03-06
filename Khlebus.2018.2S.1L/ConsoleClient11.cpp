// ConsoleClient1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Laba.h"
#include <iostream>

using namespace Massive;

int main()
{
	//std::cout <<BinaryTranslation(-16);
	int n;
	std::cout << "Please, enter natural number ";
	std::cin >> n;

	int* array = AllocateMemory(n);

	InitArray(array, n);

	DisplayArray(array, n);
	std::cout << std::endl;

	int* newArray = AllocateMemory(n);

	std::cout <<"It's new massive : ";
	IsNewMassive(array, newArray, n);

	int k = NumberOfElementsInNewMassive(array, n);

	DisplayArray(newArray, k);
	std::cout << std::endl;

	std::cout << "It's old massive without elements : ";
	RemoveOldElements(array, newArray, n);

	DisplayArray(array, n);
	std::cout << std::endl;

	std::cout << "Elements of massive is difference between 1 and 0 in the binary form : ";
	DisplayBinCountArr(array, n);
	std::cout << std::endl;

	std::cout << "It's sorting massive : ";
	SortingOldMassive(array, n);

	DisplayArray(array, n);
	std::cout << std::endl;

	FreeMemory(array);
	system("pause");

	return 0;
}



