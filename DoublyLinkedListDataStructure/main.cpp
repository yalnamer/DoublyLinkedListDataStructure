#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList<int> list;

	list.insert(15);
	list.print();

	list.insert(14);
	list.print();

	list.insert(2314);
	list.print();

	list.insert(13,true);
	list.print();


	list.insert(414);
	list.print();

	list.insert(1322, true);
	list.print();
}