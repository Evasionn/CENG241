#pragma once
#include <iostream>
using namespace std;
template<class T>
class List
{
private:
	T * arr;
	int arraySize;
	int numOfItem;
public:
	List();
	~List();
	List(List &);
	bool isEmpty();
	bool isFull();
	void insert(T);
	void sortArray();
	void listArray();
	void operator <<(T);
	bool operator==(List);
	void operator=(List);
	
};

template <class T>
List<T>::List()
{
	arraySize = 50;
	numOfItem = 0;
	arr = new T[arraySize];
}

template <class T>
List<T>::~List()
{
	delete[] arr;
}

template <class T>
bool List<T>::isEmpty()
{
	return numOfItem == 0 ? true : false;
}

template <class T>
bool List<T>::isFull()
{
	return numOfItem == arraySize ? true : false;
}
template <class T>
void List<T>::insert(T data)
{
	if (isFull())
	{
		T * newArr = new T[arraySize + 5];
		for (int i = 0; i < arraySize; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		arraySize += 10;
	}
	arr[numOfItem] = data;
	numOfItem++;
}

template <class T>
void List<T>::listArray()
{
	for (int i = 0; i < numOfItem; i++)
	{
		cout << arr[i] << endl;
	}
}

template <class T>
List<T>::List(List &b)
{
	arraySize = b.arraySize;
	numOfItem = b.numOfItem;
	arr = new T[arraySize];
	for (int i = 0; i < numOfItem; i++)
	{
		arr[i] = b.arr[i];
	}
}

template <class T>
void List<T>::sortArray()
{
	for (int i = 0; i < numOfItem; i++)
	{
		for (int j = 0; j < numOfItem; j++)
		{
			if (arr[i] < arr[j])swap(arr[i], arr[j]);
		}
	}
}

template <class T>
void List<T>::operator<<(T data)
{
	insert(data);
}

template <class T>
bool List<T>::operator==(List data)
{
	if (arraySize != data.arraySize || numOfItem != data.numOfItem) return false;
	for (int i = 0; i < numOfItem; i++)
	{
		if (arr[i] != data.arr[i]) return false;
	}
	return true;
}

template <class T>
void List<T>::operator=(List data)
{
	arraySize = data.arraySize;
	numOfItem = data.numOfItem;
	arr = new T[arraySize];
	for (int i = 0; i < numOfItem; i++)
	{
		arr[i] = data.arr[i];
	}
}