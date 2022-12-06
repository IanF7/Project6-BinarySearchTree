#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BST
{
private:
	int counter;
public:

	//default constructor
	class BST()
	{
		counter = 0;
	}

	//parameterized constructor
	class BST(int counter)
	{
		this->counter = counter;
	}

	//creates struct node and values for data, right, and left
	struct node
	{
		string data;
		struct node* left;
		struct node* right;
	};
	//creates head node and sets it to NULL
	struct node* head = NULL;

	//newInsert method that takes in a string and set head equal to the result
	//of insert given head and the string [O(1)]
	void newInsert(string data)
	{
		head = insert(head, data);
	}

	//getter for counter
	int getCounter()
	{
		return counter;
	}

	//setter for counter
	void setCounter(int counter)
	{
		this->counter = counter;
	}

	//insert method that takes in a node and and data and returns a node [O(n)]
	struct node* insert(struct node* node, string data)
	{
		//checks if the node is null
		if (node == NULL)
		{
			//creates a new node called node 
			struct node* node = new(struct node);
			//sets node's data equal to the input
			node->data = data;
			//sets left and right to NULL
			node->left = NULL;
			node->right = NULL;
			//returns the node
			return node;
		}
		else
		{
			//checks if data is less than node->data and if so sends it to the left
			if (data < node->data)
			{
				node->left = insert(node->left, data);
			}
			//checks if data is greater than node->data and if so sends it to the right
			else if(data > node->data)
			{
				node->right = insert(node->right, data);
			}
			//otherwise prints out that the value already exists
			else
			{
				cout << "This value already exists" << endl;
			}
			//returns the node
			return node;
		}
	}

	//display method that takes in a node [O(n)]
	void display(node* temp)
	{
		//returns if temp if NULL
		if (temp == NULL)
		{
			return;
		}
		else
		{
			//prints out all the values in temp using left, print, right (in order)
			display(temp->left);
			cout << temp->data << " ";
			display(temp->right);
		}
	}
	
	//search method that takes in a string and returns a bool [O(1)]
	bool search(string data)
	{
		//sets counter equal to 0
		counter = 0;
		//creates a node called root and sets it equal to the results of
		//searchRecursive given head and the input
		node* root = searchRecursive(head, data);
		//if root is NULL returns true
		if (root != NULL)
		{
			return true;
		}
		//otherwise returns false
		else
		{
			return false;
		}
	}

	//searchRecursive helper method that takes in a node and a string and returns a node [O(n)]
	node* searchRecursive(node* root, string data)
	{
		//checks if root is NULL or the data equals the data at root
		if (root == NULL || root->data == data)
		{
			//updates counter by 1
			setCounter(counter + 1);
			//returns root
			return root;
		}
		//checks if data is greater than the data at root
		if (data > root->data)
		{
			//updates counter by 1
			setCounter(counter + 1);
			//returns the value of searchRecursive given root->right and data
			return searchRecursive(root->right, data);
		}
		//updates counter
		setCounter(counter + 1);
		//returns the value of searchRecursive given root->left and data
		return searchRecursive(root->left, data);
	}

	//minValue helper method that takes in a node and returns a node [O(n)]
	node* minValue(node* head)
	{
		//creates a node min and sets it equal to the data at head
		node* min = head;
		//runs while min and min->left aren't null
		while (min != NULL && min->left != NULL)
		{
			//sets min equal to min->left to increment
			min = min->left;
		}
		//returns min
		return min;
	}

	//deleteItem method that takes in a string [O(1)]
	void deleteItem(string data)
	{
		//sets head equal to the value gotten from deleteItemRecusive using head and data
		head = deleteItemRecursive(head, data);
	}

	//deleteItemRecursive helper method that takes in a node and a string [O(n)]
	node* deleteItemRecursive(node* head, string data)
	{
		//checks if the value is in the string and if not returns head and prints that
		//no data was found
		if (search(data))
		{
			//checks if head is null, if so returns head
			if (head == NULL)
			{
				return head;
			}
			//checks if data is less than the data at head and if so sets head->left
			//equal to the value from deleteItemRecursive given head->left and data
			if (data < head->data)
			{
				head->left = deleteItemRecursive(head->left, data);
			}
			//checks if data is greater than the data at head and if so sets head->right
			//equal to the value from deleteItemRecursive given head->right and data
			else if (data > head->data)
			{
				head->right = deleteItemRecursive(head->right, data);
			}
			else
			{
				//checks if head->left is null
				if (head->left == NULL)
				{
					//creates node temp and sets it equal to head->right
					struct node* temp = head->right;
					//deletes head
					delete head;
					//returns temp
					return temp;
				}
				//checks if head->right is null
				else if (head->right == NULL)
				{
					//creates node temp and sets it equal to head->left
					struct node* temp = head->left;
					//deletes head
					delete head;
					//returns temp
					return temp;
				}
				//creates node temp and sets it equal to the minValue of the head->right path
				struct node* temp = minValue(head->right);
				//sets the data of head equal to the data of temp
				head->data = temp->data;
				//sets head->right equal to the value from deleteItemRecursive given 
				//head->right and the data of temp
				head->right = deleteItemRecursive(head->right, temp->data);
				//returns temp
			}
			//returns head
			return head;
		}
		else
		{
			cout << "data not found." << endl;
			return head;
		}
	}
};
#endif
