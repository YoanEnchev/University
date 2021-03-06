#include "stdafx.h"
#include<iostream>


using namespace std;
int br = 1;

void push_l(int n);
void push_r(int n);
int pop_l(int &n);
int pop_r(int &n);
void list();
void tarseneNaChislo(int chisloZaTarsene);


struct elem                             //структура на дек
{
	int key;                         //съдържа стойността на елемента
	elem *next;          //сочи към следващия елемент                       
} *_left = NULL, *_right = NULL;        //left сочи към краиния ляв елемент,а right сочи към крайния десен

void push_l(int n)              //добавяне на елемент със стойност n
{
	elem *p;                //създаване на указател p от тип elem
	p = _left;                      //p приема стойността на крайния ляв елемент
	_left = new elem;       //създава нов елемент сочен от left
	_left->key = n; //установяване на  n заа стойност на крайния ляв елемент 
	_left->next = p;                //следващия елемент left приема стойността на p
	if (right == NULL)           //ако няма краен десен елемент, то left  става такъв
	{
		_right = _left;
	}
}
void push_r(int n)              //добавяне отдясно на елемент със стойност  n
{
	elem *p;                //създаване на указател  p от тип elem
	p = _right;             //p приема стойността на краиния десен елемент
	_right = new elem;      //създаване на нов елемент сочен от right
	_right->key = n;                //установяване на n за стойнот на крайния десен елемент
	_right->next = NULL;    //следващия елемент right приема NULL
	if (_left == NULL)              //ако няма краен ляв елемент 
	{
		_left = _right;         //крайният ляв приема стйността на крайния
	}
	else                            //десен, в противен случей                      
		p->next = _right;       // следващият елемент райт приема стойността на крайния десен елемент
}
int pop_l(int &n)                       //извличане на елемент отляво
{
	elem *p;                        //създаване на указател p от тип elem
	if (_left)                              //проверка за наличие на краен ляв елемент 
	{
		n = _left->key;             //n приема стойността на крайния ляв елемент
		p = _left;                      //p  сочи крайния елемент
		_left = _left->next;    //left сочи следващият негов елемент
		if (left == NULL)               //ако няма краен ляв елемент
			_right = NULL;          //указателят right се занулява
		delete p;               //изтриване на указателя  p
		return 1;
	}
	else
		return 0;
}
int pop_r(int &n)                       //извличане на елемент отдясно
{
	elem *p;                        //създаване на указател p от тип elem
	if (right)                      //проверка за наличие на краен десен елемент
	{
		n = _right->key;                 //n приема стойността на крайния десен елемент
		if (_left == _right)            //ако крайния десен елемент=крайния ляв
		{
			delete _right;          //изтриване на крайния десен
			_left = _right = NULL;  //нулиране на указателите
		}
		else
		{
			p = _left;                      //p приема стойността на крайния ляв елемент
			while (p->next != _right)       //докато следващия p елемент 
											//е различен от крайния десен
				p = p->next;                    //p преминава на следващия елемент
			n = _right->key;                        //n приема стойността на крайния десен
			p->next = NULL;         //указателят за следващият на  p се нулира
			delete _right;                  //изтриване на крайния десен елемент
			_right = p;                     //крайният десен приема стойността на p
		}
		return 1;
	}
	else
		return 0;
}



void list()                     //извеждане на елементите на дека
{
	int element;
	cout << "\n DEK: \t";
	while (pop_l(element)) {
		cout << element << "\t";
	}
}

void tarseneNaChislo(int chisloZaTarsene)
{
	int number;
	bool dobavqneNaChisloto = false;

	for (int i = 0; i < br; i++)  //цикъл за обхождане на дека
	{
		pop_l(number);       //извличане на крайния ляв елемент 
		if (number == chisloZaTarsene)             //проверка за достигнат n-ти  елемент
		{
			dobavqneNaChisloto = true;
		}

		push_r(number); //добавяне на извлечения елемент от дясно
	}

	if (dobavqneNaChisloto)
	{
		push_l(chisloZaTarsene);
	}
}

void main()
{
	cout << "Broj elementi: ";
	cin >> br;

	int number;

	for (int i = 0; i < br; i++)
	{
		cin >> number;
		push_r(number);
	}

	int chisloZaProverka;
	cout << "Chislo za tarsene: ";
	cin >> chisloZaProverka;

	tarseneNaChislo(chisloZaProverka);
	list();
}