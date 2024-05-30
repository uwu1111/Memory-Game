#pragma once
#include <stdlib.h>
#include <windows.h>

using namespace std;

char symbols[18]{'!','%','?','\\','/','+','*','$','@','#','&','№','<','>',':',';','-','_'};
char** arr; // строки

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
				int randnum = rand() % 10;
				arr[i][j] = symbols[counter];
				arr[i][j + 1] = symbols[counter];
				counter++;
				//cout << arr[i][j] << " ";
			}
			//cout << endl;
		};
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < index; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Error! Number Cant Be Divined By 2!";
	}
}