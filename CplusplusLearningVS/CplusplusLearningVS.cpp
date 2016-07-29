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
	cout << "Original values\n";


	//system("pause");
	return EXIT_SUCCESS;
}

