
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
using namespace std;
int countOfList = 0;

void Push(int list[], int value)
{
	if (countOfList == 0)
		list[0] = value;
	else
	{
		for (int i = 0; i < countOfList; i++)
		{
			if (value < list[i])
			{
				for (int j = countOfList; j > i-1; j--)
				{
					list[j] = list[j-1];
				}
				list[i] = value;
				countOfList++;
				return;
			}
			else if (i == countOfList - 1)
				list[i+1] = value;
		}
	}
	countOfList++;
}

int Pop(int list[], int value)
{
	for (int j = 0; j < countOfList; j++)
	{
		if (list[j] == value)
		{
			for (int i = j; i < countOfList-j+1; i++)
			{
				list[i] = list[i + 1];
			}
			countOfList--;
			return 1;
		}
	}
	return -1;
}

int Search(int list[], int value)
{
	for (int i = 0; i < countOfList; i++)
	{
		if (list[i] == value)
			return i;
	}
	return -1;
}

void Show(int list[])
{
	if (countOfList == 0)
		cout << "Список пуст!" << endl;
	else
	{
		for (int i = 0; i < countOfList; i++)
		{
			cout << "[" << i << "] элемент: " << list[i] << endl;
		}
	}
}


void main()
{
	setlocale(LC_ALL, "rus");
	int list[5], chosen, value, search;

	while (1) {
		system("cls");
		cout << "1)Добавить элемент\n2)Удалить элемент\n3)Поиск элемента\n4)Вывод списка на экран" << endl;
		chosen = _getch() - 48;

		switch (chosen) {

			case 1: {
				system("cls");

				if (countOfList == 5)
				{
					cout << "Список заполнен!" << endl;
				}
				else
				{
					cout << "Введите значение: " << endl;
					while (!(cin >> value)) {
						cin.clear();
						while (cin.get() != '\n');

						cout << "Введены некорректные данные! Попробуйте снова:" << endl;
					}

					Push(list, value);
					cout << "Добавление элемента '" << value << "' успешно произведено!" << endl;
				}

				system("pause");
				break;
			}

			case 2: {
				system("cls");

				if (countOfList == 0)
				{
					cout << "Список пуст!" << endl;
				}
				else
				{
					cout << "Список:" << endl;
					Show(list);

					cout << "Введите информационную часть элемента, который хотите удалить:" << endl;
					while (!(cin >> value)) {
						cin.clear();
						while (cin.get() != '\n');

						cout << "Введены некорректные данные! Попробуйте снова:" << endl;
					}

					if (Pop(list, value))
					{
						cout << "Удаление элемента '" << value << "' успешно произведено!" << endl;
					}
					else
						cout << "Элемент '" << value << "' не обнаружен!" << endl;
				}
				system("pause");
				break;
			}

			case 3: {
				system("cls");

				if (countOfList == 0)
				{
					cout << "Список пуст!" << endl;
				}
				else
				{
					cout << "Введите информационную часть элемента, который хотите найти:" << endl;
					while (!(cin >> value)) {
						cin.clear();
						while (cin.get() != '\n');

						cout << "Введены некорректные данные! Попробуйте снова:" << endl;
					}

					search = Search(list, value);
					if (search == -1)
					{
						cout << "Элемент '"<< value<<"' не обнаружен!" << endl;
						cout << endl << "Список:" << endl;
						Show(list);
					}
					else
					{
						cout << "Искомый элемент '" << value << "' обнаружен под номером '" << search << "'";
						cout << endl << "Список:" << endl;
						Show(list);
					}
				}

				system("pause");
				break;
			}

			case 4: {
				system("cls");

				cout << "Список:" << endl;
				Show(list);

				system("pause");
				break;
			}

		}
	}
}

