#pragma once

template <class T>
struct Node
{
	T data;
	Node<T>* prev;
	Node<T>* next;

};