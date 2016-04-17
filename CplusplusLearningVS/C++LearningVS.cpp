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

//returns a reference to a string
string& refToElement(vector<string>& inventory, int i);

void badSwap(int x, int y);
void goodSwap(int& x, int& y);

//parameter vec is a constant reference to a vector of strings
void display(const vector<string>& inventory);

/**引用*/
int _tmain(int argc, _TCHAR* argv[]){
	//使用引用
	int myScore = 1000;
	int& mikesScore = myScore;  // create a reference

	cout << "myScore is: " << myScore << "\n";
	cout << "mikesScore is: " << mikesScore << "\n\n";

	cout << "Adding 500 to myScore\n";
	myScore += 500;
	cout << "myScore is: " << myScore << "\n";
	cout << "mikesScore is: " << mikesScore << "\n\n";

	cout << "Adding 500 to mikesScore\n";
	mikesScore += 500;
	cout << "myScore is: " << myScore << "\n";
	cout << "mikesScore is: " << mikesScore << "\n\n";

	//返回引用
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	//displays string that the returned reference refers to 
	cout << "Sending the returned reference to cout:\n";
	cout << refToElement(inventory, 0) << "\n\n";

	//assigns one reference to another -- inexpensive assignment 
	cout << "Assigning the returned reference to another reference.\n";
	string& rStr = refToElement(inventory, 1);
	cout << "Sending the new reference to cout:\n";
	cout << rStr << "\n\n";

	//copies a string object -- expensive assignment
	cout << "Assigning the returned reference to a string object.\n";
	string str = refToElement(inventory, 2);
	cout << "Sending the new string object to cout:\n";
	cout << str << "\n\n";

	//altering the string object through a returned reference
	cout << "Altering an object through a returned reference.\n";
	rStr = "Healing Potion";
	cout << "Sending the altered object to cout:\n";
	cout << inventory[1] << endl;

	//通过传递引用改变实参
	int yourScore = 1000;
	cout << "Original values\n";
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n\n";

	cout << "Calling badSwap()\n";
	badSwap(myScore, yourScore);
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n\n";

	cout << "Calling goodSwap()\n";
	goodSwap(myScore, yourScore);
	cout << "myScore: " << myScore << "\n";
	cout << "yourScore: " << yourScore << "\n";
	//传递引用以提高效率
	display(inventory);

	//system("pause");
	return EXIT_SUCCESS;
}

//returns a reference to a string
string& refToElement(vector<string>& vec, int i){
	return vec[i];
}

void badSwap(int x, int y){
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}

//parameter vec is a constant reference to a vector of strings
void display(const vector<string>& vec){
	cout << "Your items:\n";
	for (vector<string>::const_iterator iter = vec.begin();
		iter != vec.end(); ++iter)	{
		cout << *iter << endl;
	}
}
