#include "stdafx.h"
#include <iostream>
#include <string> //string - поредица от символи - FE15A, става да се запише 16-ично число

using namespace std;

//декларация на функцията
void convertToDec();

//глобални променливи
string hexNum;//няколко символа, които представляват 16-ичното число, въведено от потребителя
int decimalNum = 0; // числото, конвертирано в десетична бр. с-ма
int index = 0; //индекс на символа от 16-тичното число
int power; // степента на 16. Пример: (1А = 1 * 16^1 + 10 * 16^0 = 161)

void main()
{
	cout << "Hexademical: ";
	cin >> hexNum;
	cout << "Decimal: ";
	power = hexNum.length() - 1; // започва се от 16 на степен (броят цифри на числото - 1)

	convertToDec(); //извикване на рекурсивната функция
	cout << decimalNum << endl;
}

void convertToDec()
{
	if (index < hexNum.length()) //ако индексът е по-малък от броя символи на 16-ичното число
	{
		char hexDigit = hexNum[index];

		switch (hexDigit) //проверка на цифрата (от 1 до F) и смятане
		{
		case '1': decimalNum += 1 * pow(16, power); break;//1 * 16 на степен power
		case '2': decimalNum += 2 * pow(16, power); break;
		case '3': decimalNum += 3 * pow(16, power); break;
		case '4': decimalNum += 4 * pow(16, power); break;
		case '5': decimalNum += 5 * pow(16, power); break;
		case '6': decimalNum += 6 * pow(16, power); break;
		case '7': decimalNum += 7 * pow(16, power); break;
		case '8': decimalNum += 8 * pow(16, power); break;
		case '9': decimalNum += 9 * pow(16, power); break;
		case 'A': decimalNum += 10 * pow(16, power); break;
		case 'B': decimalNum += 11 * pow(16, power); break;
		case 'C': decimalNum += 12 * pow(16, power); break;
		case 'D': decimalNum += 13 * pow(16, power); break;
		case 'E': decimalNum += 14 * pow(16, power); break;
		case 'F': decimalNum += 15 * pow(16, power); break;
		}
		index++; //продължи със следващата цифра от 16-ичното число
		power--; //защото А1 = 10 * 16^1 + 1 * 16^0

		convertToDec();
	}
}