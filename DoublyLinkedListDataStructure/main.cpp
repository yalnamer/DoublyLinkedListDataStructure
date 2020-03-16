#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList<int> list;

	list.remove(20);

	list.insert(15);
	list.print();

	list.insert(14);
	list.print();

	list.insert(2314);
	list.print();

	list.insert(13,true);
	list.print();

	list.insert(24);
	list.print();


	list.remove(2);
	list.print();

	list.remove(0);
	list.print();

	list.remove(200);
	list.print();

	list.remove(2);
	list.print();

}