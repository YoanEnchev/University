#include "stdafx.h"
#include <iostream>

using namespace std;

void fillLeft();
void fillRight();
void fillTop();
void fillBottom();

void fillFrame();
void printMatrix();

const int x = 5;
const int y = 5;

int fillNumber = 1;
int goInside = 0;
int matrix[y][x] = { 0 };

void main()
{
	while (fillNumber <= x * y) {
		fillFrame(); // if element is 0, it gets other number
		goInside++;
	}

	printMatrix();
}

void fillLeft()
{
	for (int i = y - 2; i >= 0; i--) {
		if (matrix[i][0 + goInside] == 0) {
			matrix[i][0 + goInside] = fillNumber;
			fillNumber++;
		}
	}
}

void fillRight() {
	for (int i = 1; i < y; i++) { // rows except first one
		if (matrix[i][x - 1 - goInside] == 0) {
			matrix[i][x - 1 - goInside] = fillNumber;
			fillNumber++;
		}
	}
}

void  fillTop() {
	for (int i = 0; i < x; i++) {

		if (matrix[0 + goInside][i] == 0) {
			matrix[0 + goInside][i] = fillNumber;
			fillNumber++;
		}
	}
}

void fillBottom() {
	for (int i = x - 1; i >= 0; i--) {
		if (matrix[y - 1 - goInside][i] == 0) {
			matrix[y - 1 - goInside][i] = fillNumber;
			fillNumber++;
		}
	}
}

void fillFrame()
{
	fillTop();
	fillRight();
	fillBottom();
	fillLeft();
}

void printMatrix()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << matrix[j][i] << "\t";
		}

		cout << endl;
	}
}
