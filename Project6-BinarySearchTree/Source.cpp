/*
* Ian Flecther
* CST-201
* 11/8/2021
* This is my own code with help from the slides in class, Professor Sarlo, and W3school.com
*/


#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

int main()
{
	//creates word and userInput strings to keep track of words
	string word;
	string userInput;
	//create int wordCount int to keep track of the number of words in the file
	int wordCount = 0;
	//creates BST object called tree
	BST tree;
	//opens text file
	ifstream input("Text.txt");
	//runs while there are words to be input into the file
	while (getline(input, word))
	{
		//inputs the input into word
		input >> word;
		//inserts the word into the tree
		tree.newInsert(word);
		//adds 1 to word count
		wordCount++;
	}
	//prints out the word count
	cout << "Words: " << wordCount << endl;
	//displays all of the elements in the tree starting with head
	tree.display(tree.head);
	cout << "" << endl;
	cout << "" << endl;
	//runs while userInput isn't equal to 1
	while (userInput != "-1")
	{
		//prompts the user to enter a value to search for or -1 to exit
		cout << "Enter string, enter -1 to quit: ";
		cin >> userInput;
		cout << "" << endl;
		//checks if the value is in the tree
		if(tree.search(userInput))
		{
			//prints out that the input was found after a certain amount of searches
			cout << "'" << userInput << "' was found after " <<
				tree.getCounter() - 1 << " searches." << endl;
		}
		//if the value isn't found and the user input isn't -1, prints out that the value
		//wasn't found
		else
		{
			if (userInput != "-1")
			{
				cout << "'" << userInput << "' was not found." << endl;
			}
		}
	}
	userInput = " ";
	//runs while the userInput doesn't equal -1
	while (userInput != "-1")
	{
		//prompts the user to enter a string to remove or -1 to quit
		cout << "Enter string to remove or -1 to quit: ";
		cin >> userInput;
		cout << " " << endl;
		//checks if the userInput isn't -1 and if so deletes the item and displays the new tree
		if (userInput != "-1")
		{
			tree.deleteItem(userInput);
			tree.display(tree.head);
		}
	}
	//closes the file
	input.close();
}