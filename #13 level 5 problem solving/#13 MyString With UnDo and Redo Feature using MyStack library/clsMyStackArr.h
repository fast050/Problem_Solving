#pragma once
#include "clsDynamicArray.h"

template <class T>
class clsMyStackArr : public clsDynamicArray<T>
{

public:
	void push(T value) {
		clsDynamicArray<T>::InsertAtBeginning(value);
	}

	void pop() {
		clsDynamicArray<T>::DeleteFirstItem();
	}

	int Size() {
		return clsDynamicArray<T>::Size();
	}

	T Top() {
		return clsDynamicArray<T>::GetItem(0);
	}

	T Bottom() {
		return clsDynamicArray<T>::GetItem(Size() - 1);
	}

	void UpdateItem(int index, T value) {
		clsDynamicArray<T>::SetItem(index, value);
	}

	bool InsertAtFront(T value) {
	   return clsDynamicArray<T>::InsertAtBeginning(value);
	}

	bool InsertAtBack(T value) {
		return clsDynamicArray<T>::InsertAtEnd(value);
	}

	void Print() {
		clsDynamicArray<T>::PrintList();
	}


};
