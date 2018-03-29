// Laba4.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include "MatrixLibrary.h"


using namespace Matrix4;

#pragma region Memory
LABA4_API double** Matrix4::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	double** a = new double*[n];

	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = new double[n - i];
	}

	return a;
}

LABA4_API void Matrix4::FreeMemory(double** matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
#pragma endregion


LABA4_API  void Matrix4::InitRandomMatrix(double** array, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			array[i][j+i] = rand() % 100;
		}
	}
}

LABA4_API  void Matrix4::SumOfMatrix(double** A, double** B, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	} 

	double ** C = AllocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

LABA4_API void Matrix4::DisplayMatrix(double ** array, int  n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	/*for (int i = 0; i < n; i++)
	{
	if (*(array + i) == nullptr)
	{
	throw std::invalid_argument("Argument is null!");
	}
	}*/

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; ++j)
		{
			std::cout.width(6);
			std::cout << array[i][j];
			array[i][j] = array[j][i];
			std::cout << array[j][i];
		}
		std::cout << std::endl;
	}
}