// lb8.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "8lb.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

Product::Product::Product(char * name, double  cost, char * shelfLife, char * sort, char * releaseDate)
{
	this->SetCar(name, cost, shelfLife, sort, releaseDate);
}

Product_API void Product::Product::SetName(char * name)
{
	if (name == nullptr)
	{
		throw std::bad_alloc();
	}

	this->name = AllocateMemory(name);

	strcpy(this->name, name);
}

Product_API void Product::Product::SetCost(double * cost)
{
	if (cost == nullptr)
	{
		throw std::bad_alloc();
	}

	this->cost = cost;
}

Product_API void SetShelfLife(char* shelfLife)
{
	if (shelfLife == nullptr)
	{
		throw std::bad_alloc();
	}

	this->shelfLife = AllocateMemory(shelfLife);

	strcpy(this->shelfLife, shelfLife);
}

Product_API void Product::Product::SetSort(char * sort)
{
	if (sort == nullptr)
	{
		throw std::bad_alloc();
	}

	this->sort = AllocateMemory(sort);

	strcpy(this->sort, sort);
}

Product_API void Product::Product::SetReleaseDate(char* releaseDate)
{
	if (releaseDate <= 0)
	{
		throw std::invalid_argument("Year of issue can not be less or equal zero!");
	}

	this->releaseDate = AllocateMemory(releaseDate);

	strcpy(this->releaseDate, releaseDate);
}

Product_API void Product::Product::SetProduct(char * name, double  cost, char * shelfLife, char * sort, char * releaseDate)
	this->SetName(name);
	this->SetCost(cost);
	this->SetShelfLife(shelfLife);
	this->SetSort(sort);
	this->SetReleaseDate(releaseDate);
}

Product_API char * Product::Product::GetName()
{
	return this->name;
}

Product_API double  Product::Product::GetCost()
{
	return this->cost;
}

Product_API char * Product::Product::GetShelfLife()
{
	return this->shelfLife;
}

Product_API char * Product::Product::GetSort()
{
	return this->sort;
}

Product_API char * Product::Product::GetReleaseDate()
{
	return this->releaseDate;
}

Product_API void Product::Product::EnterProduct()
{
	const int N = 256;
	char name[N] = "";
	std::cout << "Enter the name of product:";
	std::cin.ignore();
	std::cin.getline(name, N, '\n');

	double cost;
	std::cout << "Enter the cost of product:";
	std::cin.getline(cost, N, '\n');

	char shelfLife[N] = "";
	std::cout << "Enter the shelf life of product:";
	std::cin.getline(shelfLife, N, '\n');

	char sort[N] = "";
	std::cout << "Enter the sort of product:";
	std::cin.getline(sort, N, '\n');

	char releaseDate[N] = "";
	std::cout << "Enter release date of product:";
	std::cin >> releaseDate;

	this->SetProduct(name, cost, shelfLife, sort, releaseDate);

}

Product_API void Product::Product::DisplayProduct()
{
	std::cout << std::endl << this->name << " " << this->cost << " " << this->shelfLife << " " << this->sort << ", \t";
	std::cout.precision(3);
	std::cout << this->releaseDate << "  , \t";
}

Product_API char* Product::Product::AllocateMemory(char * ch)
{
	if (ch == nullptr)
	{
		throw std::bad_alloc();
	}

	return new char[strlen(ch) + 1];
}



