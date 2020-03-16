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

		//Insert a item at the nth position
		void insert(T data, int position);

		//remove and element from the list
		void remove(int position);
		
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

template <class T>
inline void DoublyLinkedList<T>::insert(T x, int position)
{

	//Make sure that the position is within range
	if (position < 0 || position > length  )
	{
		std::cout << "ERROR: Out Of Range\n";
		return;
	}

	
	Node<T>* temp1 = new Node<T>; //>Create a new Node 
	temp1->data = x; //>Assign data to new node

	//If there is no element in the list
	if (length == 0)
	{
		temp1->next = nullptr; //> Indicates the end of the list
		temp1->prev = nullptr; //> Indicates the beginning of the list
		head = temp1; //> head now points to this element, meaning it is the first element
		length++;
		return;
	}


	 
	if (position == 0) //> If we want to insert in the beginning, another function completes this perfectly
	{
		insert(x);
		return;
	}
	else if (position == length )//> If we want to insert at the end, another function completes this perfectly
	{
		insert(x, true);
		return;
	}


	Node<T>* temp2 = head; //> A temp variable to traverse

	//Traverse to the element before the element at the current position that is desired
	for (int i = 0; i < (position - 1); i++)
		temp2 = temp2->next;

	
	//Now  adjust the next link for the new node
	temp1->next = temp2->next; //> New node points to the old element in the position for next
	temp1->prev = temp2; //>New node points to the element which will be before it, for prev

	//Fix the link of the element of before new node
	temp2->next = temp1;

	temp2 = temp1->next; //> traverse to the link after new node 

	//Fix the link of the previous element in the position
	temp2->prev = temp1;

	length++;
	
}

template<class T>
inline void DoublyLinkedList<T>::remove(int position)
{

	//If the list is empty
	if (length == 0)
	{
		std::cout << "[!]ERROR: Empty List\n";
		return;
	}

	//If the position is out of range
	if (position < 0 || position >(length - 1))
	{
		std::cout << "[!]ERROR: Out of Range\n";
		return;
	}


	Node<T>* temp = head; //> point to the first element

	//Traverse to the element which will be remvoed
	for (int i = 0; i < position; i++)
		temp = temp->next;

	//Fix the link of the previous element
	//If there is a element before the current element
	//Set the previous element's next element to the element next to the current element
	if (temp->prev != nullptr)
		temp->prev->next = temp->next; 
	else //else this the first element, and need to redirect the head to the new first element
		head = temp->next; //head points to the element next to the current element
	
	//If the next element is not null, then adjust the 
	//next elements previous link to the link before the current element
	if(temp->next != nullptr)
		temp->next->prev = temp->prev;

	delete(temp); //free the memory of the old element
	length--;



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
