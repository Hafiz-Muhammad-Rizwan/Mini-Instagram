#pragma once
#ifndef mystack_h
#define mystack_h
#include <iostream>
#include"node.h"
using namespace std;


template<typename T>
class MyStack 
{
public:
	Node<T>* Top;
	MyStack()
	{
		Top = NULL;
	}
	void push(T x)
	{
		Node<T>* temp = new Node<T>(x);
		temp->Next = Top;
		Top = temp;
	}
	void pop()
	{
		if (Top == NULL)
		{
			cout << "Stack is empty" << endl;
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
			cout << "Stack is Empty" << endl;
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
	void display()
	{
		Node<T>* temp = Top;
		while (temp != NULL)
		{
			cout << temp->Data << " ";
			temp = temp->Next;
		}
		cout << endl;
	}

};
#endif // !mystack_h
