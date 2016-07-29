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

string askText(string prompt);
int askNumber(string prompt);
void tellsStory(string name,string noun,int number,string bodyPart,string verb);

/**函数应用：Mad-Lib*/
int _tmain(int argc, _TCHAR* argv[]){
	cout << "";
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the following questions to help create a new stroy.\n";
	string name = askText("Please enter a name:");
	string noun = askText("Please enter a plural noun:");
	int number = askNumber("Please enter a number:");
	string bodyPart = askText("Please enter a body part:");
	string verb = askText("Please enter a verb:");
	tellsStory(name,noun,number,bodyPart,verb);
	int a=((1+20)+3);
	//system("pause");
	return EXIT_SUCCESS;
}

string askText(string prompt){
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt){
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellsStory(string name, string noun, int number, string bodyPart, string verb){
	cout << "\nHere's your story:\n";
	cout << "The famous explorer "<<name<<" had nearly given up a life-long quest to find\n";
	cout << "The Lost City of "<<noun<<" when one day,the "<< noun<<" found the explorer.\n";
	cout << "Surrounded by "<<number<<" "<<noun<<",a tear came to "<<name<<"'s"<<bodyPart<<".\n" ;
	cout << "After all this time,the quest was finally over. ";
	cout << "And then,the "<<noun<<"\n";
	cout << "promptly devoured "<<name<<". ";
	cout << "The moral of the story? Be careful what you "<<verb<<" for.";
}