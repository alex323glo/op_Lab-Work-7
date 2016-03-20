/*//////////////////////
Лабораторная работа №2//
Выполнил Алексей Орлюк//
Группа ИП-54          //
*///////////////////////

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <string.h>


using namespace std;


const int maxn = 15,													//maximum length of symbols row
		  maxm = 100;													//maximum length of text			

char text[maxm] = "this is program\0";									// Text
char symb[maxn];														// Symbols, which we enter

int repeat(void);														// main repeat function
void input(char*);														// Symbols input function
void search(char*, char*);												// Search words in text function

int main()
{
	do
	{
		system("cls");
		input(symb);
		search(text, symb);
		system("pause");
	} 
	while (repeat());
    return 0;
}

int repeat()
{
	int choice;
	cout << "Do you want to try again? (1 if YES)";
	cin >> choice;											//input your choice (you should put "1", if you want to run main function again)
	cout << endl;
	return choice;
}

// Symbols input function
void input(char*symbols)
{
	cout << "Text:" << endl;
	cout << text << endl;									//output whole text
	strcat_s(text, " \0");									//putting " " symbol in the end of the text
	cout << "Enter symbols:" << endl;
	cin >> symbols;											//input symbols
}

// Search words in text function
void search(char* txt, char* symbols)
{
	char* pointer = txt;									//supporting pointer for pointing words
	char* help=pointer;										//supporting pointer for pointing "_" symbol
	cout << "Words:" << endl;
	while(pointer!=nullptr)									//cycle for words
	{
		for (unsigned int i = 0;i < strlen(symbols);i++)	//cycle for entered symbols
		{													//
			if (*pointer == symbols[i])						//check for symbols in the beginning of the word
			{
				help = strchr(pointer, ' ');				//pointing pointer "help" on "_" symbol address
				if (help != nullptr)
				{
					for (unsigned int j = 0;j < strlen(symbols);j++)					//cycle for entered symbols
					{																	//
						if (*(help - 1) == symbols[j])									//check for symbols in the end of the word
						{
							for (int k = 0;k < strlen(pointer) - strlen(help);k++)		//output the word
							cout << pointer[k];											//
							cout << ' ';
							break;
						}
						
					}
				}
				break;
			}
		}
		if (strchr(pointer, ' ') != nullptr)				//check for "_" symbol in the rest part of the text
			pointer = strchr(pointer, ' ') + 1;				//pointing pointer "pointer" on a new word in the rest part of the text
		else break;											//
	}
	cout << endl;
}
