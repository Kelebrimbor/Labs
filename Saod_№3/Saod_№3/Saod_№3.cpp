#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
using namespace std;

struct Sequence {
	char data;
	Sequence *next;
};

bool CheckEmpty(Sequence *first)
{
	if (first->next == NULL)
		return true;
	else
		return false;
}


void AddElement(Sequence **last, char data)
{
	Sequence *blank = (Sequence*)malloc(sizeof(Sequence));

	blank->data = data;
	blank->next = NULL;

	(*last)->next = blank;
	(*last) = blank;
}

void RemoveElement(Sequence **first, Sequence **last)
{
	Sequence *blank = (Sequence*)malloc(sizeof(Sequence));

	blank = (*first)->next;
	(*first)->next = blank->next;

	free(blank);

	if (CheckEmpty(*first)) {
		*last = *first;
	}
}

void Show(Sequence *first)
{
	Sequence *blank = (Sequence*)malloc(sizeof(Sequence));

	cout << "Вывод очереди:" << endl;

	blank = first->next;

	while (blank != NULL)
	{
		cout << blank->data << endl;
		blank = blank->next;
	}

	free(blank);
}

void main()
{
	setlocale(LC_ALL, "rus");
	
	int chosen=0, n;
	int value;
	char symbol;
	Sequence *first;
	Sequence *last;

	first = (Sequence*) malloc(sizeof(Sequence));
	first->next = NULL;
	last = first;

	while (1) {
		system("cls");
		cout << "Нажмите 'q' чтобы остановить цикл.\n\n" << endl;

		if (_kbhit()) {
			if ((chosen = _getch() - 48) == 65)
				break;
		}

		chosen = 1 + rand() % 100;
		Sleep(1000);
		cout << "Сгенерировано случайное число: '" << chosen << "'" << endl;
		chosen %= 2;
		chosen = 1 ? chosen != 0 : 0;
		Sleep(2000);

		switch (chosen) {

			case 0: {
				n = 1 + rand() % 3;
				cout << "Выполняется операция добавления " << n << " элементов..." << endl;
				Sleep(3000);

				for (int i = 0; i < n; i++) {
					value = 65 + rand() % 26;
					symbol = (char)value;
					AddElement(&last, symbol);
					cout <<"Элемент '"<<symbol<<"' успешно добавлен!" << endl;
					Sleep(1000);
				}

				cout << "\n\nПроизводится вывод очереди на экран..." << endl;
				Sleep(3000);
				system("cls");
				if (!(CheckEmpty(first)))
				{
					Show(first);
				}
				else
					cout << "Очередь пуста!" << endl;

				Sleep(4000);
				break;
			}

			case 1: {
				n = 1 + rand() % 3;
				cout << "Выполняется операция удаления " << n << " элементов..." << endl;
				Sleep(3000);

				for (int i = 0; i < n; i++) {
					if (!(CheckEmpty(first)))
					{
						RemoveElement(&first, &last);
						cout << "Элемент успешно удален!" << endl;
						Sleep(1000);
					}
					else
					{
						cout << "Удаление прекращено, так как очередь пуста" << endl;
						break;
					}
				}

				cout << "\n\nПроизводится вывод очереди на экран..." << endl;
				Sleep(3000);
				system("cls");
				if (!(CheckEmpty(first)))
				{
					Show(first);
				}
				else
					cout << "Очередь пуста!" << endl;
				Sleep(4000);
				break;
			}

		}
	}
	cout << "Произведен выход из цикла!" << endl;
	system("pause");
}
