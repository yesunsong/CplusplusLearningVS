// C++LearningVS.cpp : �������̨Ӧ�ó������ڵ㡣
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

// ��������function prototype (declaration)
void instructions();
//ʹ���βκͷ���ֵ
char askYesNo1();
char askYesNo2(string question);

void func();
//ʹ��ȫ�ֱ���
int glob = 10;  // global variable
void access_global();
void hide_global();
void change_global();
//ʹ��Ĭ�ϲ���
int askNumber(int high, int low = 1);
//��������
int triple(int number);
string triple(string text);
//ʹ����������
int radiation(int health);

/**����*/
int _tmain(int argc, _TCHAR* argv[]){
	//��������
	instructions();

	//ʹ���βκͷ���ֵ
	char answer1 = askYesNo1();
	cout << "Thanks for answering: " << answer1 << "\n\n";

	char answer2 = askYesNo2("Do you wish to save your game?");

	//ʹ��������
	cout << "Thanks for answering: " << answer2 << "\n";
	int var = 5;  // local variable in main()
	cout << "In main() var is: " << var << "\n\n";

	func();

	cout << "Back in main() var is: " << var << "\n\n";
	{
		cout << "In main() in a new scope var is: " << var << "\n\n";

		cout << "Creating new var in new scope.\n";
		int var = 10;  // variable in new scope, hides other variable named var
		cout << "In main() in a new scope var is: " << var << "\n\n";
	}

	cout << "At end of main() var created in new scope no longer exists.\n";
	cout << "At end of main() var is: " << var << "\n";
	//ʹ��ȫ�ֱ���
	cout << "In main() glob is: " << glob << "\n\n";
	access_global();

	hide_global();
	cout << "In main() glob is: " << glob << "\n\n";

	change_global();
	cout << "In main() glob is: " << glob << "\n\n";

	//ʹ��Ĭ�ϲ���
	int number = askNumber(5);
	cout << "Thanks for entering: " << number << "\n\n";

	number = askNumber(10, 5);
	cout << "Thanks for entering: " << number << "\n\n";

	//��������
	cout << "Tripling 5: " << triple(5) << "\n\n";
	cout << "Tripling 'gamer': " << triple("gamer");
	//ʹ����������
	int health = 80;
	cout << "Your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	cout << "After radiation exposure your health is " << health << "\n\n";
	//system("pause");
	return EXIT_SUCCESS;
}

//��������function definition
void instructions(){
	cout << "Welcome to the most fun you've ever had with text!\n\n";
	cout << "Here's how to play the game...\n";
}

char askYesNo1(){
	char response1;
	do	{
		cout << "Please enter 'y' or 'n': ";
		cin >> response1;
	} while (response1 != 'y' && response1 != 'n');

	return response1;
}

char askYesNo2(string question){
	char response2;
	do	{
		cout << question << " (y/n): ";
		cin >> response2;
	} while (response2 != 'y' && response2 != 'n');

	return response2;
}

void func(){
	int var = -5;  // local variable in func()
	cout << "In func() var is: " << var << "\n\n";
}

void access_global(){
	cout << "In access_global() glob is: " << glob << "\n\n";
}

void hide_global(){
	int glob = 0;  // hide global variable glob
	cout << "In hide_global() glob is: " << glob << "\n\n";
}

void change_global(){
	glob = -10;  // change global variable glob
	cout << "In change_global() glob is: " << glob << "\n\n";
}

int askNumber(int high, int low){
	int num;
	do	{
		cout << "Please enter a number" << " (" << low << " - " << high << "): ";
		cin >> num;
	} while (num > high || num < low);

	return num;
}



int triple(int number){
	return (number * 3);
}

string triple(string text){
	return (text + text + text);
}

inline int radiation(int health){
	return (health / 2);
}