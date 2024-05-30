#include <iostream>
#include "Memory.h"

using namespace std;

int main()
{
	int gameindx;
	cout << "Welcome To Memory Game!" << endl;
	cout << "Which Difficult Do You Prefer?" << endl << "1. 4x4" << endl << "2. 8x8" << endl << "3. 16x16" << endl << "4. 32x32" << endl;
	cin >> gameindx;
	MemoryCreator(gameindx);
	char** arr = new char* [4]; // строки
	for (int i = 0; i < 4; i++)
	{
		arr[i] = new char[4]; // столбцы
	}
}
