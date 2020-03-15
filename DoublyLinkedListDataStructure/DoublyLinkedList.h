#pragma once
#include<iostream>
#include "Node.h"

template <class T> class DoublyLinkedList
{
	private:
		Node<T> * head;
		int length;

	public:
		
		DoublyLinkedList();

		//Insert a item in the list, by default items are added to the beginning of the list
		void insert(T data, bool atEnd = false);
		
		//Print list
		void print();

};

template<class T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	length = 0;
	head = nullptr;
}

template<class T>
inline void DoublyLinkedList<T>::insert(T x, bool atEnd)
{

	Node<T>* temp1 = new Node<T>; //> New node to add to list
	temp1->data = x; //> set the data of the new node

	//Special case if the list is empty
	if (length == 0)
	{
		head = temp1; //> head points to new node
		temp1->next = nullptr; //> nullptr indicates the end of the list 
		temp1->prev = nullptr; //> nullptr indicates the beginning of the list
		length++; //> Increase the count of the elements
		return;
	}

	if (atEnd) //> If true, insert element at the end of the list
	{
		Node<T>* temp2 = head; 

		//Traverse to the element at the end of the list
		for(int i = 0; i < (length - 1) ; i++)
			temp2 = temp2->next;

		//Fix Links
		temp1->next = nullptr; //> new node points to the nullptr, which indicates the last element
		temp1->prev = temp2; //> new node points to the node that was last in the list previously,

		temp2->next = temp1; //> The node that was previously last in the list, now points to the new node

	}
	else //> Else insert the element at the beginning of the list
	{
		//Fix the links of the previously first element in the list
		Node<T>* temp2 = head; //> The first element
		temp2->prev = temp1; //> the previous first element now points to the new node, as the node before it

		//Set the new node's
		temp1->next = temp2; //> the new node now points to the previously first element as the next element
		temp1->prev = nullptr; //> the new node now points to nullptr, indicating it is the first element in the list

		//Fix head's link
		head = temp1;

	}
	length++;

}

template<class T>
inline void DoublyLinkedList<T>::print()
{
	Node<T>* temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}

	std::cout << std::endl;
}
