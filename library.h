#pragma once
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

char symbols[18]{'!','%','?','\\','/','+','*','$','@','#','&',')','<','>',':',';','-','_'};
int counter = 0;
int flips = 0;
char** arr; // строки
bool** arr1;

void PrintArr(int index)
{
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < index; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void SwapSing(char& index, char& indextochange)
{
	char buffer_index = index;
	index = indextochange;
	indextochange = buffer_index;
}

void MemoryCreator(int index)
{
	if (index % 2 == 0)
	{
		int counter = 0;
		srand(time(0));
		arr = new char* [index];
		for (int i = 0; i < index; i++)
		{
			arr[i] = new char[index]; // столбцы
		}
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < index - 1; j+=2)
			{
				int random = rand() % 10;
				arr[i][j] = symbols[counter];
				arr[i][j + 1] = symbols[counter];
				counter++;
				
			}
		};
		int card1row, card1col;
		int card2row, card2col;
		switch (index)
		{
		case 4:
			for (int i = 0; i < 100; i++)
			{
				card1col = rand() % 4;
				card1row = rand() % 4;
				card2col = rand() % 4;
				card2row = rand() % 4;
				int rand_num = rand() % 2;
				system("cls");
				SwapSing(arr[card1row][card1col], arr[card2row][card2col]);
				PrintArr(index);
			}
			break;
		case 6:
			for (int i = 0; i < 100; i++)
			{
				card1col = rand() % 6;
				card1row = rand() % 6;
				card2col = rand() % 6;
				card2row = rand() % 6;
				int rand_num = rand() % 2;
				system("cls");
				SwapSing(arr[card1row][card1col], arr[card2row][card2col]);
				PrintArr(index);
			}
			break;
		}
		
	}
	else
	{
		cout << "Error! Number Cant Be Divined By 2!";
		exit(1);
	}
}
void UpCard(int index)
{
	system("cls");
	for (int i = 0;i < index;i++)
	{
		for (int j = 0; j < index; j++)
		{
			if (arr[i][j] == ' ')
			{
				cout << ' ';
			}
			else if (arr1[i][j] == false)
			{
				cout << "0";
			}
			else if (arr1[i][j] == true)
			{
				cout << arr[i][j];
			}
		}
		cout << endl;
	}
}
void HideCard(int index)
{
	arr1 = new bool* [index];
	for (int i = 0; i < index; i++)
	{
		arr1[i] = new bool[index]; // столбцы
	}
	for (int i = 0; i < index;i++)
	{
		for (int j = 0;j < index;j++)
		{
			arr1[i][j] = false;
		}
	}
	UpCard(index);
}

void Logic(int index)
{
	int stroke = -1;
	int collum = -1;
	int prev_nums[2];
	for (;;)
	{
		if (stroke != -1 && collum != -1)
		{
			flips++;
			cout << "Type Stroke: ";
			cin >> stroke;
			cout << "Type Collum: ";
			cin >> collum;
			arr1[stroke - 1][collum - 1] = true;
			UpCard(index);
			if (stroke - 1 == prev_nums[0] && collum - 1 == prev_nums[1])
			{
				cout << "Invalid, Syntax!\n";
				continue;
			}
			if (stroke != prev_nums[0] || collum != prev_nums[1])
			{
				if (arr[stroke - 1][collum - 1] == arr[prev_nums[0]][prev_nums[1]])
				{
					if (counter == index * index / 2 - 1)
					{
						system("cls");
						cout << "You Won!\n";
						cout << "Total Card Flips " << flips << "\n";
						return;
					}
					else
					{
						arr[stroke - 1][collum - 1] = ' ';
						arr[prev_nums[0]][prev_nums[1]] = ' ';
						counter++;
						UpCard(index);
					}
				}
				else
				{
					Sleep(400);
					arr1[stroke - 1][collum - 1] = false;
					arr1[prev_nums[0]][prev_nums[1]] = false;
					UpCard(index);
				}
			}
			else
			{
				Sleep(400);
				arr1[stroke - 1][collum - 1] = false;
				arr1[prev_nums[0]][prev_nums[1]] = false;
				UpCard(index);
			}
			stroke = -1;
			collum = -1;
		}
		else if (stroke == -1 && collum == -1)
		{
			flips++;
			cout << "Type Stroke: ";
			cin >> stroke;
			cout << "Type Collum: ";
			cin >> collum;
			prev_nums[0] = stroke - 1;
			prev_nums[1] = collum - 1;
			arr1[stroke - 1][collum - 1] = true;
			UpCard(index);
		}
	}
}