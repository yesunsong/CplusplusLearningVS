// C++LearningVS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>

//#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::time;

/*使用迭代器*/
void useHeroInventory3(){	
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	//PS:
	//使用push_back可能使引用向量的所有迭代器无效
	//使用insert会使所有引用了插入点之后的元素的迭代器失效，因为所有插入点之后的元素都下移了一位
	//使用erase会使所有引用了插入点之后的元素的迭代器失效，因为所有插入点之后的元素都上移了一位

	//迭代器的声明
	//迭代器
	vector<string>::iterator myIterator;
	//常量迭代器
	vector<string>::const_iterator iter;

	//循环访问变量
	//向量inventory不包含字符串字面值"sword",而是包含string对象
	//使用begin、end成员函数
	//end返回容器中最后一个元素之后的一个迭代器
	cout << "Your items:\n";
	for (iter = inventory.begin(); iter != inventory.end();iter++)	{
		cout << *iter << endl;
	}

	//修改向量元素的值
	cout << "\nYou trade your sword for a battle axe.";
	myIterator = inventory.begin();	
	*myIterator = "battle axe";
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)	{
		cout << *iter<<endl;
	}

	//访问向量元素的成员函数
	//一般而言使用->运算符访问迭代器引用对象的成员函数或数据成员
	cout << "\nThe item name '" << *myIterator << "' has ";
	cout << (*myIterator).size() << " letters in it.\n";
	cout << "\nThe item name '" << *myIterator << "' has ";
	cout << myIterator->size() << " letters in it.\n";

	//使用insert成员函数
	cout << "\nYou recover a crossbow from a slain enemy.";
	inventory.insert(inventory.begin(), "crossbow");
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)	{
		cout << *iter << endl;
	}
	//使用erase成员函数
	cout << "\nYour armor is destoryed in a fierce battle.";
	inventory.erase(inventory.begin() + 2);
	cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); iter++)	{
		cout << *iter << endl;
	}
}

void useHeroInventory2(){
	//向量的声明
	vector<string> inventory;
	//使用push_back成员函数
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");
	//使用size成员函数
	cout << "You have "<<inventory.size()<<" items.\n";
	//向量的索引
	cout << "Your items:\n";
	for (unsigned int i = 0; i < inventory.size(); i++)	{
		cout << inventory[i] << endl;
	}
	cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	cout << "\nYour items:\n";
	for (unsigned int i = 0; i < inventory.size(); i++)	{
		cout << inventory[i] << endl;
	}
	//调用元素的成员函数
	cout << "\nThe item name '" << inventory[0] << "' has ";
	cout << inventory[0].size() << " letters in it.\n";
	//调用pop_back成员函数
	cout << "\nYour shiled is destoryed in a fierce battle.";
	inventory.pop_back();
	cout << "\nYour items:\n";
	for (unsigned int i = 0; i < inventory.size(); i++)	{
		cout << inventory[i] << endl;
	}
	//调用clear成员函数
	cout << "You are robbed of all of your possessions by a thief.";
	inventory.clear();
	//调用empty成员函数
	if (inventory.empty()) {
		cout << "\nYou have nothing.\n";
	}else{
		cout << "\nYou have at latest one item.\n";
	}
}

/*使用算法*/
void useAlgorithm(){
	vector<int>::const_iterator iter;
	cout << "Creating a list of scores.";
	vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);
	cout << "\nHigh Scores:\n";
	for (iter =scores.begin();iter !=scores.end(); iter++)	{
		cout << *iter << endl;
	}

	//使用find算法
	//STL的find算法在指定范围内的容器的元素中查找值，它返回引用第一个匹配元素的一个迭代器。如果没有找到匹配的元素，则返回的 迭代器指向指定范围的结尾处。
	cout << "\nFinding a score.";
	int score;
	cout << "\nEnter a score to find:";
	cin >> score;
	iter = find(scores.begin(), scores.end(),score);
	if (iter != scores.end())	{
		cout << "Score found.\n";
	} else {
		cout << "Score not found.\n";
	}

	//使用random_shuffle算法
	//random_shuffle算法将序列中的元素进行乱序。该算法需要序列的起点迭代器和终点迭代器来进行乱序操作
	cout << "\nRandomizing scores.";
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(scores.begin(),scores.end());
	cout << "\nHigh Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); iter++)	{
		cout << *iter << endl;
	}

	//使用sort算法：对序列中的元素进行升序排序。该算法需要序列的起点迭代器和终点迭代器来进行排序操作
	cout << "\nSorting scores.";
	sort(scores.begin(),scores.end());
	cout << "\nHigh Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); iter++)	{
		cout << *iter << endl;
	}

	//只要容器满足特定要求就可以使用STL算法
	//对字符串进行乱序操作
	string word = "high score";
	random_shuffle(word.begin(),word.end());
}

void useHangman(){
	const int MAX_WRONG = 8;
	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(),words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(),'-');
	string used = "";
	cout << "Welcome to Hangman.Good luck.\n";

	while ((wrong<MAX_WRONG)&&(soFar!=THE_WORD))	{
		cout << "\nYou have "<<(MAX_WRONG-wrong);
		cout << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters:\n"<<used<<endl;
		cout << "\nSo far,the word is:\n"<<soFar<<endl;

		char guess;
		cout << "\n\nEnter your guess:";
		cin >> guess;
		guess = toupper(guess);
		while (used.find(guess)!=string::npos)		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "\n\nEnter your guess:";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess)!=string::npos)	{
			cout << "That's right!" << guess << " is in the word.\n";
			for (unsigned int i = 0; i < THE_WORD.size(); i++)			{
				if (THE_WORD[i]==guess)	{
					soFar[i] = guess;
				}
			}
		}else{
			cout << "Sorry," << guess << " isn't in the word.\n";
			wrong++;
		}
	}
	if (wrong==MAX_WRONG){
		cout << "\nYou've been hanged!";

	}else{
		cout << "\nYou guessed it!";
	}
	cout << "\nThe word was " << THE_WORD << endl;
}

/**使用向量*/
int _tmain(int argc, _TCHAR* argv[]){	
	//useHeroInventory2();
	//useHeroInventory3();
	//useAlgorithm();
	useHangman();
	//system("pause");yon g
	return EXIT_SUCCESS;
}