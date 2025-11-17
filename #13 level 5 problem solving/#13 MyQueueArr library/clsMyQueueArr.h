#pragma once
#include "clsDynamicArray.h"

template<class T>
class clsMyQueueArr
{

protected:
	clsDynamicArray<T> _MyList;

public:
	void push(T value) {
		_MyList.InsertAtEnd(value);
	}

	void Print() {
		_MyList.PrintList();
	}

	void pop() {
		_MyList.DeleteFirstItem();
	}

	int Size() {
		return _MyList.Size();
	}

	bool IsEmpty() {
		return _MyList.IsEmpty();
	}

	T front() {
		return _MyList.GetItem(0);
	}

	T back() {
		return _MyList.GetItem(Size() - 1);
	}

	void Reverse() {
		_MyList.Reverse();
	}

	void Clear() {
		_MyList.Clear();
	}

	T GetItem(int index) {
		return _MyList.GetItem(index);
	} 

	bool InsertAfter(int index, T value) {
	   return _MyList.InsertAfter(index, value);
	}

	bool InsertAtFront(T value) {
		return _MyList.InsertAtBeginning(value);
	}

	bool InsertAtBack(T value) {
		return _MyList.InsertAtEnd(value);
	}

	bool UpdateItem(int index, T value) {
		return _MyList.SetItem(index, value);
	}

};

