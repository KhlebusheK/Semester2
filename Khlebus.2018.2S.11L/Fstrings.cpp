// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include "Fstrings.h"

using namespace std;


int main()
{
	const int N = 80;
	char fileName[N] = "";

	cout << "Enter the name of file: ";
	cin.getline(fileName, N, '\n');

	CreateFile(fileName);

	int count = ContentsFile(fileName);

	int n = 9;
	int max, min;

	//char source[] = "111 Yes No-12365&*)(^%dfreejjfjkkeld; pr sd";
	char* source = InitArray(fileName, count);

	char** string = ObtainWords(source, n);
	DisplayWords(string, n);

	FindMaxAndMinWords(string, n, max, min);

	char str1[] = "All words of the max and min length :";
	char * sortedwords = WriteInArray(string, n, max, min);
	AddFile(fileName, sortedwords, str1);

	std::cout << std::endl << sortedwords << std::endl;

	FreeHeap(string, n);

	system("pause");
	return 0;
}

