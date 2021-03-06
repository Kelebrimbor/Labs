#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <iostream>
using namespace std;

int CountOfElements = 0;

bool CheckEmpty(int queue[], int first)
{
	if (queue[first] == NULL)
		return true;
	else
		return false;
}

bool CheckFull()
{
	if (CountOfElements == 10)
		return true;
	else
		return false;
}

void AddElement(int queue[], int &last, int &value)
{
	queue[last] = value;
	last++;
	if (last > 9)
		last = 0;
	CountOfElements++;
}

void RemoveElement(int queue[], int &first)
{
	queue[first] = NULL;
	first++;
	if (first > 9)
		first = 0;
	CountOfElements--;
}

void Show(int queue[], int first, int last)
{
	cout << "Вывод очереди:" << endl;
	for (int i=0; i < 10; i++)
		cout << queue[i] << endl;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int queue[10];
	int first = 0, last = 0, chosen, value;
	for (int i = 0; i < 10; i++)
	{
		queue[i] = NULL;
	}

	while (1) {
		system("cls");
		cout << "1)Проверить очередь на пустоту\n2)Проверить очередь на заполненость\n3)Добавить элемент\n4)Удалить элемент\n5)Вывод очереди на экран" << endl;
		chosen = _getch() - 48;

		switch (chosen) {

			case 1: {
				system("cls");

				if (CheckEmpty(queue, first))
					cout << "Очередь пуста" << endl;
				else
					cout << "Очередь не пуста!" << endl;

				system("pause");
				break;
			}

			case 2: {
				system("cls");

				if (CheckFull())
					cout << "Очередь полна!" << endl;
				else
					cout << "Очередь не заполнена" << endl;

				system("pause");
				break;
			}

			case 3: {
				system("cls");

				if (!(CheckFull()))
				{
					cout << "Введите значение:" << endl;
					while (!(cin >> value)) {
						cin.clear();
						while (cin.get() != '\n');

						cout << "Введены некорректные данные! Попробуйте снова:" << endl;
					}
					AddElement(queue, last, value);
					cout << "Элемент '" << value << "' успешно добавлен!" << endl;
				}
				else
					cout << "Очередь полна!" << endl;

				system("pause");
				break;
			}

			case 4: {
				system("cls");

				if (!(CheckEmpty(queue, first)))
				{
					RemoveElement(queue, first);
					cout << "Элемент успешно удален!" << endl;
				}
				else
					cout << "Очередь пуста!" << endl;

				system("pause");
				break;
			}

			case 5: {
				system("cls");

				if (!(CheckEmpty(queue, first)))
				{
					Show(queue, first, last);
				}
				else
					cout << "Очередь пуста!" << endl;

				system("pause");
				break;
			}
		}
	}
}
