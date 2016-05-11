// C++LearningVS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::time;

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

string* ptrToElement(vector<string>* const pVec, int i);

void increase(int* const array, int NUM_ELEMENTS);
void display(const int*  const array, const int NUM_ELEMENTS);

/**指针*/
int _tmain(int argc, _TCHAR* argv[]){
	//指针基础
	int* pAPinter;
	int* pScore = 0;
	int score = 1000;
	pScore = &score;
	cout << "Assigning &score to pScore\n";
	cout << "&score is:" << &score << "\n";
	cout << "pScore is:" << pScore << "\n";
	cout << "score is:" << score << "\n";
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "Adding 500 to score\n";
	score += 500;
	cout << "score is:" << score << "\n";
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "Adding 500 to *pScore\n";
	*pScore += 500;
	cout << "score is:" << score << "\n";
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "Assigning &newScore to pScore\n";
	int newScore = 5000;
	pScore = &newScore;
	cout << "&newScore is:" << &newScore << "\n";
	cout << "pScore is:" << pScore << "\n";
	cout << "newScore is:" << newScore << "\n";
	cout << "*pScore is:" << *pScore << "\n\n";

	cout << "Assigning &str to pStr\n";
	string str = "score";
	string* pStr = &str;
	cout << "str is:" << str << "\n";
	cout << "*pStr is:" << *pStr << "\n";
	cout << "(*pStr).size() is:" << (*pStr).size() << "\n";
	cout << "pStr->size() is:" << pStr->size() << "\n";
	//传递指针
	int myScore = 150;
	int yourScore = 1000;
	cout << "\n\nOriginal values\n";
	cout << "myScore:" << myScore << "\n";
	cout << "yourScore:" << yourScore << "\n\n";

	cout << "Calling badSwap()\n";
	badSwap(myScore,yourScore);
	cout << "myScore:" << myScore << "\n";
	cout << "yourScore:" << yourScore << "\n\n";

	cout << "Calling goodSwap()\n";
	goodSwap(&myScore, &yourScore);
	cout << "myScore:" << myScore << "\n";
	cout << "yourScore:" << yourScore << "\n\n";
	//返回指针
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	//displays string object that the returned pointer points to
	cout << "Sending the object pointed to by returned pointer to cout:\n";
	cout << *(ptrToElement(&inventory, 0)) << "\n\n";

	//assigns one pointer to another -- inexpensive assignment

	cout << "Assigning the returned pointer to another pointer.\n";
	string* pStr0 = ptrToElement(&inventory,1);
	cout << "Sending the object pointed to by new pointer to cout:\n";
	cout << *pStr0 << "\n\n";

	//copies a string object -- expensive assignment
	cout << "Assigning object pointed to by pointer to a string object.\n";
	string str0 = *(ptrToElement(&inventory, 2));
	cout << "Sending the new string object to cout:\n";
	cout << str0 << "\n\n";

	//altering the string object through a returned pointer
	cout << "Altering an object through a returned pointer.\n";
	*pStr0 = "Healing Potion";
	cout << inventory[1] << endl;

	//指针与数组的关系
	cout << "Creating an array of high scores.\n\n";
	const int NUM_SCORES = 3;
	int highScores[NUM_SCORES] = { 5000, 3500, 2700 };
	cout << "Displaying scores using array name as a constant pointer.\n";
	cout << *highScores << endl;
	cout << *(highScores + 1) << endl;
	cout << *(highScores + 2) << "\n\n";
	cout << "Increasing scores by passing array as a constant pointer.\n\n";
	increase(highScores,NUM_SCORES);

	cout << "Displaying scores by passing array as a constant pointer to a constant.\n";
	display(highScores,NUM_SCORES);

	//system("pause");
	return EXIT_SUCCESS;
}

void badSwap(int x,int y){
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int* pX,int* pY){
	int temp = *pX;
	*pX = *pY;
	*pY = temp;
}

string* ptrToElement(vector<string>* const pVec,int i){
	return &((*pVec)[i]);
}

void increase(int* const array,int NUM_ELEMENTS){
	for (int i = 0; i < NUM_ELEMENTS; i++)	{
		array[i] += 500;
	}
}

void display(const int*  const array, const int NUM_ELEMENTS){
	for (int i = 0; i < NUM_ELEMENTS; i++)	{
		cout << array[i] << endl;
	}
}