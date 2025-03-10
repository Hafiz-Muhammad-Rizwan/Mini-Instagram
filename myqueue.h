#pragma once
#ifndef myqueue_h
#define myqueue_h
#include <iostream>
#include"node.h"
using namespace std;

template<typename T>
class MyQueue
{
public:
	Node<T>* Top;
	MyQueue()
	{
		Top == NULL;
	}
	void push(T Data)
	{
		Node<T>* new_Node = new Node<T>(Data);
		if (Top == NULL)
		{
			Top = new_Node;
			return;
		}
		Node<T>* Temp = Top;
		while (Temp->Next != NULL)
		{
			Temp = Temp->Next;
		}
		Temp->Next = new_Node;
		new_Node->Next = NULL;
	}
	void pop()
	{
		if (Top == NULL)
		{
			cout << "Queue is Empty" << endl;
			return;
		}
		Node<T>* temp = Top;
		Top = Top->Next;
		delete temp;
	}
	T peek()
	{
		if (Top == NULL)
		{
			cout << "Queue is Empty" << endl;
			return NULL;
		}
		return Top->Data;
	}
	bool search(T Value)
	{
		Node* Temp = Top;
		while (Temp != NULL)
		{
			if (Temp->Data == Value)
			{
				return true;
			}
		}
		return false;
	}
	bool isEmpty()
	{
		if (Top == NULL)
		{
			return true;
		}
		return false;
	}
	int size()
	{
		int count = 0;
		Node<T>* Temp = Top;
		while (Temp != NULL)
		{
			count++;
			Temp = Temp->Next;
		}
		return count;
	}
};
#endif // !myqueue_h
