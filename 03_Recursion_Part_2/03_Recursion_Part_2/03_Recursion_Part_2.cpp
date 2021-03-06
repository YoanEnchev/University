//Decimal to Hex through recursion

#include "stdafx.h"
#include <iostream>
#include <string> //string - поредица от символи - FE15A, става да се запише 16-ично число
#include <algorithm> //библиотека, която може да revers-не  string - само с един ред, иначе for цикъл

using namespace std;

//декларация на функцията
void convertToHex();

//глобални променливи
string hexNum = "";//няколко символа, които представляват 16-ичното число
int decimalNum; // числото, което потребителя ще въведе

void main()
{
	cout << "Decimal: ";
	cin >> decimalNum;
	cout << "Hexademical: ";

	convertToHex(); //извикване на рекурсивната функция
    reverse(hexNum.begin(), hexNum.end()); //revers-ни всички символи от началото до края
	cout << hexNum << endl;//принтирай вече revers-натото число 
}

void convertToHex()
{
	if (decimalNum != 0) //ако числото не е 0, дели го на 16 и така
	{
		int remainer = decimalNum % 16; // Пример 100 % 16 = 4
		decimalNum /= 16; // Пример: 63/16 = 3 (заради целочислено делене)

		if (remainer < 10) //ако остатъка от 0 до 9
		{
			hexNum += to_string(remainer);
		}

		else // ако остатъка е по-голям от 9... 10->А, 11->B...
		{
			switch (remainer)
			{
			case 10:
				hexNum += "A";
				break;
			case 11:
				hexNum += "B";
				break;
			case 12:
				hexNum += "C";
				break;
			case 13:
				hexNum += "D";
				break;
			case 14:
				hexNum += "E";
				break;
			case 15:
				hexNum += "F";
				break;
			}
		}
		convertToHex(); //рекурсия, ще се вика пак и пак докато числото не стане 0 (горе)
	}
}

