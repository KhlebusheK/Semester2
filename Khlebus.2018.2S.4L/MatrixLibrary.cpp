// MatrixLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MatrixLibrary.h"
#include <iostream>

#pragma region prepare
MATRIXLIBRARY_API double ** Matrix::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	double** a = new double*[n];

	for (int i = 0; i < n; i++)
	{
		int k = i;
		a[i] = new double[k+1];
	}

	return a;
}

MATRIXLIBRARY_API void Matrix::FreeMemory(double ** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

MATRIXLIBRARY_API void Matrix::DisplayMatrix(double ** matrix, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (matrix == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	/*for (int i = 0; i < n; i++)
	{
	if ( *(matrix + i) == nullptr)
	{
	throw std::invalid_argument("Argument is null!");
	}
	}*/

	for (int i = 0, j=0; i < n; ++i)
	{
		int c = i;
		while (j <= c)
		{
			std::cout.width(8);
			std::cout << matrix[i][j];
			j++;
		}
		j--;
		c++;
		while (c < n)
		{
			std::cout.width(8);
			std::cout << matrix[c][j];
			c++;
		}
		j = 0;
		std::cout << std::endl;
	}
}

#pragma endregion

MATRIXLIBRARY_API void Matrix::InitRandomMatrix(double ** array, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = 0; i < n; i++)
	{
		int k = i + 1;
		for (int j = 0; j < k; j++)
		{
 			array[i][j] = rand() % 100 - 15;
			
		}
	}
}

MATRIXLIBRARY_API void Matrix::CreateNewMatrix(double ** array, int n)
{
	if (n <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (array == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	for (int i = 0; i < n; i++)
	{
		int k = i + 1;
		for (int j = 0; j < k; j++)
		{
			array[i][j] = array[i][j] * array[i][j];
			
		}
	}
}
