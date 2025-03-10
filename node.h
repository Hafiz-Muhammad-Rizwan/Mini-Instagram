#pragma once
#ifndef node_h
#define node_h
#include <iostream>
using namespace std;
template<typename T>
class Node
{
public:
	T Data;
	Node* Next;
	Node(T Data)
	{
		this->Data = Data;
		Next = NULL;
	}
};
#endif // !node_h
