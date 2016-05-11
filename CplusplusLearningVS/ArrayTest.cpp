// C++LearningVS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;
using std::string;
//using std::time;
//using std::rand;

/*Word Jumble game*/
void useWordJumble(){
	//字段行
	enum fields	{ WORD,HINT,NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS]{
		{"wall","Do you feel you're banging your head egainst something."},
		{ "glasses", "These might help you see the answer." },
		{ "labored", "Going slowly,is it?" },
		{ "persistent", "Keep at it." },
		{ "jumble", "It's what the game is all about." },
	};
	//随机选择单词
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	//单词乱序
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; i++) {
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
	//欢迎界面
	cout << "\t\tWelcome to Word Jumble!\n\n"; 
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game..\n\n";
	cout << "The jumble is: " << jumble;
	string guess;
	cout << "\n\nYour guess:";
	cin >> guess;
	//进入游戏主循环
	while ((guess != theWord)&&(guess != "quit"))	{
		if (guess == "hint"){
			cout << theHint;
		}else{
			cout << "Sorry,that's not it.";
		}
		cout << "\n\nYour guess:";
		cin >> guess;
	}
	//游戏结束
	if (guess == theWord){
		cout << "\nThat's it!You guessed it!\n";
	}
	cout << "\nThanks for playing.\n";	
}

/*使用多维数组*/
void useMultidimensionalArray(){
	const int ROWS = 3;
	const int COLUMNS = 3;
	//创建多维数组
	char board[ROWS][COLUMNS] = { { 'O', 'X', 'O' },
								  { ' ', 'X', 'X' },
								  { 'X', 'O', 'O' } };
	//多维数组的索引
	cout << "\n\nHere's the tic-tac-toe baord:\n";
	for (int i = 0; i < ROWS; i++)	{
		for (int j = 0; j < COLUMNS; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	
	cout << "\n'X' moves to the empty location.\n\n";
	board[1][0] = 'X';
	cout << "Noew the tic-tac-toe baord is:\n";
	for (int i = 0; i < ROWS; i++)	{
		for (int j = 0; j < COLUMNS; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}	
	cout << "\n'X' wins!";	
}

/*基础数组*/
void useBaseArray(){
	//创建数组
	const int MAX_ITEMS = 10;
	string inventory[MAX_ITEMS];
	//数组的索引
	int numItems = 0;
	inventory[numItems++] = "sword";
	inventory[numItems++] = "armor";
	inventory[numItems++] = "shield";
	cout << "Your items:\n";
	for (int i = 0; i < numItems; i++)	{
		cout << inventory[i] << endl;
	}
	cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	cout << "\nYour items:\n";

	for (int i = 0; i < numItems; i++)	{
		cout << inventory[i] << endl;
	}
	//使用数组元素的成员函数
	cout << "\nThe item name '" << inventory[0] << "' has ";
	cout << inventory[0].size() << " letters in it.\n";
	cout << "\nYou find a healing potion.";
	//数组边界
	if (numItems<MAX_ITEMS)	{
		inventory[numItems++] = "healing potion";
	}
	else {
		cout << "You has too many items and can't carry another.";
	}
	cout << "Your items:\n";
	for (int i = 0; i < numItems; i++)	{
		cout << inventory[i] << endl;
	}
}

/*理解C风格字符串*/
void understandCStyleString(){
	string word1 = "Game";
	char word2[] = "Over";
	string phrase = word1+" "+word2;
	if (word1 != word2)	{
		cout << "word1 and word2 are not equal.";
	}
	if (phrase.find(word2) == string::npos)	{
		cout << "word2 is contained in phrase.\n";
	}
}

//PS:在调用useMultidimensionalArray之前，要先声明useMultidimensionalArray。声明的方式是 将useMultidimensionalArray提前至main()之前。
/**使用数组*/
int _tmain(int argc, _TCHAR* argv[]){	
	useBaseArray();
	useMultidimensionalArray();
	useWordJumble();
	//system("pause");yon g
	return EXIT_SUCCESS;
}