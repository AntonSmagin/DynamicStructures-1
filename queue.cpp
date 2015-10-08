#include "stdafx.h"
#include "queue.h"
#include <iostream>
#include <clocale>

using namespace std;

Node *First(int val)
{
	Node *pv = new Node;
	pv->val = val; //(*pv).val
	pv->p = NULL;
	return pv;
}

void add(Node **pend, int val)
{
	Node *pv = new Node;
	pv->val = val;
	pv->p = NULL;
	(*pend)->p = pv;
	*pend = pv;
}


int del(Node **pbeg)
{
	int temp = (*pbeg)->val;
	Node *pv = *pbeg;
	*pbeg = (*pbeg)->p;
	delete pv;
	return temp;
}


void print(Node **pbeg)
{
	Node *tmp = (*pbeg)->p;

	printf("%d ", (*pbeg)->val);
	while (tmp != NULL)
	{
		printf("%d ", tmp->val);
		tmp = tmp->p;
	}
	cout << endl;

}

void menu()
{
	setlocale(LC_ALL, "Russian");

	Node *pbeg = NULL;
	Node *pend = NULL;
	{

		char t;
		int first_el;
		int el = 0;
		do
		{
			cout << "***QUEUE***" << endl << endl;
			cout << "1. Добавить первый элемент в очередь\n";
			cout << "2. Добавить новый элемент в очередь\n";
			cout << "3. Удалить первый элемент из очереди\n";
			cout << "4. Распечатать элемент(ы) очереди\n\n";
			cout << "Выберите число и нажмите ENTER\n";
			cin >> t;
			if (t >= 48 && t < 53)
			{
				switch (t)
				{
				case 1:
					cout << "Создайте первый элемент\n\n";
					cin >> first_el;

					pbeg = First(first_el);
					pend = pbeg;
					system("CLS");
					break;

				case 2:
					cout << "Напишите новый элемент\n\n";
					cin >> el;
					add(&pend, el);
					system("CLS");
					break;
				case 3:
					del(&pbeg);
					cout << "Элемент был удален из очереди\n\n";
					break;
				case 4:
					cout << "Распечатаная очередь\n\n";
					print(&pbeg);
					system("pause");
					cout << endl;
					system("cls");
					break;
				}
			}
			else 
			{
				cout << endl;
				cout << "Неверное значение! Введиите число от 1 до 4"<<endl<<endl;
				system("pause");
				cout << endl;
				system("cls");
			}
		} while (t);
		
		
	}

}
