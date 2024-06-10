#include <iostream>
#include <chrono> 
#include <thread>
#include "library.h"

using namespace std;
using namespace std::chrono;

int main()
{
	int gameindex;
	int choice;
	cout << "Welcome To Memory Game!" << endl;
	cout << "Which Difficult Do You Prefer?" << endl << "1. 4x4" << endl << "2. 6x6" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		gameindex = 4;
		break;
	case 2:
		gameindex = 6;
		break;
	}
	MemoryCreator(gameindex);
	char** arr = new char* [gameindex]; // строки
	for (int i = 0; i < gameindex; i++)
	{
		arr[i] = new char[gameindex]; // столбцы
	}
	HideCard(gameindex);
	auto begin = steady_clock::now();
	Logic(gameindex);
	auto end = steady_clock::now();
	float time_seconds = duration_cast<seconds>(end - begin).count();
	cout << "Total Time Spent On Game " << time_seconds << " seconds\n";
}
