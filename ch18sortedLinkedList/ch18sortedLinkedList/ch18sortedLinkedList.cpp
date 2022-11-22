// ch18sortedLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//has a class for the linked list
class LinkedList
{
private:
	//has a class for the node
	class Node
	{
	public:
		int data;
		Node* next;
		Node(int data, Node* next)
		{
			this->data = data;
			this->next = next;
		}
	};
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	//adds a node to the end of the list
	void add(int data)
	{
		Node* newNode = new Node(data, NULL);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	//adds a node to the front of the list
	void addFront(int data)
	{
		Node* newNode = new Node(data, NULL);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	//adds a node to the list in order
	void addInOrder(int data)
	{
		Node* newNode = new Node(data, NULL);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			Node* current = head;
			Node* previous = NULL;
			while (current != NULL && current->data < data)
			{
				previous = current;
				current = current->next;
			}
			if (previous == NULL)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				newNode->next = current;
				previous->next = newNode;
			}
		}
		size++;
	}
	//removes a node from the list
	void remove(int data)
	{
		if (head == NULL)
		{
			return;
		}
		else
		{
			Node* current = head;
			Node* previous = NULL;
			while (current != NULL && current->data != data)
			{
				previous = current;
				current = current->next;
			}
			if (current == NULL)
			{
				return;
			}
			else if (previous == NULL)
			{
				head = head->next;
			}
			else
			{
				previous->next = current->next;
			}
			delete current;
			size--;
		}
	}
	//prints the list
	void print()
	{
		Node* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	
	
};

int main()
{
    cout << "Ch 18 Sorted List by Kevin Bell\n\n";
	cout << "Enter an integer to add to the list, or a negative number to stop: ";
	//declare a linked list object
	LinkedList list;
	//declare a variable to hold the user's input
	double number;
	//get the user's input
	cin >> number;
	//while the user has not entered a negative number
	while (number >= 0)
	{
		cout << "Enter an integer to add to the list, or a negative number to stop: ";
		//add the number to the list
		list.addInOrder(number);
		//get the next number
		cin >> number;
	}
	//display the sorted list
	cout << endl;
	cout << "Here are the numbers in the list:\n";
	list.print();
	system("pause");
	return 0;
}