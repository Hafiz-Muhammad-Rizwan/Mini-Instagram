#pragma once
#ifndef myvector_h
#define myvector_h
#include <iostream>
using namespace std;
template<typename T>
class MyVector
{
public:
	T* Array;
	int Capacity;
	int Size;
	MyVector()
	{
		Capacity = 1;
		Size = 0;
		Array = new T[Capacity];
	}
	void PushBack(T Value)
	{
		if (Size >= Capacity)
		{
			Capacity =Capacity* 2;
			T* Temp = new T[Capacity];
			for (int i = 0; i < Size; i++)
			{
				Temp[i] = Array[i];
			}
			delete[] Array;
			Array = Temp;
		}
		Array[Size] = Value;
		Size++;
	}
	void PopBack()
	{
		
		if (Size == 0)
		{
			cout << "Vector is Empty" << endl;
			return;
		}
		Size--;
	}
	T peek()
	{
		if (Size <= 0)
		{
			return T();
		}
		return Array[Size - 1];
	}
	bool search(T Value)
	{
		for (int i = 0; i < Size; i++)
		{
			if (Array[i] == Value)
			{
				return true;
			}
		}
		return false;
	}
	T& operator[]( int index)
	{
		try 
		{
			if (index < 0 || index >= Size)
			{
				throw "Index Out of Bound";
			}
			return Array[index];
		}
		catch (...)
		{
			cout << "Excess Wrong Index" << endl;
		}
	}
	int size()
	{
		return Size;
	}
};

#endif // !myvector_h
