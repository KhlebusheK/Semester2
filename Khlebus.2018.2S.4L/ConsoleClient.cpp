// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MatrixLibrary.h"

using namespace Matrix;


int main()
{
	int n;
	std::cout << "Enter number of rows" << std::endl;
	std::cin >> n;

	double** matrixA = AllocateMemory(n);

	InitRandomMatrix(matrixA, n);
	DisplayMatrix(matrixA, n);

	std::cout << std::endl;

	CreateNewMatrix(matrixA, n);
	DisplayMatrix(matrixA, n);

	std::cout << std::endl;

	FreeMemory(matrixA, n);

	system("pause");
}

