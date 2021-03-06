// MatrixExtension.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <iostream>
#include "MatrixExtension.h"
#include <cmath>

using namespace MatrixLibrary;

#pragma region prepare
MATRIXLIBRARY_API double ** MatrixLibrary::AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Dimentions can not be less or equal zero!");
	}

	double** a = new double*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}

	return a;
}

MATRIXLIBRARY_API void MatrixLibrary::FreeMemory(double ** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

MATRIXLIBRARY_API void MatrixLibrary::DisplayMatrix(double ** matrix, int n)
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

	for (int i = 0; i < n; ++i)
	{

		for (int j = 0; j < n; ++j)
		{
			std::cout.width(8);
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
}
#pragma endregion

MATRIXLIBRARY_API double MatrixLibrary::SinTaylor(double value, double accurancy)
{
	if (accurancy < 0.0 || accurancy >= 1)
	{
		//http://www.cplusplus.com/reference/exception/exception/
		throw std::out_of_range("Accurancy must be between 0 and 1!");
	}

	double term = value, sum = 0;

	for (int i = 1; fabs(term) > accurancy; i++)
	{
		sum += term;
		term = -term * value * value / (2 * i) / (2 * i + 1);
	}

	return sum;
}

MATRIXLIBRARY_API void MatrixLibrary::InitMatrixTaylor(double ** matrix, int n, double accurancy)
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
	if (*(matrix + i) == nullptr)
	{
	throw std::invalid_argument("Argument is null!");
	}
	}*/


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != 2*j) matrix[i][j] = i;
			matrix[i][j] = (SinTaylor(2 * i * j, accurancy) + SinTaylor(i, accurancy)) / ((i - j - 4) ^ 3 + (i + j) ^ 2);
		}
	}
}

MATRIXLIBRARY_API void MatrixLibrary::InitMatrixTable(double ** matrix, int n)
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
	if (*(matrix + i) == nullptr)
	{
	throw std::invalid_argument("Argument is null!");
	}
	}*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != 2 * j) matrix[i][j] = i;
			matrix[i][j] = (sin(2 * i * j) + sin(i)) / ((i - j - 4) ^ 3 + (i + j) ^ 2);
		}
	}
}

MATRIXLIBRARY_API void MatrixLibrary::CompareMatrix(double ** matrixTaylor, double ** matrixTable, int n)
{
	std::cout << " Elements of matrix Taylor  : "<< std::endl;
	int k = 0;

		for (int i=0; i < n; i++)
		{
			for (int j=0; j < n; j++)
			{
					if (matrixTaylor[i][j] == matrixTable[i][j]) k = 1;
					if (matrixTaylor[i][j] > matrixTable[i][j]) k = 2;
					k = 3;
					switch (k)
					{
					case 1:
						std::cout << i+1 <<"," << j+1 << " are equal"<<";  ";
						break;
					case 2:
						std::cout << i+1 <<"," << j+1 << " more"<< ";  ";
						break;
					case 3:
						std::cout << i+1 <<"," << j+1 << " less"<< ";  ";
						break;
					}
			}
		}
}