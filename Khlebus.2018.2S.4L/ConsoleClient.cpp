// ConsoleClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MatrixLibrary.h"



int main()
{
	int n;
	std::cout << "Enter number" << std::endl;
	std::cin >> n;

	double **matrixA = AllocateMemory(n);
	InitRandomMatrix(matrixA, n);
	DisplayMatrix(matrixA, n);

	double **matrixB = AllocateMemory(n);
	InitRandomMatrix(matrixB, n);
	DisplayMatrix(matrixB, n);

	double **matrixC = AllocateMemory(n);
	SumOfMatrix(matrixA, matrixB, n);
	DisplayMatrix(matrixC, n);

	FreeMemory(matrixA, n);
	FreeMemory(matrixB, n);
	FreeMemory(matrixC, n);

	system("pause");
}

