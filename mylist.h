#pragma once
#ifndef mylist_h
#define mylist_h
#include<iostream>
#include"node.h"
using namespace std;

template <typename T>
class MyList
{
public:
	Node<T>* Head;
	Node<T>* Tail;
	int Size = 0;
	MyList()
	{
		Head = NULL;
		Tail = NULL;
	}
	void pushfront(T Data)
	{
		Node<T>* new_Node = new Node<T>(Data);
		if (Head == NULL)
		{
			Head = Tail = new_Node;
			return;
		}
		new_Node->Next = Head;
		Head->Prev = new_Node;
		Head = new_Node;
		Size++;
	}
	void pushBack(T Data)
	{
		Node<T>* new_Node = new Node<T>(Data);
		if (Tail == NULL)
		{
			Head = Tail = new_Node;
			return;
		}
		Tail->Next = new_Node;
		new_Node->Prev = Tail;
		Tail = new_Node;
		Size++;
	}
	void popFront()
	{
		if (Head == NULL)
		{
			cout << "List is Empty" << endl;
			return;
		}
		Node<T>* Temp = Head;
		Head = Head->Next;
		delete Temp;
		Temp = NULL;
		Size--;
	}
	void popBack()
	{
		if (Tail == NULL)
		{
			cout << "List is Empty" << endl;
			return;
		}
		Node<T>* Temp = Tail;
		Tail = Tail->Prev;
		delete Temp;
		Temp = NULL;
		Size--;
	}
	T peekFront()
	{
		if (Head != NULL)
		{
			return Head->Data;
		}
	}
	T peekBack()
	{
		if (Head != NULL)
		{
			return Tail->Data;
		}
	}
	int size()
	{
		return Size;
	}
};
#endif // !Mylist_h
