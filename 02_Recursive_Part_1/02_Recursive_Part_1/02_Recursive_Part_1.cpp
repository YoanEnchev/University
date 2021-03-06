﻿#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//глобални променливи:
int index = 0;
int arr[10]; //допуснатото число е максимум с 10 цифри

void fillArray(int arr[], string &numberAsString);
void printArray(int arr[]);

void main()
{
	//1. Валидация, че въведеното число е естествено (по - голямо от 0 и цяло)
	int number;

	while (true)
	{
		cout << "Number: ";
		cin >> number;

		if (number < 1)
		{
			cout << "Input must be bigger number than one." << endl;
		}
		else {
			break; //щом е валидно числото, продължи напред, излез от цикъла
		}
	}

	//2. Представяне на числото като стринг, поредица от символи
	string numberAsString = to_string(number);
	fillArray(arr, numberAsString); //извикване на рекурсивна функция


	//3.Принтиране на масива:
	printArray(arr);
}

void fillArray(int arr[], string &numberAsString)
{
	if (numberAsString != "")//ако числото не е останало без цифри (като символи)
	{
		int firstDigit = numberAsString[0] - 48; //-48 заради ASCII
		numberAsString.erase(0, 1); // махни първата цифра от числото

		arr[index] = firstDigit;
		index++;
		fillArray(arr, numberAsString);
	}
}

void printArray(int arr[])
{
	for (int i = 0; i < index; i++)
	{
		cout << "a[" << i << "] = " << arr[i] << endl;
	}
}
